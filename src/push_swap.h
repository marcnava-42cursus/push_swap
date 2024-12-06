/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:29:55 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/06 03:01:21 by marcnava         ###   ########.fr       */
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
}			t_ps_node;

// INSTRUCTIONS

void		pa(t_ps_node **a, t_ps_node **b);
void		pb(t_ps_node **b, t_ps_node **a);

void		ra(t_ps_node **a);
void		rb(t_ps_node **b);
void		rr(t_ps_node **a, t_ps_node **b);
void		rra(t_ps_node **a);
void		rrb(t_ps_node **b);
void		rrr(t_ps_node **a, t_ps_node **b);

void		sa(t_ps_node **a);
void		sb(t_ps_node **b);
void		ss(t_ps_node **a, t_ps_node **b);

// UTILS

void		ft_free_stack(t_ps_node **stack);

t_ps_node	*ft_last_node(t_ps_node *node);
bool		ft_is_sorted(t_ps_node *stack);
int			ft_stack_len(t_ps_node *stack);
t_ps_node	*ft_find_biggest(t_ps_node *stack);
t_ps_node	*ft_find_smallest(t_ps_node *stack);

void		ft_init_stack(t_ps_node **stack, char **values);

// ALGORITHM

void		ft_sort_two(t_ps_node **stack);
void		ft_sort_three(t_ps_node **stack);
void		ft_sort(t_ps_node **a, t_ps_node **b);

#endif