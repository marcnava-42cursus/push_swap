/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:51:17 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/11 15:46:49 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	_append_node(t_ps_node **stack, int content)
{
	t_ps_node	*new;
	t_ps_node	*last;

	if (!stack)
		return ;
	new = ft_calloc(1, sizeof(t_ps_node));
	if (!new)
		return ;
	new->next = NULL;
	new->number = content;
	new->cheapest = 0;
	if (!(*stack))
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = stack_last_node(*stack);
		last->next = new;
		new->prev = last;
	}
}

void	init_stack(t_ps_node **stack, char **values)
{
	int		i;
	long	value;

	i = 0;
	while (values[i])
	{
		if (check_sintax(values[i]))
			terminate(stack, values, i, "invalid syntax");
		value = ft_atol(values[i]);
		if (value > INT_MAX || value < INT_MIN)
			terminate(stack, values, i, "value out of range");
		if (check_dup(*stack, (int)value))
			terminate(stack, values, i, "duplicated values");
		_append_node(stack, (int)value);
		i++;
	}
}

void	fix_indexes(t_ps_node *stack)
{
	int	index;
	int	half;

	index = 0;
	if (!stack)
		return ;
	half = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= half)
			stack->half = 0;
		else
			stack->half = 1;
		stack = stack->next;
		index++;
	}
}
