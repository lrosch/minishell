/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:06:56 by hskowron          #+#    #+#             */
/*   Updated: 2021/11/15 12:39:25 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	x;
	int	negativ;
	int	ret;

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
