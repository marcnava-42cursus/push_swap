/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:51:17 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/03 19:29:43 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		last = ft_last_node(*stack);
		last->next = new;
		new->prev = last;
	}
}

void	ft_init_stack(t_ps_node **stack, char **values)
{
	long	n;
	int		i;

	i = 0;
	while (values[i])
	{
		n = ft_atol(values[i]);
		_append_node(stack, (int)n);
		i++;
	}
}
