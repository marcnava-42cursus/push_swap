/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:12:19 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/28 17:12:19 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_ps_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_ps_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_ps_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_ps_node **a, t_ps_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}