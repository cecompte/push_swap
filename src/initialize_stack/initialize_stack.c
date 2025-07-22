/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:11:05 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/22 16:46:31 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_duplicates(int num, t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	if (!tmp)
		return (1);
	while (tmp)
	{
		if (tmp->number == num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_valid_nb(char *str)
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

static t_node	*create_node(int number, t_node *next)
{
	t_node	*element;

	element = malloc(sizeof(t_node));
	if (!element)
		return (NULL);
	element->number = number;
	element->next = next;
	return (element);
}

static int	add_node(char *str, t_node **stack)
{
	int	number;

	if (!check_valid_nb(str))
		return (0);
	number = ps_atoi(str);
	if (!no_duplicates(number, stack))
		return (0);
	*stack = create_node(number, *stack);
	if (!*stack)
		return (0);
	return (1);
}

t_node	*init_stack(t_node **stack, int argc, char **argv)
{
	int		index;
	int		i;
	char	**tmp;

	index = argc - 1;
	while (index > 0)
	{
		if (argc == 2)
		{
			tmp = ps_split(argv[index]);
			if (!tmp)
				return (exit_error(stack), NULL);
			i = ps_strlen(tmp) - 1;
			while (i >= 0)
			{
				if (!add_node(tmp[i--], stack))
					return (free_tab(tmp), exit_error(stack), NULL);
			}
			free_tab(tmp);
		}
		else
			if (!add_node(argv[index--], stack))
				return (exit_error(stack), NULL);
	}
	return (*stack);
}
