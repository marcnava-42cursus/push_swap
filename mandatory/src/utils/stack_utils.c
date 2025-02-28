/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:12:41 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/28 17:17:02 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	calculate_cost(t_ps_node *a, t_ps_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->half))
			a->cost = len_a - (a->index);
		if (a->target->half)
			a->cost += a->target->index;
		else
			a->cost += len_b - (a->target->index);
		a = a->next;
	}
}

static void	find_targets(t_ps_node *a, t_ps_node *b)
{
	t_ps_node	*current_b;
	t_ps_node	*target_node;
	long		best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->number < a->number
				&& current_b->number > best_match_index)
			{
				best_match_index = current_b->number;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target = stack_biggest_node(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

static void	find_cheapest(t_ps_node *stack)
{
	long		cheapest_value;
	t_ps_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = TRUE;
}

void	initialize_a(t_ps_node *a, t_ps_node *b)
{
	fix_indexes(a);
	fix_indexes(b);
	find_targets(a, b);
	calculate_cost(a, b);
	find_cheapest(a);
}
