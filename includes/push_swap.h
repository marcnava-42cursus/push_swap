/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:29:55 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/05 20:49:21 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/includes/libft.h"
# include <stdbool.h>

# define OK 0
# define KO 1

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

void		free_stack(t_ps_node **stack);

t_ps_node	*stack_last_node(t_ps_node *stack);
bool		stack_is_sorted(t_ps_node *stack);
int			stack_len(t_ps_node *stack);
t_ps_node	*stack_biggest_node(t_ps_node *stack);
t_ps_node	*stack_smallest_node(t_ps_node *stack);

void		init_stack(t_ps_node **stack, char **values);
void		print_stack(t_ps_node *stack);

// ALGORITHM

void		sort_two(t_ps_node **stack);
void		sort_three(t_ps_node **stack);
void		sort(t_ps_node **a, t_ps_node **b);

// ERRORS

int			check_sintax(char *value);
int			check_dup(t_ps_node *stack, int nbr);
void		terminate(t_ps_node **stack, char **values, int error_index, const char *error_message);

#endif