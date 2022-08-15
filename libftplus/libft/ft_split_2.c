/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:27:57 by hskowron          #+#    #+#             */
/*   Updated: 2022/01/29 16:31:16 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**check_for_empty(const char *str)
{
	int		x;
	char	**nstr;

	x = 0;
	while (str[x] >= 9 && str[x] <= 32)
		x++;
	if (str[x] == '\0')
	{
		nstr = malloc(sizeof(char *));
		nstr[0] = malloc(sizeof(char));
		nstr[1] = NULL;
		return (nstr);
	}
	else
		return (NULL);
}
