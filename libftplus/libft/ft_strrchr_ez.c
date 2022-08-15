/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_ez.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:16:42 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/16 16:27:35 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchr_ez(const char *str, int tar)
{
	int	x;

	x = 0;
	if (tar == 0)
		return (-1);
	while (str[x] != 0)
	{
		if (str[x] == tar)
			return (1);
		x++;
	}
	return (0);
}
