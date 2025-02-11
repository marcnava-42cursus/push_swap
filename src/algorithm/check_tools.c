/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:34:35 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/10 19:28:19 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	check_rr(t_ps_node **a, t_ps_node **b, t_ps_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rr(a, b);
	fix_indexes(*a);
	fix_indexes(*b);
}

void	check_rrr(t_ps_node **a, t_ps_node **b, t_ps_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rrr(a, b);
	fix_indexes(*a);
	fix_indexes(*b);
}

void	check_push(t_ps_node **stack, t_ps_node *to_top, char name)
{
	if (*stack != to_top)
	{
		if (name == 'a')
		{
			if (to_top->half)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (to_top->half)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

