/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:08:55 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/03 17:26:55 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a)
{
	if (find_max(stack_a) == 1)
		ra(stack_a);
	else if (find_max(stack_a) == 2)
		rra(stack_a);
	if (!is_sorted(stack_a))
		sa(*stack_a);
}
int	find_target(int number, t_node *stack)
{
	int		position;
	int		target;
	int		closest_max;

	position = 1;
	while (number > stack->number && stack->next)
	{
		stack = stack->next;
		position++;
	}
	if (!stack->next)
		return (1); // non ! position du minimum !
	closest_max = stack->number;
	target = position;
	while (stack->next)
	{
		stack = stack->next;
		position++;
		if (number < stack->number && closest_max > stack->number)
		{
			closest_max = stack->number;
			target = position;
		}
	}
	return (target);
}

void	put_target_top(int position, t_node **stack)
{
	if (position > count_nodes(*stack) / 2)
	{
		while (position != count_nodes(*stack))
		{
			rra(stack);
			position++;
		}
		rra(stack);
	}
	else
	{
		while (position != 1)
		{
			ra(stack);
			position--;
		}
	}
}

void	sort_five(t_node **stack_a, t_node	**stack_b)
{	
	int	min;
	int	target;

	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	ft_printf("sort stack_a :\n");
	sort_three(stack_a);
	print_stack(*stack_a);
	target = find_target((*stack_b)->number, *stack_a);
	ft_printf("target = %d\n", target);
	ft_printf("put target on top:\n");
	put_target_top(target, stack_a);
	print_stack(*stack_a);
	pa(stack_a, stack_b);
	print_stack(*stack_a);
	target = find_target((*stack_b)->number, *stack_a);
	ft_printf("target = %d\n", target);
	ft_printf("put target on top:\n");
	put_target_top(target, stack_a);
	print_stack(*stack_a);
	pa(stack_a, stack_b);
	print_stack(*stack_a);
	if (is_sorted(stack_a))
		return;
	if (find_max(stack_a) == 1)
		min = count_nodes(*stack_a);
	else
		min = find_max(stack_a) + 1;
	ft_printf("min = %d\n", min);
	ft_printf("put min on top:\n");
	put_target_top(min, stack_a);
	print_stack(*stack_a);
}
