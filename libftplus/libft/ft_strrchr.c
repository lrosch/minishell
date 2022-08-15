/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:07:44 by hskowron          #+#    #+#             */
/*   Updated: 2021/08/26 16:25:15 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strrchrrec(char *src, int tar, int x);

char	*ft_strrchr(const char *src, int tar)
{
	int		x;
	char	*sorc;

	sorc = (char *)src;
	x = 0;
	if (tar == 0)
		return (&sorc[ft_strlen(sorc)]);
	return (strrchrrec (sorc, (char)tar, x));
}

static char	*strrchrrec(char *src, int tar, int x)
{
	if (src[x] != 0)
	{
		if (src[x] == (char)tar)
		{
			if (strrchrrec (src, (char)tar, x + 1) == 0)
				return (&src[x]);
			else
				return (strrchrrec (src, (char)tar, x + 1));
		}
		else if (src[x + 1] != 0)
		{
			x++;
			return (strrchrrec (src, (char)tar, x));
		}
	}
	return (0);
}
