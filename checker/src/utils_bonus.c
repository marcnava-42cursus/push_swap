/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:33:55 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/05 15:18:43 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	is_sorted(t_list	*stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	print_stack(t_list *node)
{
	t_list	*current;

	current = node;
	ft_printf("[");
	while (current != NULL)
	{
		ft_printf("%d", current->content);
		if (current->next != NULL)
			ft_printf(", ");
		current = current->next;
	}
	ft_printf("]\n");
}

int	int_off_limits(int nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (1);
	return (0);
}
