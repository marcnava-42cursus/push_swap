/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:37:45 by marcnava          #+#    #+#             */
/*   Updated: 2024/11/25 19:47:45 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../libs/libft/headers/libft.h"

static void	_swap(t_ps_node **init)
{
	return ;
}

void	sa(t_ps_node **a)
{
	_swap(a);
	ft_printf("sa\n");
}

void	sb(t_ps_node **b)
{
	_swap(b);
	ft_printf("sb\n");
}

void	ss(t_ps_node **a, t_ps_node **b)
{
	_swap(a);
	_swap(b);
	ft_printf("ss\n");
}
