/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_in_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:45:29 by rcarette          #+#    #+#             */
/*   Updated: 2017/04/30 17:36:10 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		is_sorted(t_push *list_a)
{
	int		data;

	if (lenght_list(list_a) == 0)
		return (0);
	else if (lenght_list(list_a) == 1)
		return (1);
	while (list_a->next)
	{
		data = list_a->value;
		list_a = list_a->next;
		if (data > list_a->value)
			return (0);
	}
	return (1);
}
