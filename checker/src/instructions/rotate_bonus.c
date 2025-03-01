/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:29:21 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/01 19:45:43 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

static void	ft_rotate(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = head->next;
	head->next = NULL;
	ft_lstlast(*stack)->next = head;
}

void	ra(t_list **a)
{
	ft_rotate(a);
}

void	rb(t_list **b)
{
	ft_rotate(b);
}

void	rr(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
}
