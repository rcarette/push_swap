/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:04:44 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 12:10:47 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			ft_usage(t_push **list_a)
{
	(list_a != NULL) ? clear_list(list_a) : 0;
	write(1, "\033[31;1m", ft_strlen("\033[31;1m"));
	write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
	write(1, "\033[32;1m", ft_strlen("\033[32;1m"));
	write(1, "Usage :\n", 8);
	write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
	write(1, "-v : visualization display\n", 27);
	write(1, "-t : slow motion display", 24);
	write(1, "\033[31;1m", ft_strlen("\033[31;1m"));
	write(1, " /!\\ requires -v option to be enabled\n", 38);
	write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
	write(1, "-d : descending sort\n", 21);
	write(1, "-i : shows the number of moves\n", 31);
	exit(0);
}

void			check_option(t_opt *opt)
{
	if (opt->visualization == 0 && opt->time == 1)
		opt->time = 0;
}
