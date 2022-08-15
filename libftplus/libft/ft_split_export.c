/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:37:47 by coder             #+#    #+#             */
/*   Updated: 2022/03/29 16:58:55 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	allocate_first(char *str, char **newstr)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	newstr[0] = malloc(sizeof(char) * (i + 1));
	return (i);
}

void	allocate_second(char *str, char **newstr)
{
	int	j;

	j = 0;
	while (str[j])
		j++;
	newstr[1] = malloc(sizeof(char) * (j + 1));
}

int	fill_first(char *str, char **newstr)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
	{
		newstr[0][i] = str[i];
		i++;
	}
	newstr[0][i] = '\0';
	return (i);
}

void	fill_second(char *str, char **newstr)
{
	int	i;

	i = 0;
	while (str[i])
	{
		newstr[1][i] = str[i];
		i++;
	}
	newstr[1][i] = '\0';
}

char	**ft_split_export(char *str)
{
	char	**newstr;
	int		i;

	i = 0;
	newstr = malloc(sizeof(char *) * 3);
	newstr[2] = NULL;
	i = allocate_first(str, newstr);
	if (str[i] == '=')
		allocate_second(&str[i + 1], newstr);
	else
		newstr[1] = NULL;
	i = fill_first(str, newstr);
	if (newstr[1])
		fill_second(&str[i + 1], newstr);
	return (newstr);
}
