/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:41:03 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/04 16:49:42 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node *stack)
{
	int	tmp;

	if(stack->next == NULL)
		return;
	tmp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = tmp;
}

void	sa(t_node *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}
void	sb(t_node *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}
void	ss(t_node *stack_a, t_node *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}