/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:46:42 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 16:18:14 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		ft_start_pushswap(t_push **list_a, t_push **list_b, t_opt *opt)
{
	int		*board;
	int		size_elements;

	size_elements = lenght_list(*list_a);
	board = transforms_list_to_array(*list_a);
	if (opt->desc == 1)
	{
		if (is_sorted_descending_array(board, size_elements))
			return (free(board));
	}
	else
	{
		if (is_sorted_ascending_array(board, size_elements))
			return (free(board));
	}
	free(board);
	ft_start_ascending(list_a, list_b, opt);
}

int				main(int argc, const char *argv[])
{
	t_push		*list_a;
	t_push		*list_b;
	t_opt		opt;
	int			returns;
	int			i;

	init_opt(&opt);
	i = -1;
	list_a = NULL;
	list_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc > 1)
	{
		returns = get_arguments(argv, &list_a, &opt);
		if (returns == 0)
			ft_exit(&list_a);
		else if (returns == -1)
			ft_usage(&list_a);
		check_option(&opt);
	}
	ft_start_pushswap(&list_a, &list_b, &opt);
	(list_a != NULL) ? clear_list(&list_a) : 0;
	(list_b != NULL) ? clear_list(&list_b) : 0;
	return (0);
}
