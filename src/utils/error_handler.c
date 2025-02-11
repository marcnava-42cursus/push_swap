/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:19:14 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/10 18:04:11 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_sintax(char *value)
{
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

int	check_dup(t_ps_node *stack, int nbr)
{
	if (!stack)
		return (OK);
	while (stack)
	{
		if (stack->number == nbr)
			return (KO);
		stack = stack->next;
	}
	return (OK);
}

void	terminate(t_ps_node **stack, char **values,
	int error_index, const char *error_message)
{
	int	i;

	i = 0;
	free_stack(stack);
	ft_printf("Error: %s\n", error_message);
	ft_printf("./push_swap ");
	while (values[i])
	{
		if (i == error_index)
			ft_printf("\033[31m%s\033[0m ", values[i]);
		else
			ft_printf("%s ", values[i]);
		i++;
	}
	ft_printf("\n");
	exit(KO);
}
