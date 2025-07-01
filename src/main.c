/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:57:53 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/01 17:26:19 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
// Declare pointers to two data structures / linked lists, one for stack 'a' and another for 'b'
	// Set both pointers to NULL to avoid undefined behavior and indicate we're starting with empty stacks
	
	t_node	*stack_a;
	char	**tmp;

	stack_a = NULL;
// Handle input count errors. Argument count must be 2 or more, and the second input must not be empty
	// If input errors, return error
	if (argc < 2)
		return(0);
	if (!argv[1])
		return(0);

// Handle both cases of input, whether a variable number of command line arguments, or as a string
	// If the input of numbers is as a string, call "split()" to split the substrings (beware leaks !!)
	if (argc == 2)
	{
		tmp = split(argv[1]);
		if (!tmp)
			return(ft_printf("Error\n"));
		
		stack_a = fill_stack(argc, tmp);
		free (tmp);
	}
	else
		stack_a = fill_stack(argc, argv);
	if (!stack_a)
		lstclear(stack_a); // + Error message
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->number);
		stack_a = stack_a->next;
	}
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