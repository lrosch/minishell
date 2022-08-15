/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_nl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:13:26 by hskowron          #+#    #+#             */
/*   Updated: 2022/02/15 12:56:19 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_nl(const char *src)
{
	size_t	x;
	char	*dst;

	x = 0;
	if (src == NULL)
		return (NULL);
	dst = malloc(ft_strlen(src) + 2);
	if (dst == NULL)
		return (NULL);
	if (src[x] == 0)
		dst[x] = src[x];
	while (src[x] != 0)
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\n';
	dst[x + 1] = '\0';
	return (dst);
}
