/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:12:38 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/28 17:17:11 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	_append_node(t_ps_node **stack, int n)
{
	t_ps_node	*node;
	t_ps_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_ps_node));
	if (!node)
		return ;
	node->next = NULL;
	node->number = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = stack_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack(t_ps_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (check_sintax(argv[i]))
			terminate(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			terminate(a);
		if (check_dup(*a, (int)n))
			terminate(a);
		_append_node(a, (int)n);
		i++;
	}
}

void	fix_indexes(t_ps_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->half = TRUE;
		else
			stack->half = FALSE;
		stack = stack->next;
		++i;
	}
}
