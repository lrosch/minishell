/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_only.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:19:43 by hskowron          #+#    #+#             */
/*   Updated: 2021/10/25 16:50:10 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchr_only(const char *str, int tar)
{
	int	x;

	x = 0;
	if (tar == 0)
		return (-1);
	while (str[x] != 0)
	{
		if (str[x] != tar)
			if (str[x] != '\n')
				return (0);
		x++;
	}
	return (1);
}
