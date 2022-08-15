/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:13:26 by hskowron          #+#    #+#             */
/*   Updated: 2021/10/23 17:28:57 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	x;
	char	*dst;

	x = 0;
	if (src == NULL)
		return (NULL);
	dst = malloc(ft_strlen(src) + 1);
	if (dst == NULL)
		return (NULL);
	if (src[x] == 0)
		dst[x] = src[x];
	while (src[x] != 0)
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (dst);
}
