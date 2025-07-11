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

