/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_nl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:10:18 by hskowron          #+#    #+#             */
/*   Updated: 2022/02/15 12:55:24 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_nl(char const *s1, char const *s2)
{
	size_t	x;
	size_t	s1l;
	size_t	s2l;
	char	*strc;

	s1l = ft_strlen (s1);
	s2l = ft_strlen (s2);
	x = 0;
	strc = malloc(sizeof(char) * (s1l + s2l + 2));
	if (strc == 0)
		return (NULL);
	while (*(s1 + x) != 0)
	{
		*(strc + x) = *(s1 + x);
		x++;
	}
	x = 0;
	while (*(s2 + x) != 0)
	{
		*(strc + x + s1l) = *(s2 + x);
		x++;
	}
	strc[s1l + s2l] = '\n';
	*(strc + s1l + s2l + 1) = '\0';
	return (strc);
}
