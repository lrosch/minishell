/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:39:39 by hskowron          #+#    #+#             */
/*   Updated: 2021/11/15 12:43:11 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	int		x;
	int		negativ;
	long	ret;

	x = 0;
	negativ = 0;
	ret = 0;
	while (str[x] == 32 || (str[x] > 8 && str[x] < 14))
	{
		x++;
	}
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			negativ++;
		x++;
	}
	while (str[x] > 47 && str[x] < 58 && str[x] != 0)
	{
		ret = (ret * 10) + (str[x] - 48);
		x++;
	}
	if (negativ == 1)
		ret = ret * -1;
	return (ret);
}
