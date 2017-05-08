/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 12:32:48 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 12:33:54 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		check_data(const char *str)
{
	int			ite;
	long long	data;

	ite = -1;
	ite += (str[0] == '-') ? 1 : 0;
	ite += (str[0] == '+') ? 1 : 0;
	while (str[++ite])
		if (!(ft_isdigit(str[ite])))
			return (0);
	data = ft_atoi(str);
	if (data < MIN_INT || data > MAX_INT)
		return (0);
	return (1);
}

int		check_data_list(t_push *list, int data)
{
	if (lenght_list(list) == 0)
		return (1);
	while (list)
	{
		if (list->value == data)
			return (0);
		list = list->next;
	}
	return (1);
}
