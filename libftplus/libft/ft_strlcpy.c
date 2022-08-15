/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:07:27 by hskowron          #+#    #+#             */
/*   Updated: 2021/07/13 14:50:50 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(void *dst, const void *src, size_t len)
{
	size_t	x;
	char	*dest;
	char	*sorc;

	dest = (char *)dst;
	sorc = (char *)src;
	x = 0;
	if (len == 0)
		return (ft_strlen(src));
	while (sorc[x] != 0 && (x + 1) < len)
	{
		dest[x] = sorc[x];
		x++;
	}
	dest[x] = 0;
	return (ft_strlen(src));
}
