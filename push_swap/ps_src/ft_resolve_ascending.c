/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_ascending.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:48:51 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 14:42:42 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		prepare_sort(t_push **list_a, t_push **list_b)
{
	char	i;

	i = 2;
	while (i--)
	{
		push(list_a, list_b, 0);
		write(1, "pb\n", 3);
	}
}

static void		double_rotate(t_push **list_a, t_push **list_b, \
														t_rotate *best_shot)
{
	if (best_shot->double_rotate < 0)
	{
		best_shot->double_rotate = (-best_shot->double_rotate);
		while (best_shot->double_rotate)
		{
			ft_reverse_rotate_rrr(list_a, list_b);
			write(1, "rrr\n", 4);
			best_shot->double_rotate--;
		}
	}
	else
	{
		while (best_shot->double_rotate)
		{
			ft_rotate_rr(list_a, list_b);
			write(1, "rr\n", 3);
			best_shot->double_rotate--;
		}
	}
}

static void		apply_rotate_b(t_push **list_a, t_push **list_b, \
														t_rotate *best_shot)
{
	if (best_shot->rotate_b < 0)
	{
		best_shot->rotate_b = (-best_shot->rotate_b);
		while (best_shot->rotate_b > 0)
		{
			ft_reverse_rotate(list_a, list_b, 1);
			write(1, "rrb\n", 4);
			best_shot->rotate_b--;
		}
	}
	else
	{
		while (best_shot->rotate_b > 0)
		{
			ft_rotate(list_a, list_b, 1);
			write(1, "rb\n", 3);
			best_shot->rotate_b--;
		}
	}
}

static void		apply_rotate_a(t_push **list_a, t_push **list_b, \
														t_rotate *best_shot)
{
	if (best_shot->rotate_a < 0)
	{
		best_shot->rotate_a = (-best_shot->rotate_a);
		while (best_shot->rotate_a > 0)
		{
			ft_reverse_rotate(list_a, list_b, 0);
			write(1, "rra\n", 4);
			best_shot->rotate_a--;
		}
	}
	else
	{
		while (best_shot->rotate_a > 0)
		{
			ft_rotate(list_a, list_b, 0);
			write(1, "ra\n", 3);
			best_shot->rotate_a--;
		}
	}
}

void			ft_resolve_ascending(t_push **list_a, t_push **list_b, \
																t_opt *opt)
{
	t_rotate	best_shot;

	prepare_sort(list_a, list_b);
	while (lenght_list(*list_a) != 0)
	{
		init_rotate(list_b);
		init_rotate(list_a);
		init_select_rotate(&best_shot);
		select_bestshot(*list_a, *list_b, &best_shot);
		if (best_shot.double_rotate != 0)
			double_rotate(list_a, list_b, &best_shot);
		if (best_shot.rotate_b < 0 || best_shot.rotate_b > 0)
			apply_rotate_b(list_a, list_b, &best_shot);
		if (best_shot.rotate_a < 0 || best_shot.rotate_a > 0)
			apply_rotate_a(list_a, list_b, &best_shot);
		push(list_a, list_b, 0);
		write(1, "pb\n", 3);
	}
	replace_big_value(list_b, list_a, opt);
}
