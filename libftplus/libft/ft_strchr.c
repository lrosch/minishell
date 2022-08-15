/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:50:22 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/10 14:16:15 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int tar)
{
	size_t	x;
	char	*sorc;

	sorc = (char *)src;
	x = 0;
	while (src[x] != 0)
	{
		if (src[x] == (char)tar)
			return (&sorc[x]);
		x++;
	}
	if (src[x] == (char)tar)
		return (&sorc[x]);
	return (NULL);
}
