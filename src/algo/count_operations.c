/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:04:48 by user              #+#    #+#             */
/*   Updated: 2025/07/23 12:05:14 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rotate(int position, t_node **stack)
{
	int	count;

	if (position - 1 < count_nodes(*stack) - position + 1)
		count = position - 1;
	else
		count = 0;
	return (count);
}

int	count_rrotate(int position, t_node **stack)
{
	int	count;

	if (position - 1 >= count_nodes(*stack) - position + 1)
		count = count_nodes(*stack) - position + 1;
	else
		count = 0;
	return (count);
}

int	count_rr(int pos_a, int pos_b, t_node **stack_a, t_node **stack_b)
{
	int	ra;
	int	rb;
	int	rr;

	ra = count_rotate(pos_a, stack_a);
	rb = count_rotate(pos_b, stack_b);
	if (ra > rb)
		rr = rb;
	else
		rr = ra;
	return (rr);
}

int	count_rrr(int pos_a, int pos_b, t_node **stack_a, t_node **stack_b)
{
	int	rra;
	int	rrb;
	int	rrr;

	rra = count_rrotate(pos_a, stack_a);
	rrb = count_rrotate(pos_b, stack_b);
	if (rra > rrb)
		rrr = rrb;
	else
		rrr = rra;
	return (rrr);
}

int	push_cost(int pos_a, int pos_b, t_node **stack_a, t_node **stack_b)
{
	int	rotate;
	int	rrotate;
	int	cost;

	rotate = count_rotate(pos_a, stack_a) + count_rotate(pos_b, stack_b)
		- count_rr(pos_a, pos_b, stack_a, stack_b);
	rrotate = count_rrotate(pos_a, stack_a) + count_rrotate(pos_b, stack_b)
		- count_rrr(pos_a, pos_b, stack_a, stack_b);
	cost = rotate + rrotate;
	return (cost);
}
