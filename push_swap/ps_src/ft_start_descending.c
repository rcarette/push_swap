/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_descending.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:00:53 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/03 16:53:07 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_tree_elements_descending(t_push **list_a, t_push **list_b)
{
	int		min_value;
	int		*board;
	int		pos_min;

	board = transforms_list_to_array(*list_a);
	min_value = returns_small_value_array(board, lenght_list(*list_a));
	pos_min = returns_pos_array(board, lenght_list(*list_a), min_value);
	if (pos_min == 1)
	{
		ft_rotate(list_a, list_b, 0);
		if ((*list_a)->value < (*list_a)->next->value)
			swap_pile(list_a, 0);
	}
	else if (pos_min == 2)
	{
		ft_reverse_rotate(list_a, list_b, 0);
		if ((*list_a)->value < (*list_a)->next->value)
			swap_pile(list_a, 0);
	}
	else
	{
		if ((*list_a)->value < (*list_a)->next->value)
			swap_pile(list_a, 0);
	}
	free(board);
}

void	ft_start_descending(t_push **list_a, t_push **list_b)
{
	if (lenght_list(*list_a) == 3 || lenght_list(*list_a) == 2)
			ft_tree_elements_descending(list_a, list_b);
}
