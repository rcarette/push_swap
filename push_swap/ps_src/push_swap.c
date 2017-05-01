/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:46:42 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/01 14:40:45 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


void			init_rotate(t_push **list)
{
	int		size_list;
	int		rotate;
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

void			ft_tree_elements(t_push **list_a, t_push **list_b)
{
	int		big_position;
	
	big_position = ft_getbig_position(*list_a);
	if (big_position == 1)
	{
		ft_rotate(list_a, list_b, 0);
		if ((*list_a)->value > (*list_a)->next->value)
			swap_pile(list_a, 0);
	}
	else if (big_position == 2)
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
}

int				main(int argc, const char *argv[])
{
	t_push		*list_a;
	t_push		*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc > 1)
	{
		if (!get_arguments(argv, &list_a))
			ft_exit(&list_a);
	}
	if (!list_a || lenght_list(list_a) == 0)
		return (0);
	if (!(is_sorted(list_a)) && lenght_list(list_a) == 3)
		ft_tree_elements(&list_a, &list_b);
	push(&list_a, &list_b, 0);
	push(&list_a, &list_b, 0);
	init_rotate(&list_a);
	init_rotate(&list_b);
	//print_list(list_a);
	/*else if (!(is_sorted(list_a)))
		resolve(&list_a, &list_b);*/
	//print_list(list_a);
	(list_a != NULL) ? clear_list(&list_a) : 0;
	(list_b != NULL) ? clear_list(&list_b) : 0;
	return (0);
}
