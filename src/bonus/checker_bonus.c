/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:14:15 by cecompte          #+#    #+#             */
/*   Updated: 2025/07/24 14:39:24 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"
#include "get_next_line.h"

int	is_sorted(t_node **stack)
{
	t_node	*current;

	if (!(*stack))
		return (0);
	current = *stack;
	while (current->next)
	{
		if (current->number < current->next->number)
			current = current->next;
		else
			return (0);
	}
	return (1);
}

static void	get_input(t_list **input, t_node **stack_a, t_node **stack_b)
{
	char	*line;
	t_list	*current;

	line = get_next_line(0);
	current = *input;
	while (line)
	{
		current = ft_lstnew(line);
		if (!current)
		{
			free (line);
			exit_error_bonus(input, stack_a, stack_b);
		}
		ft_lstadd_back(input, current);
		line = get_next_line(0);
	}
}

static void	apply_instr(t_list *input, t_node **stack_a, t_node **stack_b)
{
	if (!ft_strncmp(input->content, "pa\n", 3))
		push(stack_a, stack_b);
	else if (!ft_strncmp(input->content, "pb\n", 3))
		push(stack_b, stack_a);
	else if (!ft_strncmp(input->content, "sa\n", 3))
		swap(*stack_a);
	else if (!ft_strncmp(input->content, "sb\n", 3))
		swap(*stack_b);
	else if (!ft_strncmp(input->content, "ra\n", 3))
		rotate(stack_a);
	else if (!ft_strncmp(input->content, "rb\n", 3))
		rotate(stack_b);
	else if (!ft_strncmp(input->content, "rra\n", 4))
		rrotate(stack_a);
	else if (!ft_strncmp(input->content, "rrb\n", 4))
		rrotate(stack_b);
	else if (!ft_strncmp(input->content, "rrr\n", 4))
		double_rrotate(stack_a, stack_b);
	else if (!ft_strncmp(input->content, "rr\n", 3))
		double_rotate(stack_a, stack_b);
	else if (!ft_strncmp(input->content, "ss\n", 3))
		double_swap(stack_a, stack_b);
	else
		exit_error_bonus(&input, stack_a, stack_b);
}

static void	sort(t_list *input, t_node **stack_a, t_node **stack_b)
{
	t_list	*current;

	current = input;
	while (current)
	{
		apply_instr(current, &stack_a, &stack_b);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*input;
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	init_stack(&stack_a, argc, argv);
	if (!stack_a)
		exit_error(&stack_a);
	stack_b = NULL;
	input = NULL;
	get_input(&input, &stack_a, &stack_b);
	sort(input, &stack_a, &stack_b);
	if (is_sorted(&stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(&input, free);
	lstclear(&stack_a);
	lstclear(&stack_b);
	return (0);
}
