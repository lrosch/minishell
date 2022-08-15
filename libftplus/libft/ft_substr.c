/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:26:23 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/28 14:57:36 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	x;
	size_t	strsize;
	char	*sub;

	x = 0;
	if (start >= ft_strlen(str))
	{
		sub = malloc (1);
		if (sub == NULL)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	strsize = ft_strlen(str) - start;
	if (strsize > len)
		strsize = len;
	sub = malloc(strsize + 1);
	if (sub == NULL)
		return (NULL);
	x = start;
	ft_strlcpy (sub, (str + x), len + 1);
	return (sub);
}
