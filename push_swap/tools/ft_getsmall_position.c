/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsmall_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 14:23:35 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/02 17:49:46 by rcarette         ###   ########.fr       */
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
