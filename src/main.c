/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:57:53 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/04 18:00:34 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->number);
		stack = stack->next;
	}
}
int	main(int argc, char **argv)
{
// Declare pointers to two data structures / linked lists, one for stack 'a' and another for 'b'
	// Set both pointers to NULL to avoid undefined behavior and indicate we're starting with empty stacks
	
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	stack_a = init_stack(argc, argv);
	if (!stack_a)
		return (lstclear(&stack_a), ft_printf("Error\n"));
	if (is_sorted(&stack_a))
		return (0);
	if (count_nodes(stack_a) == 2)
		sa(stack_a);
	if (count_nodes(stack_a) == 3)
		sort_three(&stack_a);
	if (count_nodes(stack_a) == 4)
		sort_four(&stack_a, &stack_b);
	if (count_nodes(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
/* 	ft_printf("stack_a =\n");
	print_stack(stack_a);
	ft_printf("stack_b =\n");
	print_stack(stack_b); */
	return (0);
}

// Initialize stack 'a' by appending each input number as a node to stack 'a'
	// Handle integer overflow, duplicates, and syntax errors, e.g. input must only contain digits or '-' '+' signs
		// If errors found, free stack 'a' and return error
	// Check for each input, if it is a long integer
		// If the input is a string, convert it to a long integer
	// Append the nodes to stack 'a'

// Check if stack 'a' is sorted
	// If not sorted, implement our sorting algorithm
		// Check for 2 numbers
			// If so, simply swap the numbers
		// Check for 3 numbers
			// If som implement our simple 'sort three' algorithm
		// Check if the stack has more than 3 numbers
			// If so, implement our Turk algorithm