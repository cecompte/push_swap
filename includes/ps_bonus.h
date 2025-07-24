/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:38:41 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/24 14:47:05 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_BONUS_H
# define PS_BONUS_H

# include "push_swap.h"

void	exit_error_bonus(t_list **list, t_node **stack_a, t_node **stack_b);
void	push(t_node **dest, t_node **source);
void	rrotate(t_node **stack);
void	rotate(t_node **stack);
void	swap(t_node *stack);
void	double_rrotate(t_node **stack_a, t_node **stack_b);
void	double_rotate(t_node **stack_a, t_node **stack_b);
void	double_swap(t_node **stack_a, t_node **stack_b);
int		is_sorted(t_node **stack);

#endif