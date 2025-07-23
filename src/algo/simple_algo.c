/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:08:55 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/23 11:39:39 by cecompte         ###   ########.fr       */
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

void	sort_four(t_node **stack_a, t_node	**stack_b)
{
	int	target;

	pb(stack_b, stack_a);
	sort_three(stack_a);
	target = target_max((*stack_b)->number, stack_a);
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
	target = target_max((*stack_b)->number, stack_a);
	put_target_top(target, stack_a);
	pa(stack_a, stack_b);
	target = target_max((*stack_b)->number, stack_a);
	put_target_top(target, stack_a);
	pa(stack_a, stack_b);
	put_target_top(position_min(stack_a), stack_a);
}
