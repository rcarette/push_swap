/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_pile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 11:53:01 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 16:11:55 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		replace(t_push **list_a, t_push **list_b)
{
	while (lenght_list(*list_b) != 0)
	{
		push(list_a, list_b, 1);
		write(1, "pa\n", 3);
	}
}

static void		replace_desc(t_push **list_a, t_push **list_b)
{
	while (lenght_list(*list_b) != 0)
	{
		ft_reverse_rotate(list_a, list_b, 1);
		write(1, "rrb\n", 4);
		push(list_a, list_b, 1);
		write(1, "pa\n", 3);
	}
}

static void		fuck_norm(t_push **list_a, t_push **list_b, int big_value, \
																	int choice)
{
	if (choice == 0)
	{
		while ((*list_b)->value != big_value)
		{
			ft_rotate(list_a, list_b, 1);
			write(1, "rb\n", 3);
		}
	}
	else
	{
		while ((*list_b)->value != big_value)
		{
			ft_reverse_rotate(list_a, list_b, 1);
			write(1, "rrb\n", 4);
		}
	}
}

void			replace_big_value(t_push **list_b, t_push **list_a, t_opt *opt)
{
	int		position;
	int		big_value;

	position = ft_getposition_big_value(*list_b, ft_getbig_value(*list_b));
	big_value = ft_getbig_value(*list_b);
	if (position == 0)
	{
		if (opt->desc == 1)
			return (replace_desc(list_a, list_b));
		replace(list_a, list_b);
	}
	if (position < 0)
		fuck_norm(list_a, list_b, big_value, 1);
	else
		fuck_norm(list_a, list_b, big_value, 0);
	(opt->desc == 1) ? replace_desc(list_a, list_b) : replace(list_a, list_b);
}
