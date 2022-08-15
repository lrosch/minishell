/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:57:01 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/07 17:59:10 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	size_t	x;
	size_t	strl;
	char	buf;

	x = 0;
	strl = ft_strlen (str);
	while (x < strl / 2)
	{
		buf = str[x];
		str[x] = str[strl - x - 1];
		str[strl - x - 1] = buf;
		x++;
	}
}
