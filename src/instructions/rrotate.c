/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:54:02 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/10 18:06:12 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	_rrotate(t_ps_node **node)
{
	t_ps_node	*last;

	if (!*node || !(*node)->next)
		return ;
	last = stack_last_node(*node);
	(*node)->prev = last;
	last->next = *node;
	*node = last;
	(*node)->prev->next = NULL;
	(*node)->prev = NULL;
}

void	rra(t_ps_node **a)
{
	_rrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_ps_node **b)
{
	_rrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_ps_node **a, t_ps_node **b)
{
	_rrotate(a);
	_rrotate(b);
	ft_printf("rrr\n");
}
