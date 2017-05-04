/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:12:38 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/03 22:45:50 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int		check_data(const char *str)
{
	int		ite;

	ite = -1;
	ite += (str[0] == '-') ? 1 : 0;
	ite += (str[0] == '+') ? 1 : 0;
	while (str[++ite])
		if (!(ft_isdigit(str[ite])))
			return (0);
	return (1);
}

static int		check_data_list(t_push *list, int data)
{
	if (lenght_list(list) == 0)
		return (1);
	while (list)
	{
		if (list->value == data)
			return (0);
		list = list->next;
	}
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

static int		ft_getoption(char *str, t_opt *opt)
{
	int		ite;

	ite = 0;
	while (str[++ite])
	{
		if (str[ite] == 'd')
			opt->descending = 1;
		else if (str[ite] == 't')
			opt->time = 1;
		else if (str[ite] == 'v')
			opt->visualization = 1;
		else if (str[ite] == 'i')
			opt->instruc = 1;
		else
			return (-1);
	}
	return (1);
}

int				get_arguments(const char **av, t_push **list, t_opt *opt)
{
	int				ite;
	long long		data;

	ite = 0;
	(void)opt;
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
			if (!(check_data(av[ite])))
				return (0);
			data = ft_atoi(av[ite]);
			if (data < MIN_INT || data > MAX_INT)
				return (0);
			if (!(check_data_list(*list, data)))
				return (0);
			push_back(list, data);
		}
	}
	return (1);
}
