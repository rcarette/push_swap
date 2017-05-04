/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_ascending.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:31:52 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/05 00:09:52 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		ft_pos_max_asen(t_push **list_a, t_push **list_b, int pos_max)
{
	if (pos_max == 1)
	{
		ft_rotate(list_a, list_b, 0);
		write(1, "ra\n", 3);
		if ((*list_a)->value > (*list_a)->next->value)
		{
			swap_pile(list_a);
			write(1, "sa\n", 3);
		}
	}
	else if (pos_max == 2)
	{
		ft_reverse_rotate(list_a, list_b, 0);
		write(1, "rra\n", 4);
		if ((*list_a)->value > (*list_a)->next->value)
		{
			swap_pile(list_a);
			write(1, "sa\n", 3);
		}
	}
}

void			ft_tree_elements_ascending(t_push **list_a, t_push **list_b)
{
	int		max_value;
	int		*board;
	int		pos_max;

	board = transforms_list_to_array(*list_a);
	max_value = returns_big_value_array(board, lenght_list(*list_a));
	pos_max = returns_pos_array(board, lenght_list(*list_a), max_value);
	if (pos_max == 1 || pos_max == 2)
		ft_pos_max_asen(list_a, list_b, pos_max);
	else
	{
		if ((*list_a)->value > (*list_a)->next->value)
		{
			swap_pile(list_a);
			write(1, "sa\n", 3);
		}
	}
	free(board);
}

void			stock_two_small_value(t_push **list_a, t_push **list_b)
{
	int		min_value;
	int		pos;
	int		*board;

	board = transforms_list_to_array(*list_a);
	min_value = returns_small_value_array(board, lenght_list(*list_a));
	pos = returns_pos_array(board, lenght_list(*list_a), min_value);
	free(board);
	if (pos == 4 || pos == 5)
	{
		ft_reverse_rotate(list_a, list_b, 0);
		write(1, "rra\n", 4);
		if (pos == 4 && lenght_list(*list_a) == 5)
			ft_reverse_rotate(list_a, list_b, 0);
		(pos == 4 && lenght_list(*list_a) == 5) ? write(1, "rra\n", 4) : 0;
	}
	else if (pos == 3 || pos == 2)
	{
		write(1, "ra\n", 3);
		ft_rotate(list_a, list_b, 0);
		(pos == 3) ? ft_rotate(list_a, list_b, 0) : 0;
		(pos == 3) ? write(1, "ra\n", 3) : 0;
	}
	push(list_a, list_b, 0);
	write(1, "pb\n", 3);
}

void			ft_five_elements_ascending(t_push **list_a, t_push **list_b)
{
	int		i;

	i = 2;
	stock_two_small_value(list_a, list_b);
	stock_two_small_value(list_a, list_b);
	ft_tree_elements_ascending(list_a, list_b);
	while (i--)
	{
		push(list_a, list_b, 1);
		write(1, "pa\n", 3);
	}
}

void			ft_start_ascending(t_push **list_a, t_push **list_b)
{
	int		choice;

	if (lenght_list(*list_a) == 3 || lenght_list(*list_a) == 2)
		ft_tree_elements_ascending(list_a, list_b);
	else if (lenght_list(*list_a) == 4 || lenght_list(*list_a) == 5)
		ft_five_elements_ascending(list_a, list_b);
	else
	{
		choice = (lenght_list(*list_a) > 150) ? 2 : 1;
		ft_resolve_ascending(list_a, list_b, choice);
	}
}
