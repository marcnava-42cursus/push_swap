/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:19:07 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/17 19:18:16 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stack(t_ps_node **stack)
{
	t_ps_node	*tmp;
	t_ps_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->number = 0;
		ft_free((void *)&current);
		current = tmp;
	}
	*stack = NULL;
}

t_ps_node	*cheapest_node(t_ps_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	push_a(t_ps_node **a, t_ps_node **b)
{
	t_ps_node	*cheapest;

	cheapest = cheapest_node(*b);
	if (cheapest->half && cheapest->target->half)
		check_rr(a, b, cheapest);
	else if (!(cheapest->half) && !(cheapest->target->half))
		check_rrr(a, b, cheapest);
}
