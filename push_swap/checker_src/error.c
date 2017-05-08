/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 12:16:10 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 15:32:27 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ft_exit_checker(t_push **list_a, t_push **list_b)
{
	(*list_a != NULL) ? clear_list(list_a) : 0;
	(*list_b != NULL) ? clear_list(list_b) : 0;
	write(1, "\033[31;1m", ft_strlen("\033[31;1m"));
	write(1, "Error\n", 6);
	write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
	exit(0);
}

void		messag(char *str, int choice, long long nbr_coup, t_opt *opt)
{
	if (opt->instruc)
	{
		write(1, "Number of shots : (", 19);
		ft_putnbr(nbr_coup);
		write(1, ") >> ", 5);
	}
	(choice == 1) ? write(1, str, ft_strlen(str)) : 0;
	(choice == 1) ? write(1, "OK\n", 3) : 0;
	(choice == 0) ? write(1, str, ft_strlen(str)) : 0;
	(choice == 0) ? write(1, "KO\n", 3) : 0;
	write(1, DEFAULT, ft_strlen(DEFAULT));
}

void		check_if_sorted(t_push **list_a, t_opt *opt, int i_coups, \
																t_push *list_b)
{
	int		*board;

	board = transforms_list_to_array(*list_a);
	if (opt->desc == 1)
	{
		if (is_sorted_descending_array(board, lenght_list(*list_a)) \
												&& lenght_list(list_b) == 0)
			messag(GREEN, 1, i_coups, opt);
		else
			messag(RED, 0, i_coups, opt);
	}
	else
	{
		if (is_sorted_ascending_array(board, lenght_list(*list_a)) \
												&& lenght_list(list_b) == 0)
			messag(GREEN, 1, i_coups, opt);
		else
			messag(RED, 0, i_coups, opt);
	}
	free(board);
}
