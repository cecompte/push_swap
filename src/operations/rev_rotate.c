/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:00:13 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/02 17:51:35 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*head;
	t_node	*tail;

	if (!(*stack)->next)
		return;
	head = *stack;
	tmp = head;
	while (tmp->next->next)
		tmp = tmp->next; // finds the second-to-last
	tail = lstlast(*stack);
	tail->next = head;
	tmp->next = NULL;
	*stack = tail;
}

void	rra(t_node **stack_a)
{
	rrotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	rrotate(stack_b);
	ft_printf("rrb\n");
}
void	rrr(t_node **stack_a, t_node **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_printf("rrr\n");
}
	
