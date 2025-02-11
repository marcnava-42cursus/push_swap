/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:24:40 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/10 21:03:57 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort(t_ps_node **a, t_ps_node **b)
{
	int	len;

	len = stack_len(*a);
	while (len > 3 && stack_is_sorted(*a))
	{
		initialize_a(*a, *b);
	}
}
