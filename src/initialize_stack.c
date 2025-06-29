/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:49:36 by cecompte          #+#    #+#             */
/*   Updated: 2025/06/29 20:08:06 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_valid_nb(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_node	*initialize_stack(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*element;
	int		i;
	int		number;
	
	if (argc == 2)
		i = 0;
	else
		i = 1;
	if (check_valid_nb(argv[i]))
	{
		number = ft_atoi(argv[i]);
		stack_a = lstnew(number);
		if (!stack_a)
			return (NULL);
	}
	while (argv[++i])
	{
		if (check_valid_nb(argv[i]))
		{
			number = ft_atoi(argv[i]);
			// if no duplicate
			element = lstnew(number);
			if (!element)
				return (NULL);
			lstadd_back(&stack_a, element); 
		}
		else
			return (NULL);
	}
	return (stack_a);
}