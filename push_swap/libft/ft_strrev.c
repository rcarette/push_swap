/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 21:27:43 by rcarette          #+#    #+#             */
/*   Updated: 2017/02/04 07:24:44 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int			size;
	int			i;
	char		temporary;

	i = -1;
	size = ft_strlen(s);
	while (++i < --size)
	{
		temporary = s[size];
		s[size] = s[i];
		s[i] = temporary;
	}
	return (s);
}
