/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsmall_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 14:23:35 by rcarette          #+#    #+#             */
/*   Updated: 2017/04/30 18:06:21 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int				ft_getsmall_position(t_push *list_a)
{
	int		small_data;
	int		position;
	int		ite;

	position = 0;
	ite = 0;
	small_data = list_a->value;
	while (list_a)
	{
		printf("%d\n", list_a->value);
		++ite;
		if (small_data >= list_a->value)
		{
			small_data = list_a->value;
			position = ite;
		}
		list_a = list_a->next;
	}
	return (position);
}

static int		ft_getnew_position(t_push *list_a, int position)
{
	t_push		*temporary;
	int			ite;
	int			data;

	temporary = NULL;
	ite = 0;
	while (list_a)
	{
		ite++;
		if (position == ite)
		{
			data = list_a->value;
			list_a = list_a->next;
			continue ;
		}
		push_back(&temporary, list_a->value);
		list_a = list_a->next;
	}
	if_remove_list(&temporary, data);
	data = ft_getsmall_position(temporary);
	clear_list(&temporary);
	return (data);
}

int				ft_getbig_position(t_push *list_a)
{
	int		small_data;
	int		position;
	int		ite;

	position = 1;
	ite = 0;
	small_data = list_a->value;
	while (list_a)
	{
		++ite;
		if (small_data <= list_a->value)
		{
			small_data = list_a->value;
			position = ite;
		}
		list_a = list_a->next;
	}
	return (position);
}

int				ft_getbefore_last(t_push *list_a, int small_position)
{
	small_position = ft_getnew_position(list_a, small_position);
	return (small_position);
}
