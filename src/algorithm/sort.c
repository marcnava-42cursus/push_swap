/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:24:40 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/20 21:14:14 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	first_smaller(t_ps_node **stack)
{
	while ((*stack)->number != stack_smallest_node(*stack)->number)
	{
		if (stack_smallest_node(*stack)->half)
			ra(stack);
		else
			rra(stack);
	}
}

static void pre_sort_a(t_ps_node **a, t_ps_node **b)
{
	t_ps_node	*cheapest;

	cheapest = cheapest_node(*a);
	if (cheapest->half && cheapest->target->half)
		check_rr(a, b, cheapest);
	else if (!(cheapest->half) && !(cheapest->target->half))
		check_rrr(a, b, cheapest);
	check_push(a, cheapest, STACK_A);
	check_push(b, cheapest->target, STACK_B);
	pb(b, a);
}

static void	pre_sort_b(t_ps_node **a, t_ps_node **b)
{
	check_push(a, (*b)->target, STACK_A);
	pa(a, b);
}

void	sort(t_ps_node **a, t_ps_node **b)
{
	int	len;

	len = stack_len(*a);
	while (len > 3 && stack_is_sorted(*a))
	{
		initialize_a(*a, *b);
		pre_sort_a(a, b);
	}
	sort_three(a);
	while (*b)
	{
		initialize_b(*a, *b);
		pre_sort_b(a, b);
	}
	fix_indexes(*a);
	first_smaller(a);
}
