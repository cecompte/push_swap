/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:27:45 by cecompte          #+#    #+#             */
/*   Updated: 2025/06/29 19:56:35 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

char	**split(char *str)
{
	int		i;
	char	**tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
			return (NULL);
		i++;
	}
	tmp = ft_split(str, ' ');
	
	return (tmp);
}

t_node	*lstnew(int number)
{
	t_node	*element;

	element = malloc(sizeof(t_node));
	if (!element)
		return (NULL);
	element->number = number;
	element->next = NULL;
	return (element);
}

void	lstadd_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (!*lst)
	{
		lstadd_front(lst, new);
		return ;
	}
	tmp = lstlast(*lst);
	tmp->next = new;
}

void	lstadd_front(t_node **lst, t_node *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_node	*lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}