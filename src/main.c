/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:57:53 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/22 16:36:42 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->number);
		stack = stack->next;
	}
}*/
int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	if (argc == 2 && check_valid_nb(argv[1]))
		return (0);
	stack_a = NULL;
	stack_a = init_stack(&stack_a, argc, argv);
	if (is_sorted(&stack_a))
		return (lstclear(&stack_a), 0);
	if (count_nodes(stack_a) == 2)
		sa(stack_a);
	if (count_nodes(stack_a) == 3)
		sort_three(&stack_a);
	if (count_nodes(stack_a) == 4)
		sort_four(&stack_a, &stack_b);
	if (count_nodes(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
	if (count_nodes(stack_a) > 5)
		turk_algo(&stack_a, &stack_b);
	lstclear(&stack_a);
	lstclear(&stack_b);
	return (0);
}
