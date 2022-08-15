/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:07:20 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/10 14:15:36 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	x;
	char	*dest;
	char	*sorc;

	sorc = (char *)src;
	dest = (char *)dst;
	x = 0;
	if (dst <= src)
	{
		while (x < len)
		{
			dest[x] = sorc[x];
			x++;
		}
	}
	else if (dst > src)
	{
		x = len - 1;
		while (x < len)
		{
			dest[x] = sorc[x];
			x--;
		}
	}
	return (dst);
}
