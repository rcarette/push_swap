/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:05:26 by rcarette          #+#    #+#             */
/*   Updated: 2017/04/30 17:13:26 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		push_b(t_push **list_a, t_push **list_b)
{
	int		data;

	if (!list_a || !list_b || lenght_list(*list_a) == 0)
		return ;
	data = (*list_a)->value;
	push_front(list_b, data);
	write(1, "pb\n", 3);
	if_remove_list(list_a, data);
}

static void		push_a(t_push **list_b, t_push **list_a)
{
	int		data;

	if (!list_b || !list_a || lenght_list(*list_b) == 0)
		return ;
	data = (*list_b)->value;
	push_front(list_a, data);
	write(1, "pa\n", 3);
	if_remove_list(list_b, data);
}

void	push(t_push **list_a, t_push **list_b, int choice)
{
	if (choice == 0)
		push_b(list_a, list_b);
	else
		push_a(list_b, list_a);
}
