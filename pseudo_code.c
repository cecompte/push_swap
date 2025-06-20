/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:57:53 by cecompte          #+#    #+#             */
/*   Updated: 2025/06/20 16:51:58 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
// Declare pointers to two data structures / linked lists, one for stack 'a' and another for 'b'
	// Set both pointers to NULL to avoid undefined behavior and indicate we're starting with empty stacks
	
	node	*stack_a;
	node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
// Handle input count errors. Argument count must be 2 or more, and the second input must not be empty
	// If input errors, return error
	if (argc != 2 || argv[1] == "")
		return(ft_printf("Error\n"));

// Handle both cases of input, whether a variable number of command line arguments, or as a string
	// If the input of numbers is as a string, call "split()" to split the substrings (beware leaks !!)
	
}

// Handle both cases of input, whether a variable number of command line arguments, or as a string
	// If the input of numbers is as a string, call "split()" to split the substrings (beware leaks !!)

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