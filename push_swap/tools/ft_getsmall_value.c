/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsmall_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:16:43 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/02 17:51:29 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


int			ft_getsmall_value(t_push *list)
{
	int		data;
	
	data = list->value;
	while (list)
	{
		if (data > list->value)
			data = list->value;
		list = list->next;
	}
	return (data);
}

int			ft_getbig_value(t_push *list)
{
	int		data;
	
	data = list->value;
	while (list)
	{
		if (data < list->value)
			data = list->value;
		list = list->next;
	}
	return (data);
}

t_push		*dupliq(t_push *list)
{
	t_push		*new_list;

	new_list = NULL;
	while (list)
	{
		push_back(&new_list, list->value);
		list = list->next;
	}
	return (new_list);
}
