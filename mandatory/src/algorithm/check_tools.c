/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:11:40 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/01 19:35:48 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	check_rr(t_ps_node **a, t_ps_node **b, t_ps_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b);
	fix_indexes(*a);
	fix_indexes(*b);
}

void	check_rrr(t_ps_node **a, t_ps_node **b, t_ps_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	fix_indexes(*a);
	fix_indexes(*b);
}

void	check_push(t_ps_node **stack, t_ps_node *top, char name)
{
	while (*stack != top)
	{
		if (name == STACK_A)
		{
			if (top->half)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == STACK_B)
		{
			if (top->half)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
