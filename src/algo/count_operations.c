/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:04:48 by user              #+#    #+#             */
/*   Updated: 2025/07/23 12:18:19 by cecompte         ###   ########.fr       */
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
	t_operations	nb;
	int				cost;

	nb.rr = count_rr(pos_a, pos_b, stack_a, stack_b);
	nb.rrr = count_rrr(pos_a, pos_b, stack_a, stack_b);
	nb.ra = count_rotate(pos_a, stack_a) - nb.rr;
	nb.rb = count_rotate(pos_b, stack_b) - nb.rr;
	nb.rra = count_rrotate(pos_a, stack_a) - nb.rrr;
	nb.rrb = count_rrotate(pos_b, stack_b) - nb.rrr;
	cost = nb.ra + nb.rb + nb.rr + nb.rra + nb.rrb + nb.rrr;
	return (cost);
}
