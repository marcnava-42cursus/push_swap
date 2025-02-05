/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:09:02 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/04 17:56:59 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


t_ps_node	*stack_last_node(t_ps_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

bool	stack_is_sorted(t_ps_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	stack_len(t_ps_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_ps_node	*stack_smallest_node(t_ps_node *stack)
{
	long		min;
	t_ps_node	*node;

	if (!stack)
		return (NULL);
	min = UINT_MAX;
	while (stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

t_ps_node	*stack_biggest_node(t_ps_node *stack)
{
	long		max;
	t_ps_node	*node;

	if (!stack)
		return (NULL);
	max = -UINT_MAX;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}
