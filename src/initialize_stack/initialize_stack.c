/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:49:36 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/01 17:26:34 by cecompte         ###   ########.fr       */
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

static int	no_duplicates(int num, t_node *stack_a)
{
	t_node	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->number == num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
/*
t_node	*create_stack(int argc, char **argv, t_node **stack_a)
{
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
		element = lstnew(number);
		if (!stack_a)
			return (NULL);
	}
	else
		return (ft_printf("Not valid number\n"), NULL);\
	return (stack_a);
}
*/
t_node	*fill_stack(int argc, char **argv)
{
	t_node	*head;
	t_node	*current;
	int		i;
	int		number;
	
	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		if (check_valid_nb(argv[i]))
		{
			number = ft_atoi(argv[i++]);
			if (!no_duplicates(number, head))
				return (ft_printf("Duplicates\n"), NULL);
			current = lstnew(number);
			if (!current)
				return (NULL);
			if (!head)
				head = current;
			lstadd_back(&head, current);
		}
		else
			return (ft_printf("Not valid number\n"), NULL);
	}
	return (head);
}
