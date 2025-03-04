/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:12:49 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/05 14:49:34 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_node	*a;
	t_ps_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	// else if (argc == 2)
	// 	argv = ft_split(argv[1], ' ');
	init_stack(&a, argv + 1);
	if (!stack_is_sorted(a))
	{
		if (stack_len(a) == 2)
			sort_two(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
