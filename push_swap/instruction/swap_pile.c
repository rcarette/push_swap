/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_pile_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:48:32 by rcarette          #+#    #+#             */
/*   Updated: 2017/04/30 17:19:14 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		swap(int *s1, int *s2)
{
	int		temporary;


	temporary = *s1;
	*s1 = *s2;
	*s2 = temporary;
}

void			swap_pile(t_push **pile, int choice)
{
	if (!*pile)
		return ;
	else if (lenght_list(*pile) == 1)
		return ;
	swap(&(*pile)->value, &(*pile)->next->value);
	(choice == 0) ? write(1, "sa\n", 3) : write(1, "sb\n", 3);
}

void			swap_ss(t_push **pile_a, t_push **pile_b)
{
	swap_pile(pile_a, 0);
	swap_pile(pile_b, 1);
}
