/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:09:02 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/06 03:51:43 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ps_node	*ft_last_node(t_ps_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

bool	ft_is_sorted(t_ps_node *stack)
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

int	ft_stack_len(t_ps_node *stack)
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

t_ps_node	*ft_find_smallest(t_ps_node *stack)
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

t_ps_node	*ft_find_biggest(t_ps_node *stack)
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
