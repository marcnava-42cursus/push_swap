/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:12:12 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/01 19:36:31 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_ps_node **stack)
{
	t_ps_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = stack_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_ps_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_ps_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_ps_node **a, t_ps_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
