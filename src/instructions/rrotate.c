/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:54:02 by marcnava          #+#    #+#             */
/*   Updated: 2024/11/26 22:24:45 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../libs/libft/headers/libft.h"

static void	_rrotate(t_ps_node **node)
{
	if (!*node || !(*node)->next)
		return ;
	return ;
}

void	rra(t_ps_node **a)
{
	_rrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_ps_node **b)
{
	_rrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_ps_node **a, t_ps_node **b)
{
	_rrotate(a);
	_rrotate(b);
	ft_printf("rrr\n");
}
