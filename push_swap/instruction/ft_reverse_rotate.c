/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:47:50 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 12:23:18 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		ft_reverse_rotate_a(t_push **list_a)
{
	t_push		*temporary;
	int			data;

	temporary = *list_a;
	if (!*list_a)
		return ;
	while (temporary->next)
		temporary = temporary->next;
	data = temporary->value;
	if_remove_list(list_a, data);
	push_front(list_a, data);
}

static void		ft_reverse_rotate_b(t_push **list_b)
{
	t_push		*temporary;
	int			data;

	temporary = *list_b;
	if (!*list_b)
		return ;
	while (temporary->next)
		temporary = temporary->next;
	data = temporary->value;
	if_remove_list(list_b, data);
	push_front(list_b, data);
}

void			ft_reverse_rotate_rrr(t_push **list_a, t_push **list_b)
{
	ft_reverse_rotate_a(list_a);
	ft_reverse_rotate_b(list_b);
}

void			ft_reverse_rotate(t_push **list_a, t_push **list_b, int choice)
{
	if (choice == 0)
		ft_reverse_rotate_a(list_a);
	else
		ft_reverse_rotate_b(list_b);
}
