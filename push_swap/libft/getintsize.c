/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getintsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 03:01:34 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/07 09:05:12 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		getintsize(int data)
{
	char	*str;
	int		size;

	str = ft_itoa(data);
	size = ft_strlen(str);
	free(str);
	return (size);
}
