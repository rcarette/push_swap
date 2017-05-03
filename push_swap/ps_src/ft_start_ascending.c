/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_ascending.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:31:52 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/03 17:33:21 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_tree_elements_ascending(t_push **list_a, t_push **list_b)
{
	int		max_value;
	int		*board;
	int		pos_max;

	board = transforms_list_to_array(*list_a);
	max_value = returns_big_value_array(board, lenght_list(*list_a));
	pos_max = returns_pos_array(board, lenght_list(*list_a), max_value);
	if (pos_max == 1)
	{
		ft_rotate(list_a, list_b, 0);
		if ((*list_a)->value > (*list_a)->next->value)
			swap_pile(list_a, 0);
	}
	else if (pos_max == 2)
	{
		ft_reverse_rotate(list_a, list_b, 0);
		if ((*list_a)->value > (*list_a)->next->value)
			swap_pile(list_a, 0);
	}
	else
	{
		if ((*list_a)->value > (*list_a)->next->value)
			swap_pile(list_a, 0);
	}
	free(board);
}

void	ft_five_elements_ascending(t_push **list_a, t_push **list_b)
{
	(void)list_b;
	int		min;
	int		*board;
	board = transforms_list_to_array(*list_a);
	min = returns_small_value_array(board, lenght_list(*list_a));
	push(list_a, list_b, 0);
	board = transforms_list_to_array(*list_a);
	min = returns_small_value_array(board, lenght_list(*list_a));
	push(list_a, list_b, 0);
	print_list(*list_a);
	print_list(*list_b);
}

void	ft_start_ascending(t_push **list_a, t_push **list_b)
{
	if (lenght_list(*list_a) == 3 || lenght_list(*list_a) == 2)
		ft_tree_elements_ascending(list_a, list_b);
	else if (lenght_list(*list_a) == 5)
		ft_five_elements_ascending(list_a, list_b);
}
