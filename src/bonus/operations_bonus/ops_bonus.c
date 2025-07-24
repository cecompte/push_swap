/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:01:25 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/24 14:17:38 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

t_node	*lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	push(t_node **dest, t_node **source)
{
	t_node	*to_push;
	t_node	*tmp;

	if (!source || !(*source))
		return ;
	tmp = (*source)->next;
	to_push = *source;
	to_push->next = *dest;
	*dest = to_push;
	*source = tmp;
}

void	rrotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*head;
	t_node	*tail;

	if (!(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	tmp = head;
	while (tmp->next->next)
		tmp = tmp->next;
	tail = lstlast(*stack);
	tail->next = head;
	tmp->next = NULL;
	*stack = tail;
}

void	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*head;

	if (!(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	tmp = lstlast(*stack);
	tmp->next = head;
	tmp = tmp->next;
	head = head->next;
	tmp->next = NULL;
	*stack = head;
}

void	swap(t_node *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = tmp;
}
