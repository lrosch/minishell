/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:07:17 by hskowron          #+#    #+#             */
/*   Updated: 2021/07/13 15:01:51 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	x;
	size_t	y;
	char	*dest;
	char	*sorc;

	dest = (char *)dst;
	sorc = (char *)src;
	x = 0;
	if (len == 0)
		return (dest);
	while (dest[x] != 0 && sorc[x] != 0 && x < len)
	{
		dest[x] = sorc[x];
		x++;
	}
	y = x;
	while (sorc[x] == 0 && y < len)
	{
		dest[y] = 0;
		y++;
	}
	return (dest);
}
