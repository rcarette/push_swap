/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:54:23 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/02 17:55:40 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_push		*ft_getdata_position(t_push *list, int data)
{
	while (list)
	{
		if (list->value == data)
			return (list);
		list = list->next;
	}
	return (NULL);
}
