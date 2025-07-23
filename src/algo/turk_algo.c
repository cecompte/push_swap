/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:25:56 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/23 12:11:20 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cheapest_push(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	int		pos_a;
	int		pos_b;
	int		cheapest_node;
	int		min_cost;

	pos_a = 1;
	cheapest_node = 1;
	current = *stack_a;
	pos_b = target_min(current->number, stack_b);
	min_cost = push_cost(pos_a, pos_b, stack_a, stack_b);
	if (!min_cost)
		return (1);
	while (current)
	{
		pos_b = target_min(current->number, stack_b);
		if (push_cost(pos_a, pos_b, stack_a, stack_b) < min_cost)
		{
			min_cost = push_cost(pos_a, pos_b, stack_a, stack_b);
			cheapest_node = pos_a;
		}
		pos_a++;
		current = current->next;
	}
	return (cheapest_node);
}

static void	push_node(int pos_a, int pos_b, t_node **stack_a, t_node **stack_b)
{
	t_operations	nb;

	nb.ra = 0;
	nb.rb = 0;
	nb.rra = 0;
	nb.rrb = 0;
	nb.rr = 0;
	nb.rrr = 0;
	while (nb.ra++ < count_rotate(pos_a, stack_a)
		- count_rr(pos_a, pos_b, stack_a, stack_b))
		ra(stack_a);
	while (nb.rb++ < count_rotate(pos_b, stack_b)
		- count_rr(pos_a, pos_b, stack_a, stack_b))
		rb(stack_b);
	while (nb.rra++ < count_rrotate(pos_a, stack_a)
		- count_rrr(pos_a, pos_b, stack_a, stack_b))
		rra(stack_a);
	while (nb.rrb++ < count_rrotate(pos_b, stack_b)
		- count_rrr(pos_a, pos_b, stack_a, stack_b))
		rrb(stack_b);
	while (nb.rr++ < count_rr(pos_a, pos_b, stack_a, stack_b))
		rr(stack_a, stack_b);
	while (nb.rrr++ < count_rrr(pos_a, pos_b, stack_a, stack_b))
		rrr(stack_a, stack_b);
}

void	turk_algo(t_node **stack_a, t_node **stack_b)
{
	int		target_b;
	int		cheapest_position;
	int		cheapest_number;
	int		target_a;

	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	while (count_nodes(*stack_a) > 3)
	{
		cheapest_position = cheapest_push(stack_a, stack_b);
		cheapest_number = find_node(cheapest_position, stack_a)->number;
		target_b = target_min(cheapest_number, stack_b);
		push_node(cheapest_position, target_b, stack_a, stack_b);
		pb(stack_b, stack_a);
	}
	sort_three(stack_a);
	while (count_nodes(*stack_b) > 0)
	{
		target_a = target_max((*stack_b)->number, stack_a);
		put_target_top(target_a, stack_a);
		pa(stack_a, stack_b);
	}
	put_target_top(position_min(stack_a), stack_a);
}
