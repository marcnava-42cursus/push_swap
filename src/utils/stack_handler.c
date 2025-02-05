/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:19:07 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/04 17:55:04 by marcnava         ###   ########.fr       */
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
