/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:39:25 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/20 20:35:58 by marcnava         ###   ########.fr       */
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
		if (a->index > len_a / 2)
			a->cost = len_a - a->index;
		if (a->target->half)
			a->cost += a->target->index;
		else
			a->cost += len_b - a->target->index;
		a = a->next;
	}
}

static void	find_targets(t_ps_node *a, t_ps_node *b)
{
	t_ps_node	*tmp_b;
	t_ps_node	*target;
	long		closest_value;

	while (a)
	{
		closest_value = LONG_MIN;
		tmp_b = b;
		while (tmp_b)
		{
			if (tmp_b->number < a->number && tmp_b->number > closest_value)
			{
				closest_value = tmp_b->number;
				target = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (closest_value == LONG_MIN)
			a->target = stack_biggest_node(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	find_cheapest(t_ps_node *stack)
{
	long		nbr;
	t_ps_node	*cheapest;

	if (!stack)
		return ;
	nbr = UINT_MAX;
	while (stack)
	{
		if (stack->cost < nbr)
		{
			nbr = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = true;
}

void	initialize_a(t_ps_node *a, t_ps_node *b)
{
	fix_indexes(a);
	fix_indexes(b);
	find_targets(a, b);
	calculate_cost(a, b);
	find_cheapest(a);
}
