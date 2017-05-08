/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_informations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 11:46:57 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 11:52:15 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
