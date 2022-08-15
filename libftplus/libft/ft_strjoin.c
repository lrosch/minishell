/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:45:09 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/01 19:43:44 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	x;
	size_t	s1l;
	size_t	s2l;
	char	*strc;

	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	x = 0;
	strc = malloc(sizeof(char) * (s1l + s2l + 1));
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
	*(strc + s1l + s2l) = 0;
	return (strc);
}
