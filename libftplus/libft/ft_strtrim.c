/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:08:45 by hskowron          #+#    #+#             */
/*   Updated: 2022/02/28 20:20:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strempt(char *str);

static int	ischar(char chr, const char *set);

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	strs;
	size_t	stend;
	size_t	strsz;
	char	*nstr;

	strs = 0;
	stend = 0;
	strsz = ft_strlen(str);
	nstr = NULL;
	while (ischar(*(str + (strsz - 1) - stend), set) == 1)
		stend++;
	while (ischar(*(str + strs), set) == 1)
		strs++;
	if (stend >= strsz)
		return (strempt(nstr));
	nstr = malloc(strsz - (strs + stend) + 1);
	if (nstr == NULL)
		return (NULL);
	ft_strlcpy ((char *)nstr, (char *)&str[strs], strsz - ((strs + stend) - 1));
	return (nstr);
}

static char	*strempt(char *str)
{
	str = malloc (1);
	if (str == NULL)
		return (NULL);
	str[0] = 0;
	return (str);
}

static int	ischar(char chr, const char *set)
{
	int		corr;
	size_t	x;

	x = 0;
	corr = 0;
	while (*(set + x) != 0)
	{
		if (*(set + x) == chr)
			corr = 1;
		x++;
	}
	return (corr);
}
