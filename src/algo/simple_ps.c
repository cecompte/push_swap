/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:08:55 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/04 17:01:53 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_three(t_node **stack_a)
{
	if (position_max(stack_a) == 1)
		ra(stack_a);
	else if (position_max(stack_a) == 2)
		rra(stack_a);
	if (!is_sorted(stack_a))
		sa(*stack_a);
}
int	find_target(int number, t_node **stack)
{
	t_node	*current;
	int		position;
	int		target;
	int		closest_max;

	position = 1;
	current = *stack;
	closest_max = nb_max(stack);
	if (closest_max < number)
		return (position_min(stack));
	target = position;
	while (current)
	{
		if (number < current->number && closest_max >= current->number)
		{
			closest_max = current->number;
			target = position;
		}
		current = current->next;
		position++;
	}
	return (target);
}

void	put_target_top(int position, t_node **stack)
{
	if (position > count_nodes(*stack) / 2)
	{
		while (position != count_nodes(*stack))
		{
			rra(stack);
			position++;
		}
		rra(stack);
	}
	else
	{
		while (position != 1)
		{
			ra(stack);
			position--;
		}
	}
}

void	sort_five(t_node **stack_a, t_node	**stack_b)
{	
	int	min;
	int	target;

	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
/* 	ft_printf("sort stack_a :\n"); */
	sort_three(stack_a);
/* 	print_stack(*stack_a);
	ft_printf("stack_b :\n");
	print_stack(*stack_b); */
	target = find_target((*stack_b)->number, stack_a);
/* 	ft_printf("target = %d\n", target);
	ft_printf("put target on top:\n"); */
	put_target_top(target, stack_a);
/* 	print_stack(*stack_a); */
	pa(stack_a, stack_b);
/* 	print_stack(*stack_a); */
	target = find_target((*stack_b)->number, stack_a);
/* 	ft_printf("target = %d\n", target);
	ft_printf("put target on top:\n"); */
	put_target_top(target, stack_a);
/* 	print_stack(*stack_a); */
	pa(stack_a, stack_b);
/* 	print_stack(*stack_a); */
	if (is_sorted(stack_a))
		return;
	min = position_min(stack_a);
/* 	ft_printf("min = %d\n", min);
	ft_printf("put min on top:\n"); */
	put_target_top(min, stack_a);
/* 	print_stack(*stack_a); */
}
