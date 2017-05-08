/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbig_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 10:29:19 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 16:14:04 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_getbig_value(t_push *list)
{
	int		*board;
	int		big_value;

	board = transforms_list_to_array(list);
	big_value = returns_big_value_array(board, lenght_list(list));
	free(board);
	return (big_value);
}

int		ft_getposition_big_value(t_push *list, int data)
{
	int		i;
	int		size_list;

	i = 0;
	size_list = lenght_list(list);
	if (list->value == data)
		return (0);
	while (list)
	{
		if (list->value == data)
		{
			if (i < (size_list / 2))
				return (i);
			else if (i > size_list / 2)
			{
				i = (-i);
				return (i);
			}
			else
				return (i);
		}
		++i;
		list = list->next;
	}
	return (i);
}
