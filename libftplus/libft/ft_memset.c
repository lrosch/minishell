/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:07:24 by hskowron          #+#    #+#             */
/*   Updated: 2021/07/16 17:20:02 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int rep, size_t len)
{
	size_t			x;
	unsigned char	*dest;

	dest = (unsigned char *)dst;
	x = 0;
	if (len == 0)
		return (dest);
	while (x < len)
	{
		dest[x] = rep;
		x++;
	}
	return (dest);
}
