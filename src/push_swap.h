/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:29:55 by marcnava          #+#    #+#             */
/*   Updated: 2024/11/25 20:00:29 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/headers/libft.h"
# include <stdbool.h>

typedef struct s_ps_node
{
	int					number;
	int					index;
	int					cost;
	bool				half;
	bool				cheapest;

	struct s_ps_node	*target;
	struct s_ps_node	*next;
	struct s_ps_node	*prev;
}		t_ps_node;

void	pa(t_ps_node **a, t_ps_node **b);
void	pb(t_ps_node **b, t_ps_node **a);

void	ra(t_ps_node **a);
void	rb(t_ps_node **b);
void	rr(t_ps_node **a, t_ps_node **b);
void	rra(t_ps_node **a);
void	rrb(t_ps_node **b);
void	rrr(t_ps_node **a, t_ps_node **b);

void	sa(t_ps_node **a);
void	sb(t_ps_node **b);
void	ss(t_ps_node **a, t_ps_node **b);

#endif