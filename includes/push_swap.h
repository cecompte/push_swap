/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:05:44 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/22 13:10:39 by cecompte         ###   ########.fr       */
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
int		check_valid_nb(char *str);
t_node	*init_stack(int argc, char **argv);
void	print_stack(t_node *stack);

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

//algo_utils
int		is_sorted(t_node **stack);
int		count_nodes(t_node	*stack);
int		position_max(t_node	**stack);
int		position_min(t_node **stack);
t_node	*find_node(int position, t_node **stack);

//find_targets
int		find_target_max(int number, t_node **stack);
int		find_target_min(int number, t_node **stack);
void	put_target_top(int position, t_node **stack);

//count_operations
int		count_rotate(int position, t_node **stack);
int		count_rev_rotate(int position, t_node **stack);
int		count_rr(int position_a, int position_b, t_node **stack_a, t_node **stack_b);
int		count_rrr(int position_a, int position_b, t_node **stack_a, t_node **stack_b);
int		push_cost(int position_a, int position_b, t_node **stack_a, t_node **stack_b);

//algo
void	sort_three(t_node **stack_a);
void	sort_four(t_node **stack_a, t_node	**stack_b);
void	sort_five(t_node **stack_a, t_node	**stack_b);
void	turk_algo(t_node **stack_a, t_node **stack_b);

#endif