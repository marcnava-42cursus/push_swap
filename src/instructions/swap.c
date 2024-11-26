/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:37:45 by marcnava          #+#    #+#             */
/*   Updated: 2024/11/26 22:54:49 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../libs/libft/headers/libft.h"

static void	_swap(t_ps_node **node)
{
	if (!*node || !(*node)->next)
		return ;
	*node = (*node)->next;
	return ;
}

// (*head)->prev->prev = *head; //Update the `prev` pointer of the node before the `new head` to point to the `new head`
// (*head)->prev->next = (*head)->next; //Update the `next` pointer of the node before the `new head` to skip the `old head` and point directly to the `new head`
// if ((*head)->next) //Check if there's a `next` node after the `new head` and
// 	(*head)->next->prev = (*head)->prev; //If so, update its `prev` pointer to point back to the `new head`
// (*head)->next = (*head)->prev; //Update the `next` pointer of the `new head` to point to the `old head`, effectively reversing their positions
// (*head)->prev = NULL; //Sets the `prev` pointer of the `new head` to `NULL` completing the swap

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
