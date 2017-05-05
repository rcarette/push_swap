/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:22:25 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/05 03:42:56 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			init_opt(t_opt *opt)
{
	opt->descending = 0;
	opt->instruc = 0;
	opt->time = 0;
	opt->visualization = 0;
	opt->time_opt = 1;
}
