/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:32:09 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/04 21:03:23 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		ft_rotate_a(t_push **list_a)
{
	int		data;

	if (!list_a)
		return ;
	else if (lenght_list(*list_a) == 1)
		return ;
	data = (*list_a)->value;
	if_remove_list(list_a, data);
	push_back(list_a, data);
}

static void		ft_rotate_b(t_push **list_b)
{
	int		data;

	if (!list_b)
		return ;
	else if (lenght_list(*list_b) == 1)
		return ;
	data = (*list_b)->value;
	if_remove_list(list_b, data);
	push_back(list_b, data);
}

void			ft_rotate_rr(t_push **list_a, t_push **list_b)
{
	ft_rotate_a(list_a);
	ft_rotate_b(list_b);
}

void			ft_rotate(t_push **list_a, t_push **list_b, int choice)
{
	if (choice == 0)
		ft_rotate_a(list_a);
	else
		ft_rotate_b(list_b);
}
