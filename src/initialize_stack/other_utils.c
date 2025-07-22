/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:25:43 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/22 11:45:13 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ps_split(char *str)
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

int	ps_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 1;
	result = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		if (neg == -1 && (result > INT_MAX / 10
				|| (result == INT_MAX / 10 && nptr[i] - '0' > 7)))
			return (INT_MIN);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * neg);
}