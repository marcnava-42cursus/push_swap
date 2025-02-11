/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:16:35 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/10 18:05:55 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_ps_node **stack)
{
	t_ps_node	*max;

	max = stack_biggest_node(*stack);
	if (max == *stack)
		ra(stack);
	else if (max == (*stack)->next)
		rra(stack);
	if ((*stack)->number > (*stack)->next->number)
		sa(stack);
}
