/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_flags_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:48:41 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/24 16:09:22 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_valid_u(const char *src)
{
	char	*valid_flags;

	valid_flags = "-0.123456789";
	while (check_con(*src) == 0)
	{
		if (ft_strrchr_ez(valid_flags, *src) == 0)
			return (-1);
		src++;
	}
	return (1);
}

int	check_valid_perc(const char *src)
{
	char	*valid_flags;

	valid_flags = "-0. #+123456789";
	while (check_con(*src) == 0)
	{
		if (ft_strrchr_ez(valid_flags, *src) == 0)
			return (-1);
		src++;
	}
	return (1);
}
