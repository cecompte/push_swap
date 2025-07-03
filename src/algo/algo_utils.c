/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:17:34 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/03 20:41:32 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **stack)
{
	t_node	*current;
	
	current = *stack;
	while (current->next)
	{
		if (current->number < current->next->number)
			current = current->next;
		else
			return (0);
	}
	return (1);
}

int	count_nodes(t_node	*stack)
{
	t_node	*tmp;
	int		count;

	tmp = stack;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
int	find_max(t_node	**stack)
{
	t_node	*current;
	int		position;
	int		i;
	int		maximum;

	current = *stack;
	maximum = current->number;
	i = 1;
	position = 1;
	while (current->next)
	{
		i++;
		if (maximum < current->next->number)
		{
			maximum = current->next->number;
			position = i;
		}
		current = current->next;
	}
	return (position);
}
int	find_min(t_node **stack)
{
	t_node	*current;
	int		position;
	int		i;
	int		minimum;

	current = *stack;
	minimum = current->number;
	i = 1;
	position = 1;
	while (current->next)
	{
		i++;
		if (minimum > current->next->number)
		{
			minimum = current->next->number;
			position = i;
		}
		current = current->next;
	}
	return (position);
}