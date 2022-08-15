/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:07:04 by hskowron          #+#    #+#             */
/*   Updated: 2021/07/13 15:37:52 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *dest, size_t len)
{
	size_t	x;
	char	*dst;

	dst = (char *)dest;
	x = 0;
	if (len != 0)
	{
		while (x < len)
		{
			dst[x] = '\0';
			x++;
		}
	}
	return (dst);
}
