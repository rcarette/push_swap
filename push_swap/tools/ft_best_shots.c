/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_shots.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 11:16:38 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 11:24:42 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		check_top(t_push *rot_a, t_push *rot_b, int *min, \
														t_rotate **best_shot)
{
	int		totals;

	totals = *min;
	if (rot_a->rotate_top > rot_b->rotate_top)
		totals = rot_a->rotate_top;
	else
		totals = rot_b->rotate_top;
	if (totals < *min)
	{
		*min = totals;
		(*best_shot)->rotate_a = rot_a->rotate_top;
		(*best_shot)->rotate_b = rot_b->rotate_top;
		(*best_shot)->value_a = rot_a->value;
		(*best_shot)->value_b = rot_b->value;
		if (rot_a->rotate_top != 0 && rot_b->rotate_top != 0)
			(*best_shot)->status = (1);
	}
}

static void		check_bottom(t_push *rot_a, t_push *rot_b, int *min, \
														t_rotate **best_shot)
{
	int		totals;

	totals = *min;
	if (rot_a->rotate_bottom > rot_b->rotate_bottom)
		totals = rot_a->rotate_bottom;
	else
		totals = rot_b->rotate_bottom;
	if (totals < *min)
	{
		*min = totals;
		(*best_shot)->rotate_a = (-rot_a->rotate_bottom);
		(*best_shot)->rotate_b = (-rot_b->rotate_bottom);
		(*best_shot)->value_a = rot_a->value;
		(*best_shot)->value_b = rot_b->value;
		if (rot_a->rotate_bottom != 0 && rot_b->rotate_bottom != 0)
			(*best_shot)->status = (1);
	}
}

static void		check_rotate_reverse(t_push *rot_a, t_push *rot_b, int *min, \
														t_rotate **best_shot)
{
	int		totals;

	totals = (rot_a->rotate_top + rot_b->rotate_bottom);
	if (totals < *min)
	{
		(*best_shot)->rotate_a = rot_a->rotate_top;
		(*best_shot)->rotate_b = (-rot_b->rotate_bottom);
		(*best_shot)->value_a = rot_a->value;
		(*best_shot)->value_b = rot_b->value;
		*min = totals;
		(*best_shot)->status = 0;
	}
	totals = (rot_a->rotate_bottom + rot_b->rotate_top);
	if (totals < *min)
	{
		(*best_shot)->rotate_a = (-rot_a->rotate_bottom);
		(*best_shot)->rotate_b = rot_b->rotate_top;
		(*best_shot)->value_a = rot_a->value;
		(*best_shot)->value_b = rot_b->value;
		*min = totals;
		(*best_shot)->status = 0;
	}
}

static void		calcul_double_rotation(t_rotate **best_shot)
{
	if ((*best_shot)->rotate_a == (*best_shot)->rotate_b)
	{
		(*best_shot)->double_rotate = (*best_shot)->rotate_a;
		(*best_shot)->rotate_a = 0;
		(*best_shot)->rotate_b = 0;
	}
	else if (ABS((*best_shot)->rotate_a) > ABS((*best_shot)->rotate_b))
	{
		(*best_shot)->double_rotate = (*best_shot)->rotate_b;
		(*best_shot)->rotate_a -= (*best_shot)->rotate_b;
		(*best_shot)->rotate_b = 0;
	}
	else if (ABS((*best_shot)->rotate_b) > ABS((*best_shot)->rotate_a))
	{
		(*best_shot)->double_rotate = (*best_shot)->rotate_a;
		(*best_shot)->rotate_b -= (*best_shot)->rotate_a;
		(*best_shot)->rotate_a = 0;
	}
}

void			select_bestshot(t_push *list_a, t_push *list_b, \
														t_rotate *best_shot)
{
	int			position_b;
	t_push		*rot_b;
	int			min;

	min = MAX_INT;
	while (list_a)
	{
		position_b = ft_getposition(list_b, list_a->value);
		rot_b = ft_getdata(list_b, position_b);
		check_top(list_a, rot_b, &min, &best_shot);
		check_bottom(list_a, rot_b, &min, &best_shot);
		check_rotate_reverse(list_a, rot_b, &min, &best_shot);
		list_a = list_a->next;
	}
	if (best_shot->status == 1)
		calcul_double_rotation(&best_shot);
}
