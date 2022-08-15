/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:40:01 by hskowron          #+#    #+#             */
/*   Updated: 2022/02/28 20:33:00 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
