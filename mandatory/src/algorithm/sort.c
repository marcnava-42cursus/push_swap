/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:12:03 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/01 19:35:25 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	first_smaller(t_ps_node **a)
{
	while ((*a)->number != stack_smallest_node(*a)->number)
	{
		if (stack_smallest_node(*a)->half)
			ra(a);
		else
			rra(a);
	}
}

static void	pre_sort_a(t_ps_node **a, t_ps_node **b)
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
	check_push(a, (*b)->target, 'a');
	pa(a, b);
}

void	sort(t_ps_node **a, t_ps_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_is_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !stack_is_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !stack_is_sorted(*a))
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
