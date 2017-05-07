/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 06:22:01 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/07 08:54:12 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void			display_top_stack(void)
{
	write(1, "\033[32;1m", ft_strlen("\033[32;1m"));
	write(1, "|    PILE A    |", 16);
	write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
	write(1, "   ", 3);
	write(1, "\033[31;1m", ft_strlen("\033[31;1m"));
	write(1, "|    PILE B    |\n",17);
	write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
}

static void			display_separator(char *color)
{
	write(1, color, ft_strlen(color));
	write(1, "|", 1);
	write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
}

static void			display_data(t_push *list_a)
{
	int		spaces;
	int		size;

	spaces = 14;
	size = getintsize(list_a->value);
	spaces -= size;
	while (spaces--)
		write(1, " ", 1);
	ft_putnbr(list_a->value);
}

static void			fuck_norm(void)
{
	display_separator("\033[32;1m");
	write(1, "   ", 3);
	display_separator("\033[31;1m");
}


void			visualization(t_push *list_a, t_push *list_b, t_opt *opt)
{

	display_top_stack();
	while (1)
	{
		(opt->time) ? sleep(opt->time_opt) : 0;
		display_separator("\033[32;1m");
		if (list_a)
		{
			display_data(list_a);
			list_a = list_a->next;
		}
		else
			write(1, "              ", 14);
		fuck_norm();
		if (list_b)
		{
			display_data(list_b);
			list_b = list_b->next;
		}
		else
			write(1, "              ", 14);
		display_separator("\033[31;1m");
		if (!list_a && !list_b)
			return ;
		write(1, "\n", 1);
	}
}
