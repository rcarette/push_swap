/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:46:42 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/03 16:10:13 by rcarette         ###   ########.fr       */
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
			push(list_a, list_b, 1);
		return ;
	}
	while (lenght_list(*list_b) != 0)
	{
		init_rotate(list_b);
		data = ft_getbig_value(*list_b);
		new_link = ft_getdata_position(*list_b, data);
		if (new_link->rotate_top < new_link->rotate_bottom)
		{
			while (new_link->rotate_top--)
				ft_rotate(list_a, list_b, 1);
			push(list_a, list_b, 1);
		}
		else
		{
			while (new_link->rotate_bottom--)
				ft_reverse_rotate(list_a, list_b, 1);
			push(list_a, list_b, 1);
		}
	}
}

void			ft_resolve(t_push **list_a, t_push **list_b, int choice)
{

	int		median;
	int		last;
	int		size;

	while (1)
	{
		median = ft_get_mediane(*list_a, choice);
		size = lenght_list(*list_a);
		last = ft_getlast_elem(*list_a);
		while ((*list_a)->value != last)
		{
			if ((*list_a)->value < median)
				push(list_a, list_b, 0);
			else if ((*list_a)->value > median)
				ft_rotate(list_a, list_b, 0);
			else if ((*list_a)->value == median)
			{
				push(list_a, list_b, 0);
				ft_rotate(list_a, list_b, 1);
			}
		}
		if ((*list_a)->value == last && (*list_a)->value < median)
			push(list_a, list_b, 0);
		if ((*list_a)->value != median)
			ft_reverse_rotate(list_a, list_b, 1);
		/*if (lenght_list(*list_a) == 3 || lenght_list(*list_a) == 2)
			ft_tree_elements(list_a, list_b);*/
		if (!(is_sorted(*list_a)))
			break ;
	}
	transfer_pile(list_a, list_b);
}

void			ft_start_pushswap(t_push **list_a, t_push **list_b, t_opt *opt)
{
	int		*board;
	int		size_elements;
	
	size_elements = lenght_list(*list_a);
	board = transforms_list_to_array(*list_a);
	if (opt->descending == 1)
	{
		if (is_sorted_descending_array(board, size_elements))
			return (free(board)) ;
		free(board);
		ft_start_descending(list_a, list_b);
	}
	else if (opt->descending == 0)
	{
		if (is_sorted_ascending_array(board, size_elements))
			return (free(board));
		free(board);
		ft_start_ascending(list_a, list_b);
	}
}

int				main(int argc, const char *argv[])
{
	t_push		*list_a;
	t_push		*list_b;
	t_opt		opt;
	int			returns;
	int			i;

	init_opt(&opt);
	i = -1;
	list_a = NULL;
	list_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc > 1)
	{
		returns = get_arguments(argv, &list_a, &opt);
		if (returns == 0)
			ft_exit(&list_a);
		else if (returns == -1)
			ft_usage(&list_a);
		check_option(&opt);
	}
	ft_start_pushswap(&list_a, &list_b, &opt);
	(list_a != NULL) ? clear_list(&list_a) : 0;
	(list_b != NULL) ? clear_list(&list_b) : 0;
	return (0);
}
