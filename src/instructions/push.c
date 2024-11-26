/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:48:08 by marcnava          #+#    #+#             */
/*   Updated: 2024/11/26 22:24:53 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../libs/libft/headers/libft.h"

static void	_push(t_ps_node **dest, t_ps_node **src)
{
	dest = src;
	src = dest;
	return ;
}

void	pa(t_ps_node **a, t_ps_node **b)
{
	_push(a, b);
	ft_printf("pa\n");
}

void	pb(t_ps_node **a, t_ps_node **b)
{
	_push(b, a);
	ft_printf("pb\n");
}
