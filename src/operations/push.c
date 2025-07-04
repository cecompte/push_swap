/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:01:25 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/04 16:47:02 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	push(t_node **dest, t_node **source)
{
	t_node	*to_push;
	t_node	*tmp;

	if (!source)
		return;
	tmp = (*source)->next;
	to_push = *source;
	to_push->next = *dest;
	*dest = to_push;
	*source = tmp;
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}
