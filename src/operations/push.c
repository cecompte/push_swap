/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:01:25 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/02 16:42:48 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_node **dest, t_node **source)
{	
	t_node	*new;
	t_node	*tmp_head;
	
	if (!source)
		return (0);
	new = lstnew((*source)->number);
	if (!new)
		return (-1);
	lstadd_front(dest, new);
	tmp_head = *source;
	*source = (*source)->next;
	free (tmp_head);
	return (1);
}

int pb(t_node **stack_b, t_node **stack_a)
{
	int	ret;
	
	ret = push(stack_b, stack_a);
	if (ret == 1)
		ft_printf("pb\n");
	return (ret);
}
int pa(t_node **stack_a, t_node **stack_b)
{
	int	ret;
	
	ret = push(stack_a, stack_b);
	if (ret == 1)
		ft_printf("pa\n");
	return (ret);
}
