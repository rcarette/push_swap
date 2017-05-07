/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_ascending.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:48:51 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/07 09:16:29 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			init_rotate(t_push **list)
{
	int			size_list;
	int			rotate;
	t_push		*temporary_list;

	rotate = 0;
	temporary_list = *list;
	size_list = lenght_list(*list);
	while (temporary_list)
	{
		temporary_list->rotate_top = rotate;
		temporary_list->rotate_bottom = size_list;
		temporary_list = temporary_list->next;
		++rotate;
		--size_list;
	}
}

void			prepare_sort(t_push **list_a, t_push **list_b)
{
	int		i;

	i = 2;
	while (i)
	{
		push(list_a, list_b, 0);
		write(1, "pb\n", 3);
		i--;
	}
	if ((*list_b)->value < (*list_b)->next->value)
	{
		swap_pile(list_b);
		write(1, "sb\n", 3);
	}
}

int				ft_getposition(t_push *list_b, int value)
{
	int		position;

	position = 1;
	while (list_b->next)
	{
		if ((value < list_b->value && value > list_b->next->value) || \
										(value > list_b->next->value && \
									list_b->value < list_b->next->value) || \
				(value < list_b->value && list_b->value < list_b->next->value))
			return (position);
		++position;
		list_b = list_b->next;
	}
	return (0);
}

t_push			*ft_getdata(t_push *list_b, int position)
{
	int		ite;

	ite = 0;
	while (list_b)
	{
		if (position == ite)
			return (list_b);
		ite++;
		list_b = list_b->next;
	}
	return (NULL);
}

void			check_top(t_push *rot_a, t_push *rot_b, int *min, \
														t_rotate **best_shot)
{
	int		totals;

	totals = *min;
	if (rot_a->rotate_top > rot_b->rotate_top)
		totals = rot_a->rotate_top;
	else if (rot_b->rotate_top > rot_a->rotate_top)
		totals = rot_b->rotate_top;
	else if (rot_a->rotate_top == rot_b->rotate_top)
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

void			check_bottom(t_push *rot_a, t_push *rot_b, int *min, \
														t_rotate **best_shot)
{
	int		totals;

	totals = *min;
	if (rot_a->rotate_bottom > rot_b->rotate_bottom)
		totals = rot_a->rotate_bottom;
	else if (rot_b->rotate_bottom > rot_a->rotate_bottom)
		totals = rot_b->rotate_bottom;
	else if (rot_b->rotate_bottom == rot_a->rotate_bottom)
		totals = rot_a->rotate_bottom;
	if (totals <= *min)
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

void			check_rotate(t_push *rot_a, t_push *rot_b, int *min, \
														t_rotate **best_shot)
{
	int		totals;

	totals = (rot_a->rotate_top + rot_b->rotate_bottom);
	if (totals <= *min)
	{
		(*best_shot)->rotate_a = rot_a->rotate_top;
		(*best_shot)->rotate_b = (-rot_b->rotate_bottom);
		(*best_shot)->value_a = rot_a->value;
		(*best_shot)->value_b = rot_b->value;
		*min = totals;
		(*best_shot)->status = 0;
	}
}

void			check_reverse_rotate(t_push *rot_a, t_push *rot_b, int *min, \
														t_rotate **best_shot)
{
	int		totals;

	totals = (rot_a->rotate_bottom + rot_b->rotate_top);
	if (totals <= *min)
	{
		(*best_shot)->rotate_a = (-rot_a->rotate_bottom);
		(*best_shot)->rotate_b = rot_b->rotate_top;
		(*best_shot)->value_a = rot_a->value;
		(*best_shot)->value_b = rot_b->value;
		*min = totals;
		(*best_shot)->status = 0;
	}
}

void				calcul_double_rotation(t_rotate **best_shot)
{
	if ((*best_shot)->rotate_a == (*best_shot)->rotate_b)
	{
		(*best_shot)->double_rotate = (*best_shot)->rotate_a;
		(*best_shot)->rotate_a = 0;
		(*best_shot)->rotate_b = 0;
	}
	else if ((*best_shot)->rotate_a > (*best_shot)->rotate_b)
	{
		(*best_shot)->double_rotate = (*best_shot)->rotate_b;
		(*best_shot)->rotate_a -= (*best_shot)->rotate_b;
		(*best_shot)->rotate_b = 0;
	}
	else if ((*best_shot)->rotate_b > (*best_shot)->rotate_a)
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

	min = 2147483647;
	while (list_a)
	{
		position_b = ft_getposition(list_b, list_a->value);
		rot_b = ft_getdata(list_b, position_b);
		check_top(list_a, rot_b, &min, &best_shot);
		check_bottom(list_a, rot_b, &min, &best_shot);
		check_rotate(list_a, rot_b, &min, &best_shot);
		check_reverse_rotate(list_a, rot_b, &min, &best_shot);
		list_a = list_a->next;
	}
	if (best_shot->status == 1)
		calcul_double_rotation(&best_shot);
	//printf("Minimun : %d rotate_a: %d rotate_b : %d double : %d\n", min, best_shot->rotate_a, best_shot->rotate_b, best_shot->double_rotate);
}


void			ft_resolve_ascending(t_push **list_a, t_push **list_b)
{
	t_rotate	best_shot;

	prepare_sort(list_a, list_b); //DEBUT D'ALGO !
	while (lenght_list(*list_a) != 0)
	{
		// PROGRAM PRINCIPALE
		init_rotate(list_b);
		init_rotate(list_a);
		init_select_rotate(&best_shot);
		select_bestshot(*list_a, *list_b, &best_shot);
		if (best_shot.double_rotate != 0)
		{
			if (best_shot.double_rotate < 0)
			{
				best_shot.double_rotate = (-best_shot.double_rotate);
				while (best_shot.double_rotate)
				{
					ft_reverse_rotate_rrr(list_a, list_b);
					write(1, "rrr\n", 4);
					best_shot.double_rotate--;
				}
			}
			else
			{
				while (best_shot.double_rotate)
				{
					ft_rotate_rr(list_a, list_b);
					write(1, "rr\n", 3);
					best_shot.double_rotate--;
				}
			}
		}
		if (best_shot.rotate_b < 0 || best_shot.rotate_b > 0)
		{
			if (best_shot.rotate_b < 0)
			{
				best_shot.rotate_b = (-best_shot.rotate_b);
				while (best_shot.rotate_b > 0)
				{
					ft_reverse_rotate(list_a, list_b, 1);
					write(1, "rrb\n", 4);
					best_shot.rotate_b--;
				}
			}
			else
			{
				while (best_shot.rotate_b > 0)
				{
					ft_rotate(list_a, list_b, 1);
					write(1, "rb\n", 3);
					best_shot.rotate_b--;
				}
			}
		}
		if (best_shot.rotate_a < 0 || best_shot.rotate_a > 0)
		{
			if (best_shot.rotate_a < 0)
			{
				best_shot.rotate_a = (-best_shot.rotate_a);
				while (best_shot.rotate_a > 0)
				{
					ft_reverse_rotate(list_a, list_b, 0);
					write(1, "rra\n", 4);
					best_shot.rotate_a--;
				}
			}
			else
			{
				while (best_shot.rotate_a > 0)
				{
					ft_rotate(list_a, list_b, 0);
					write(1, "ra\n", 3);
					best_shot.rotate_a--;
				}
			}
		}
		push(list_a, list_b, 0);
		write(1, "pb\n", 3);
	}
	// END ALGO !
}
