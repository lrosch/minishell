/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:07:39 by hskowron          #+#    #+#             */
/*   Updated: 2021/07/19 17:28:37 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isneedle(char *src, const char *tar, size_t len);

char	*ft_strnstr(const char *src, const char *tar, size_t len)
{
	size_t	x;
	char	*sorc;

	x = 0;
	if (ft_strlen(src) < ft_strlen(tar))
		return (NULL);
	sorc = (char *)src;
	if (tar[x] == 0)
		return (sorc);
	if (len == 0)
		return (0);
	while (sorc[x] != 0 && x < len)
	{
		if (sorc[x] == tar[0])
			if (isneedle(&sorc[x], tar, len - x) == 1)
				return (&sorc[x]);
		x++;
	}
	return (0);
}

static int	isneedle(char *src, const char *tar, size_t len)
{
	size_t	x;

	x = 0;
	while (src[x] != 0 && tar[x] != 0)
	{
		if (x == len)
			return (0);
		else
		{
			if (src[x] == tar[x])
				x++;
			else
				return (0);
		}
	}
	return (1);
}
