/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:24:03 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/20 19:00:09 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	find_targets(t_ps_node *a, t_ps_node *b)
{
	t_ps_node	*tmp_a;
	t_ps_node	*target;
	long		closest_value;

	while (b)
	{
		closest_value = LONG_MAX;
		tmp_a = a;
		while (tmp_a)
		{
			if (tmp_a->number > b->number && tmp_a->number < closest_value)
			{
				closest_value = tmp_a->number;
				target = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (closest_value == LONG_MAX)
			b->target = stack_smallest_node(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	initialize_b(t_ps_node *a, t_ps_node *b)
{
	fix_indexes(a);
	fix_indexes(b);
	find_targets(a, b);
}
