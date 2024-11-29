/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:48:08 by marcnava          #+#    #+#             */
/*   Updated: 2024/11/29 19:33:22 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../libs/libft/headers/libft.h"

static void _push(t_ps_node **dest, t_ps_node **src)
{
	t_ps_node	*node;

	if (!*src)
		return;
	node = *src;
	// nde - [NULL] a [(src)b]
	// SRC - [NULL] a [(src)b] - [(src)a] b [(src)c] - ...
	// DST - [NULL] a [(dst)b] - [(dst)a] b [(dst)c] - ...
	*src = (*src)->next;
	// nde - [NULL] a [(src)b]
	// SRC - [(src)a] b [(src)c] - ...
	// DST - [NULL] a [(dst)b] - [(dst)a] b [(dst)c] - ...
	if (*src)
		(*src)->prev = NULL;
	// nde - [NULL] a [(src)b]
	// SRC - [NULL] b [(src)c] - ...
	// DST - [NULL] a [(dst)b] - [(dst)a] b [(dst)c] - ...
	if (*dest)
	{
		node->next = *dest;
		// nde - [NULL] a [(dst)a]
		// SRC - [NULL] b [(src)c] - ...
		// DST - [NULL] a [(dst)b] - [(dst)a] b [(dst)c] - ...
		(*dest)->prev = node;
		// nde - [NULL] a [(dst)a]
		// SRC - [NULL] b [(src)c] - ...
		// DST - [(nde)a] a [(dst)b] - [(dst)a] b [(dst)c] - ...
		*dest = node;
		// SRC - [NULL] b [(src)c] - ...
		// DST - [NULL] a [(dst)a] - [(nde)a] a [(dst)b] - [(dst)a] b [(dst)c] - ...
	}
	else
	{
		// nde - [NULL] a [(src)b]
		// SRC - [NULL] b [(src)c] - ...
		// DST - NULL
		*dest = node;
		// nde - [NULL] a [(src)b]
		// SRC - [NULL] b [(src)c] - ...
		// DST - [NULL] a [(src)b]
		(*dest)->next = NULL;
		// nde - [NULL] a [(src)b]
		// SRC - [NULL] b [(src)c] - ...
		// DST - [NULL] a [NULL]
	}
}

void pa(t_ps_node **a, t_ps_node **b)
{
	_push(a, b);
	ft_printf("pa\n");
}

void pb(t_ps_node **a, t_ps_node **b)
{
	_push(b, a);
	ft_printf("pb\n");
}
