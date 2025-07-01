/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:25:43 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/01 14:26:42 by cecompte         ###   ########.fr       */
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