/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_ascending.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:48:51 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/05 00:49:24 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			init_rotate(t_push **list)
{
	int			size_list;
	int			rotate;
	t_push		*temporary_list;

	rotate = 0;
	temporary_list = *list;
	size_list = lenght_list(*list);
	while (temporary_list)
	{
		temporary_list->rotate_top = rotate;
		temporary_list->rotate_bottom = size_list;
		temporary_list = temporary_list->next;
		++rotate;
		--size_list;
	}
}

void			transfer_pile(t_push **list_a, t_push **list_b)
{
	int			data;
	t_push		*new_link;

	if (!(is_sorted_desc(*list_b)))
	{
		while (lenght_list(*list_b) > 0)
		{
			push(list_a, list_b, 1);
			write(1, "pa\n", 3);
		}
		return ;
	}
	while (lenght_list(*list_b) > 0)
	{
		init_rotate(list_b);
		data = ft_getbig_value(*list_b);
		new_link = ft_getdata_position(*list_b, data);
		if (new_link->rotate_top < new_link->rotate_bottom)
		{
			while (new_link->rotate_top--)
			{
				ft_rotate(list_a, list_b, 1);
				write(1, "rb\n", 3);
			}
			push(list_a, list_b, 1);
			write(1, "pa\n", 3);
		}
		else
		{
			while (new_link->rotate_bottom--)
			{
				ft_reverse_rotate(list_a, list_b, 1);
				write(1, "rrb\n", 4);
			}
			push(list_a, list_b, 1);
			write(1, "pa\n", 3);
		}
	}
}

static int		ft_getdata(int *median, int *size, t_push **list_a, int choice)
{
	int		last;

	*median = ft_get_mediane(*list_a, choice);
	*size = lenght_list(*list_a);
	last = ft_getlast_elem(*list_a);
	return (last);
}

int			check_aftermedian(t_push *list, int median)
{
	while (list)
	{
		if (list->value > median)
			return (0);
		list = list->next;
	}
	return (1);
}


void			ft_resolve_ascending(t_push **list_a, t_push **list_b, \
																int choice)
{
	int		median;
	int		last;
	int		size;

	while (1)
	{
		last = ft_getdata(&median, &size, list_a, choice);
		while ((*list_a)->value != last)
		{
			if (check_aftermedian(*list_a, median))
				break ;
			if ((*list_a)->value <= median)
			{
				push(list_a, list_b, 0);
				write(1, "pb\n", 3);
			}
			else if ((*list_a)->value > median)
			{
				ft_rotate(list_a, list_b, 0);
				write(1, "ra\n", 3);
			}
		}
		if ((*list_a)->value == last && (*list_a)->value < median)
		{
			push(list_a, list_b, 0);
			write(1, "pb\n", 3);
		}
		if (lenght_list(*list_a) == 5)
			ft_five_elements_ascending(list_a, list_b);
		if (lenght_list(*list_a) == 3 || lenght_list(*list_a) == 2)
			ft_tree_elements_ascending(list_a, list_b);
		if (!(is_sorted(*list_a)))
			break ;
	}
	transfer_pile(list_a, list_b);
	//print_list(*list_a);
}
