/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:05:44 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/03 11:06:15 by cecompte         ###   ########.fr       */
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

char	**ps_split(char *str);
int		ps_atoi(const char *nptr);
t_node	*init_stack(int argc, char **argv);
int		is_sorted(t_node *head);

//list_utils
t_node	*lstnew(int number);
void	lstadd_back(t_node **lst, t_node *new);
void	lstadd_front(t_node **lst, t_node *new);
t_node	*lstlast(t_node *lst);
void	lstclear(t_node **lst);

//operations
void	sa(t_node *stack_a);
void	sb(t_node *stack_a);
void	ss(t_node *stack_a, t_node *stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

#endif