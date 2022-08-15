/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmpenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:07:35 by hskowron          #+#    #+#             */
/*   Updated: 2022/02/01 16:36:44 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmpenv(const char *s1, const char *s2, size_t len)
{
	size_t	x;

	x = 0;
	if (len == 0)
		return (0);
	while (s1[x] != 0 && s2[x] != 0 && (x + 1) < len)
	{
		if (s1[x] - s2[x] != 0)
			return (s1[x] - s2[x]);
		x++;
	}
	if (!s2[x + 1])
		return (s1[x] - s2[x]);
	return (1);
}
