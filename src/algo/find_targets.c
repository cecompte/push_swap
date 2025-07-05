/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_targets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:47:09 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/05 17:37:09 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_max(int number, t_node **stack)
{
	t_node	*current;
	int		position;
	int		target;
	int		closest_max;

	position = 1;
	current = *stack;
	closest_max = find_node(position_max(stack), stack)->number;
	if (closest_max < number)
		return (position_min(stack));
	target = position;
	while (current)
	{
		if (number < current->number && closest_max >= current->number)
		{
			closest_max = current->number;
			target = position;
		}
		current = current->next;
		position++;
	}
	return (target);
}
int	find_target_min(int number, t_node **stack)
{
	t_node	*current;
	int		position;
	int		target;
	int		closest_min;

	position = 1;
	current = *stack;
	closest_min = find_node(position_min(stack), stack)->number;
	if (closest_min > number)
		return (position_max(stack));
	target = position;
	while (current)
	{
		if (number > current->number && closest_min <= current->number)
		{
			closest_min = current->number;
			target = position;
		}
		current = current->next;
		position++;
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

int	push_cost(int position_a, int position_b, t_node **stack_a, t_node **stack_b)
{
	int		push_cost_a;
	int		push_cost_b;
	int		push_cost;

	if (position_b > count_nodes(*stack_b) / 2)
		push_cost_b = count_nodes(*stack_b) - position_b + 1;
	else
		push_cost_b = position_b - 1;
	if (position_a > count_nodes(*stack_a) / 2)
		push_cost_a = count_nodes(*stack_a) - position_a + 1;
	else
		push_cost_a = position_a - 1;
	if ((position_a > count_nodes(*stack_a) / 2 && position_b > count_nodes(*stack_b) / 2) ||
			(position_a <= count_nodes(*stack_a) / 2 &&  position_b <= count_nodes(*stack_b) / 2))
		{
			if (push_cost_a > push_cost_b)
				push_cost = push_cost_a;
			else
				push_cost = push_cost_b;
		}
	else
		push_cost = push_cost_a + push_cost_b;
	return (push_cost);
}
