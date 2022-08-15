/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:05:41 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/10 14:16:26 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{	
	size_t	x;
	size_t	dstlen;

	x = 0;
	dstlen = ft_strlen(dst);
	if (len == 0)
		return (ft_strlen(src));
	if (dstlen >= len)
		dstlen = len;
	while (src[x] != 0 && (x + 1 + dstlen) < len)
	{
		dst[dstlen + x] = src[x];
		x++;
	}
	if (dstlen < len)
		dst[dstlen + x] = 0;
	return (dstlen + ft_strlen(src));
}
