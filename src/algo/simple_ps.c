/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:08:55 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/04 18:00:03 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_three(t_node **stack_a)
{
	if (position_max(stack_a) == 1)
		ra(stack_a);
	else if (position_max(stack_a) == 2)
		rra(stack_a);
	if (!is_sorted(stack_a))
		sa(*stack_a);
}
int	find_target(int number, t_node **stack)
{
	t_node	*current;
	int		position;
	int		target;
	int		closest_max;

	position = 1;
	current = *stack;
	closest_max = nb_max(stack);
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
void	sort_four(t_node **stack_a, t_node	**stack_b)
{
	int	target;
	
	pb(stack_b, stack_a);
	sort_three(stack_a);
	target = find_target((*stack_b)->number, stack_a);
	put_target_top(target, stack_a);
	pa(stack_a, stack_b);
	put_target_top(position_min(stack_a), stack_a);
}
void	sort_five(t_node **stack_a, t_node	**stack_b)
{	
	int	target;

	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	if (is_sorted(stack_b))
		sb(*stack_b);
	sort_three(stack_a);
	target = find_target((*stack_b)->number, stack_a);
	put_target_top(target, stack_a);
	pa(stack_a, stack_b);
	target = find_target((*stack_b)->number, stack_a);
	put_target_top(target, stack_a);
	pa(stack_a, stack_b);
	put_target_top(position_min(stack_a), stack_a);
}
