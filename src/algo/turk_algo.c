/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:25:56 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/05 17:34:45 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_algo(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	int		source_position;
	int		target_position;
	
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	ft_printf("stack_a =\n");
	print_stack(*stack_a);
	ft_printf("stack_b =\n");
	print_stack(*stack_b);
	current = *stack_a;
	source_position = 1;
	while (current)
	{
		target_position = find_target_min(current->number, stack_b);
		ft_printf("target number of %d is %d, and push cost is %d\n", current->number, find_node(target_position, stack_b)->number, push_cost(source_position, target_position, stack_a, stack_b));
		source_position++;
		current = current->next;
	}
}