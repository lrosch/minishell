/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_no_eq.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:15:06 by coder             #+#    #+#             */
/*   Updated: 2022/03/04 14:17:04 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_no_eq(const char *src)
{
	size_t	x;
	char	*dst;

	x = 0;
	if (src == NULL)
		return (NULL);
	dst = malloc(ft_strlen(src));
	if (dst == NULL)
		return (NULL);
	if (src[x] == 0)
		dst[x] = src[x];
	while (src[x] != '\0' && src[x] != '=')
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (dst);
}
