/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:50:52 by marcnava          #+#    #+#             */
/*   Updated: 2024/11/29 18:52:45 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../libs/libft/headers/libft.h"

static void	_rotate(t_ps_node **node)
{
	t_ps_node	*last;

	if (!*node || !(*node)->next)
		return ;
	last = ft_last_node(*node);
	last->next = *node;
	*node = (*node)->next;
	(*node)->prev->prev = last;
	(*node)->prev = NULL;
	last->next->next = NULL;
}

void	ra(t_ps_node **a)
{
	_rotate(a);
	ft_printf("ra\n");
}

void	rb(t_ps_node **b)
{
	_rotate(b);
	ft_printf("rb\n");
}

void	rr(t_ps_node **a, t_ps_node **b)
{
	_rotate(a);
	_rotate(b);
	ft_printf("rr\n");
}
