/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:37:45 by marcnava          #+#    #+#             */
/*   Updated: 2025/01/29 19:23:11 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


static void	_swap(t_ps_node **node)
{
	if (!*node || !(*node)->next)
		return ;
	*node = (*node)->next;
	(*node)->prev->prev = *node;
	(*node)->prev->next = (*node)->next;
	if ((*node)->next)
		(*node)->next->prev = (*node)->prev;
	(*node)->next = (*node)->prev;
	(*node)->prev = NULL;
	return ;
}

void	sa(t_ps_node **a)
{
	_swap(a);
	ft_printf("sa\n");
}

void	sb(t_ps_node **b)
{
	_swap(b);
	ft_printf("sb\n");
}

void	ss(t_ps_node **a, t_ps_node **b)
{
	_swap(a);
	_swap(b);
	ft_printf("ss\n");
}
