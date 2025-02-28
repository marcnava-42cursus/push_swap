/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:12:15 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/28 17:12:16 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rev_rotate(t_ps_node **stack)
{
	t_ps_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = stack_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_ps_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_ps_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_ps_node **a, t_ps_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}