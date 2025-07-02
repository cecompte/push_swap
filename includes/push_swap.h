/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:05:44 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/02 11:35:52 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"

typedef struct s_node
{
	int				number;
	struct s_node	*next;
}	t_node;

char	**split(char *str);
t_node	*fill_stack(int argc, char **argv);
t_node	*lstnew(int number);
void	lstadd_back(t_node **lst, t_node *new);
void	lstadd_front(t_node **lst, t_node *new);
t_node	*lstlast(t_node *lst);
void	lstclear(t_node **lst);

#endif