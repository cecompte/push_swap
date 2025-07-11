
#include "push_swap.h"

// replace push cost with count operations

int	count_rotate(int position, t_node **stack)
{
	int	count;

	if (position - 1 < count_nodes(*stack) - position + 1)
		count = position - 1;
	else
		count = 0;
	return (count);
}
int	count_rev_rotate(int position, t_node **stack)
{
	int	count;

	if (position - 1 >= count_nodes(*stack) - position + 1)
		count = count_nodes(*stack) - position + 1;
	else
		count = 0;
	return (count);
}

int	count_rr(int position_a, int position_b, t_node **stack_a, t_node **stack_b)
{
	int	ra;
	int	rb;
	int	rr;

	ra = count_rotate(position_a, stack_a);
	rb = count_rotate(position_b, stack_b);
	if (ra > rb)
		rr = rb;
	else
		rr = ra;
	return (rr);
}

int	count_rrr(int position_a, int position_b, t_node **stack_a, t_node **stack_b)
{
	int	rra;
	int	rrb;
	int	rrr;

	rra = count_rev_rotate(position_a, stack_a);
	rrb = count_rev_rotate(position_b, stack_b);
	if (rra > rrb)
		rrr = rrb;
	else
		rrr = rra;
	return (rrr);
}
int	push_cost(int position_a, int position_b, t_node **stack_a, t_node **stack_b)
{
	int	nb_ra;
	int	nb_rb;
	int	nb_rra;
	int	nb_rrb;
	int	nb_rr;
	int	nb_rrr;
	int	cost;

	nb_ra = count_rotate(position_a, stack_a) - count_rr(position_a, position_b, stack_a, stack_b);
	nb_rb = count_rotate(position_b, stack_b) - count_rr(position_a, position_b, stack_a, stack_b);
	nb_rra = count_rev_rotate(position_a, stack_a) - count_rrr(position_a, position_b, stack_a, stack_b);
	nb_rrb = count_rev_rotate(position_b, stack_b) - count_rrr(position_a, position_b, stack_a, stack_b);
	nb_rr = count_rr(position_a, position_b, stack_a, stack_b);
	nb_rrr = count_rrr(position_a, position_b, stack_a, stack_b);
	cost = nb_ra + nb_rb + nb_rra + nb_rrb + nb_rr + nb_rrr;
	return (cost);
}