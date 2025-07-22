/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:49:36 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/22 13:25:28 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	no_duplicates(int num, t_node **head)
{
	t_node	*tmp;
	
	tmp = *head;
	while (tmp)
	{
		if (tmp->number == num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static t_node	*create_stack(int i, char **argv)
{
	t_node	*head;
	int		number;
	
	if (check_valid_nb(argv[i]))
	{
		number = ps_atoi(argv[i]);
		head = lstnew(number);
		if (!head)
			return (NULL);
	}
	else
		return (ft_printf("Not valid number\n"), NULL);
	return (head);
}
static t_node	*fill_stack(int i, char **argv)
{
	t_node	*head;
	t_node	*current;
	int		number;
	
	head = create_stack(i, argv);
	if (!head)
		return (NULL);
	i++;
	while (argv[i])
	{
		if (check_valid_nb(argv[i]))
		{
			number = ps_atoi(argv[i++]);
			if (!no_duplicates(number, &head))
				return (ft_printf("Duplicates\n"), NULL);
			current = lstnew(number);
			if (!current)
				return (NULL);
			lstadd_back(&head, current);
		}
		else
			return (ft_printf("Not valid number\n"), NULL);
	}
	return (head);
}
t_node	*init_stack(int argc, char **argv)
{
	t_node	*stack_a;
	char	**tmp;
	int		i;
	
	if (!argv[1])
		return (NULL);
	if (argc == 2)
	{
		tmp = ps_split(argv[1]);
		if (!tmp)
			return (NULL);
		stack_a = fill_stack(0, tmp);
		i = 0;
		while (tmp[i])
			free(tmp[i++]);
		free(tmp);
	}
	else
		stack_a = fill_stack(1, argv);
	return (stack_a);
}
