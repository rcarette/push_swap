/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:12:38 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 14:32:54 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int		fuck_norm(const char **av, int ite, t_push **list)
{
	long long	data;

	if (!(check_data(av[ite])))
		return (0);
	data = ft_atoi(av[ite]);
	if (data < MIN_INT || data > MAX_INT)
		return (0);
	if (!(check_data_list(*list, data)))
		return (0);
	push_back(list, data);
	return (1);
}

static int		split_spaces(char *str, t_push **list)
{
	char			**board;
	int				ite;
	long long		data;

	ite = -1;
	if (!(board = ft_strsplit(str, ' ')))
		return (0);
	if (board[0] == NULL)
		return (0);
	while (board[++ite])
	{
		if (!(check_data(board[ite])))
			return (clear_tab(board));
		data = ft_atoi(board[ite]);
		if (data < MIN_INT || data > MAX_INT)
			return (clear_tab(board));
		if (!(check_data_list(*list, data)))
			return (clear_tab(board));
		push_back(list, data);
	}
	clear_tab(board);
	return (1);
}

static int		ft_getoption(char *s1, t_opt *opt)
{
	int		i;

	i = 0;
	while (s1[++i])
	{
		if (s1[i] == 'l')
			opt->last_instruction = 1;
		else if (s1[i] == 'd')
			opt->desc = 1;
		else if (s1[i] == 't')
		{
			opt->time = 1;
			(ft_isdigit(s1[i + 1])) ? opt->time_opt = ft_atoi(&s1[i + 1]) : 0;
			i += (ft_isdigit(s1[i + 1])) ? getintsize(opt->time_opt) : 0;
		}
		else if (s1[i] == 'v')
			opt->visualization = 1;
		else if (s1[i] == 'i')
			opt->instruc = 1;
		else
			return (-1);
	}
	return (1);
}

int				get_arguments(const char **av, t_push **list, t_opt *opt)
{
	int				ite;

	ite = 0;
	while (av[++ite])
	{
		if ((av[ite][0] == '-' || av[ite][0] == '+') && ft_strlen(av[ite]) == 1)
			return (0);
		else if (av[ite][0] == '-' && ft_isalpha(av[ite][1]))
		{
			if (ft_getoption((char *)av[ite], opt) == -1)
				return (-1);
			continue ;
		}
		if (ft_strchr(av[ite], ' '))
		{
			if (!(split_spaces((char *)av[ite], list)))
				return (0);
		}
		else
		{
			if (!(fuck_norm(av, ite, list)))
				return (0);
		}
	}
	return (1);
}
