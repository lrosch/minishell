/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:04:53 by hskowron          #+#    #+#             */
/*   Updated: 2022/02/28 20:22:11 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*freeall(char **nstr);

static void	fill_2d(char **nstr, const char *s, char c);

static char	**alloc_2d(const char *s, char c, char **nstr);

static void	alloc_part(const char *s, char c, int parts, char **nstr);

char	**ft_split(char const *s, char c)
{
	char	**nstr;

	nstr = NULL;
	if (!s)
		return (NULL);
	nstr = check_for_empty(s);
	if (nstr == NULL)
	{
		nstr = alloc_2d (s, c, nstr);
		if (nstr == 0)
			return (NULL);
		fill_2d (nstr, s, c);
	}
	return (nstr);
}

static void	fill_2d(char **nstr, char const *s, char c)
{
	int		x;
	int		z;
	int		y;

	x = 0;
	z = 0;
	y = 0;
	while (s[x])
	{
		if (s[x] != 0)
		{
			y = 0;
			while (s[x] != 0 && s[x] == c)
				x++;
		}
		while (s[x] != c && s[x] != 0)
		{
			nstr[z][y] = s[x];
			x++;
			y++;
		}
		if (nstr[z] != 0)
			nstr[z][y] = '\0';
		z++;
	}
}

static char	**alloc_2d(char const *s, char c, char **nstr)
{
	int		x;
	int		parts;

	x = 0;
	parts = 0;
	while (s[x])
	{
		if (x == 0 && s[x] != c)
			parts++;
		if (s[x] == c && s[x + 1] != c && s[x + 1] != 0)
			parts++;
		x++;
	}
	nstr = malloc((parts + 1) * sizeof(char *));
	if (nstr == NULL)
		return (NULL);
	x = 0;
	while (x < parts)
	{
		nstr[x] = "buf";
		x++;
	}
	nstr[parts] = NULL;
	alloc_part (s, c, parts, nstr);
	return (nstr);
}

static void	alloc_part(char const *s, char c, int parts, char **nstr)
{
	int		x;
	int		ignore;
	int		partnb;

	x = 0;
	while (nstr[x] != 0)
		x++;
	partnb = x - parts;
	x = 0;
	while (s[x] == c && s[x] != 0)
		x++;
	ignore = x;
	while (s[x] != c && s[x] != 0)
		x++;
	if ((s[x] == c || s[x] == 0) && parts != 0)
	{
		alloc_part(&s[x], c, (parts - 1), nstr);
		nstr[partnb] = (char *)malloc ((x - ignore) + 1);
		if (nstr[partnb] == NULL)
			nstr = freeall (nstr);
	}
}

static void	*freeall(char **nstr)
{
	int		x;

	x = 0;
	while (nstr[x] != 0)
	{
		free (nstr[x]);
		x++;
	}
	free (nstr);
	return (NULL);
}
