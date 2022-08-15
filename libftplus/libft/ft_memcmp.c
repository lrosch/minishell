/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:50:58 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/10 14:15:30 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	size_t			x;
	unsigned char	*stri1;
	unsigned char	*stri2;

	stri1 = (unsigned char *)str1;
	stri2 = (unsigned char *)str2;
	x = 0;
	while (1)
	{
		if (x == len)
			return (0);
		if (stri1[x] != stri2[x])
			return (stri1[x] - stri2[x]);
		x++;
	}
	return (stri1[x] - stri2[x]);
}
