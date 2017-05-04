/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmedian.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:22:59 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/04 23:02:01 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int			ft_get_mediane(t_push *list, int choice)
{
	t_push		*temporary;
	int			i;
	int			data;
	int			median;
	int			*board;

	i = -1;
	temporary = dupliq(list);
	if (!(board = (int *)malloc(sizeof(int) * lenght_list(list))))
		exit(EXIT_FAILURE);
	while (lenght_list(temporary) != 0)
	{
		data = ft_getsmall_value(temporary);
		board[++i] = data;
		if_remove_list(&temporary, data);
	}
	(choice == 2) ? median = board[lenght_list(list) / 6] : 0;
	(choice == 1) ? median = board[lenght_list(list) / 3 % lenght_list(list)] : 0;
	free(board);
	return (median);
}
