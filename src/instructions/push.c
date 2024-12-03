/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:48:08 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/03 19:10:32 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	_insert_into_dest(t_ps_node **dest, t_ps_node *node)
{
	t_ps_node	*dest_tail;

	if (*dest)
	{
		dest_tail = (*dest)->prev;
		dest_tail->next = node;
		node->prev = dest_tail;
		node->next = *dest;
		(*dest)->prev = node;
	}
	else
	{
		*dest = node;
		node->next = node;
		node->prev = node;
	}
}

static void	_push(t_ps_node **dest, t_ps_node **src)
{
	t_ps_node	*node;

	if (!*src)
		return ;
	node = *src;
	if ((*src)->next == *src)
		*src = NULL;
	else
	{
		(*src)->prev->next = (*src)->next;
		(*src)->next->prev = (*src)->prev;
		*src = (*src)->next;
	}
	_insert_into_dest(dest, node);
}

void	pa(t_ps_node **a, t_ps_node **b)
{
	_push(a, b);
	ft_printf("pa\n");
}

void	pb(t_ps_node **a, t_ps_node **b)
{
	_push(b, a);
	ft_printf("pb\n");
}
