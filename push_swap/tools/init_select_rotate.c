/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_select_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 21:02:26 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/07 00:29:56 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_select_rotate(t_rotate *rotate)
{
	rotate->rotate_a = 0;
	rotate->rotate_b = 0;
	rotate->double_rotate = 0;
	rotate->status = 0;
	rotate->value_a = 0;
	rotate->value_b = 0;
}
