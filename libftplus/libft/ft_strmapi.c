/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:46:36 by hskowron          #+#    #+#             */
/*   Updated: 2022/02/28 20:23:05 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*nstr;
	unsigned int	x;

	nstr = malloc (ft_strlen(s) + 1);
	x = 0;
	if (s == 0)
		return (NULL);
	if (nstr == 0)
		return (NULL);
	while (x < ft_strlen (s))
	{
		nstr[x] = (*f)(x, s[x]);
		x++;
	}
	nstr[x] = '\0';
	return (nstr);
}
