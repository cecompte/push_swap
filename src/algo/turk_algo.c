/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:25:56 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/05 17:34:45 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cheapest_push(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	int		position_a;
	int		position_b;
	int		cheapest_node;
	int		min_cost;

	current = *stack_a;
	position_a = 1;
	cheapest_node = 1;
	min_cost = push_cost_total(position_a, find_target_min(current->number, stack_b), stack_a, stack_b);
	if (!min_cost)
		return (1);
	while (current)
	{
		position_b =  find_target_min(current->number, stack_b);
		if (push_cost_total(position_a, position_b, stack_a, stack_b) < min_cost)
		{
			min_cost = push_cost_total(position_a, position_b, stack_a, stack_b);
			cheapest_node = position_a;
		}
		position_a++;
		current = current->next;
	}
	return (cheapest_node);
}

static int	count_rotate(int position, t_node **stack)
{
	int	count;

	if (position - 1 < count_nodes(*stack) - position + 1)
		count = position - 1;
	else
		count = 0;
	return (count);
}
static int	count_rev_rotate(int position, t_node **stack)
{
	int	count;

	if (position - 1 >= count_nodes(*stack) - position + 1)
		count = count_nodes(*stack) - position + 1;
	else
		count = 0;
	return (count);
}

static int	count_rr(int position_a, int position_b, t_node **stack_a, t_node **stack_b)
{
	int	ra;
	int	rb;
	int	rr;

	ra = count_rotate(position_a, stack_a);
	rb = count_rotate(position_b, stack_b);
	if (ra && rb)
	{
		if (ra > rb)
			rr = ra - rb;
		else
			rr = rb - ra;
	}
	else
		rr = 0;
	return (rr);
}

static int	count_rrr(int position_a, int position_b, t_node **stack_a, t_node **stack_b)
{
	int	rra;
	int	rrb;
	int	rrr;

	rra = count_rev_rotate(position_a, stack_a);
	rrb = count_rev_rotate(position_b, stack_b);
	if (rra && rrb)
	{
		if (rra > rrb)
			rrr = rra - rrb;
		else
			rrr = rrb - rra;
	}
	else
		rrr = 0;
	return (rrr);
}
static void	push_node(int position_a, int position_b, t_node **stack_a, t_node **stack_b)
{
	int	nb_ra;
	int	nb_rb;
	int	nb_rra;
	int	nb_rrb;
	int	nb_rr;
	int	nb_rrr;

	nb_ra = 0;
	nb_rb = 0;
	nb_rra = 0;
	nb_rrb = 0;
	nb_rr = 0;
	nb_rrr = 0;
	while (nb_ra++ < count_rotate(position_a, stack_a) - count_rr(position_a, position_b, stack_a, stack_b))
		ra(stack_a);
	while (nb_rb++ < count_rotate(position_b, stack_b) - count_rr(position_a, position_b, stack_a, stack_b))
		rb(stack_b);
	while (nb_rra++ < count_rev_rotate(position_a, stack_a) - count_rrr(position_a, position_b, stack_a, stack_b))
		rra(stack_a);
	while (nb_rrb++ < count_rev_rotate(position_b, stack_b) - count_rrr(position_a, position_b, stack_a, stack_b))
		rrb(stack_b);
	while (nb_rr++ < count_rr(position_a, position_b, stack_a, stack_b))
		rr(stack_a, stack_b);
	while (nb_rrr++ < count_rrr(position_a, position_b, stack_a, stack_b))
		rrr(stack_a, stack_b);
}

void	turk_algo(t_node **stack_a, t_node **stack_b)
{
	int		target_b;
	int		cheapest_position;
	int		target_a;
	
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	ft_printf("stack_a =\n");
	print_stack(*stack_a);
	ft_printf("stack_b =\n");
	print_stack(*stack_b);
	while (count_nodes(*stack_a) > 3)
	{
		cheapest_position = cheapest_push(stack_a, stack_b);
		target_b = find_target_min(find_node(cheapest_position, stack_a)->number, stack_b);
		push_node(cheapest_position, target_b, stack_a, stack_b);
		pb(stack_b, stack_a);
		ft_printf("stack_a =\n");
		print_stack(*stack_a);
		ft_printf("stack_b =\n");
		print_stack(*stack_b);
	}
	sort_three(stack_a);
	ft_printf("stack_a =\n");
	print_stack(*stack_a);
	ft_printf("stack_b =\n");
	print_stack(*stack_b);
	while (count_nodes(*stack_b) > 0)
	{
		target_a = find_target_max((*stack_b)->number, stack_a);
		put_target_top(target_a, stack_a);
		pa(stack_a, stack_b);
		ft_printf("stack_a =\n");
		print_stack(*stack_a);
		ft_printf("stack_b =\n");
		print_stack(*stack_b);
	}
	put_target_top(position_min(stack_a), stack_a);
	ft_printf("stack_a =\n");
	print_stack(*stack_a);
	ft_printf("stack_b =\n");
	print_stack(*stack_b);
}