/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:34:22 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/10 14:15:26 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int tar, size_t len)
{
	size_t			x;
	unsigned char	*sorc;

	x = 0;
	sorc = (unsigned char *)src;
	while (x < len)
	{
		if (sorc[x] == (unsigned char)tar)
			return ((unsigned char *)&sorc[x]);
		x++;
	}
	return (NULL);
}
