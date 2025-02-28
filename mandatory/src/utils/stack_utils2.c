/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:12:43 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/28 17:14:13 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	set_target_b(t_ps_node *a, t_ps_node *b)
{
	t_ps_node	*current_a;
	t_ps_node	*target_node;
	long		best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->number > b->number
				&& current_a->number < best_match_index)
			{
				best_match_index = current_a->number;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = stack_smallest_node(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	initialize_b(t_ps_node *a, t_ps_node *b)
{
	fix_indexes(a);
	fix_indexes(b);
	set_target_b(a, b);
}
