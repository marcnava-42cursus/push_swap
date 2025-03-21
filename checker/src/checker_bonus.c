/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:24:03 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/18 19:13:56 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static int	lexer(char *input, t_swap *tab)
{
	if (ft_strcmp(input, "sa\n") == 0)
		sa(&tab->stack_a);
	else if (ft_strcmp(input, "sb\n") == 0)
		sb(&tab->stack_b);
	else if (ft_strcmp(input, "ss\n") == 0)
		ss(&tab->stack_a, &tab->stack_b);
	else if (ft_strcmp(input, "pa\n") == 0)
		pa(&tab->stack_a, &tab->stack_b);
	else if (ft_strcmp(input, "pb\n") == 0)
		pb(&tab->stack_a, &tab->stack_b);
	else if (ft_strcmp(input, "ra\n") == 0)
		ra(&tab->stack_a);
	else if (ft_strcmp(input, "rb\n") == 0)
		rb(&tab->stack_b);
	else if (ft_strcmp(input, "rra\n") == 0)
		rra(&tab->stack_a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		rrb(&tab->stack_b);
	else if (ft_strcmp(input, "rr\n") == 0)
		rr(&tab->stack_a, &tab->stack_b);
	else if (ft_strcmp(input, "rrr\n") == 0)
		rrr(&tab->stack_a, &tab->stack_b);
	else
		return (free(input), 0);
	return (free(input), 1);
}

static int	ft_check(t_list *lst, int n, char *nbr)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (nbr[i])
	{
		if (!(((nbr[i] == '-' || nbr[i] == '+')
					&& ft_isdigit(nbr[i + 1])) || ft_isdigit(nbr[i])))
			return (0);
		i++;
	}
	while (tmp)
	{
		if ((long int)tmp->content == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static t_list	*ft_init(char **argv, int argc)
{
	t_list	*tmp;
	t_list	*res;
	int		i;
	long	nbr;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	res = NULL;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		if (!(nbr < INT_MAX && nbr > INT_MIN)
			|| ft_check(res, nbr, argv[i]) == 0)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(1);
		}
		tmp = ft_lstnew(&nbr);
		ft_lstadd_back(&res, tmp);
		tmp->content = (void *)nbr;
		i++;
	}
	return (res);
}

static void	input(t_swap *tab)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (!lexer(input, tab))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(1);
		}
		input = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_swap	*tab;

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (argc == 1)
		return (0);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		return (1);
	tab->stack_b = NULL;
	tab->stack_a = ft_init(argv, argc);
	if (tab->stack_a == NULL)
		return (1);
	input(tab);
	if (is_sorted(tab->stack_a) && !tab->stack_b)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}
