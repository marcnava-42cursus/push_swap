/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:12:22 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/17 13:47:38 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_sintax(char *value)
{
	if (!value || !*value)
		return (KO);
	if (!ft_strchr("+-0123456789", *value))
		return (KO);
	if (ft_strchr("+-", *value) && !ft_isdigit(value[1]))
		return (KO);
	while (*++value)
	{
		if (!ft_isdigit(*value))
			return (KO);
	}
	return (OK);
}

int	check_dup(t_ps_node *a, int n)
{
	if (!a)
		return (OK);
	while (a)
	{
		if (a->number == n)
			return (KO);
		a = a->next;
	}
	return (OK);
}

void	terminate(t_ps_node **a)
{
	free_stack(a);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(KO);
}
