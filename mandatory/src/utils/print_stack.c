/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:44:07 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/28 17:12:27 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_stack(t_ps_node *node)
{
	t_ps_node	*current;

	current = node;
	ft_printf("[");
	while (current != NULL)
	{
		ft_printf("%d", current->number);
		if (current->next != NULL)
			ft_printf(", ");
		current = current->next;
	}
	ft_printf("]\n");
}
