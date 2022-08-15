/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:20:25 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/30 18:36:37 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	skip_flags(const char *src, int x)
{
	char	*flags;

	flags = "0123456789+-. #";
	while (ft_strrchr_ez(flags, src[x]) == 1)
		x++;
	return (x);
}

int	check_valid(const char *src)
{
	int	x;

	x = 0;
	while (src[x] != 0)
	{
		if (src[x] == '%')
		{
			if (check_con_sf(&src[x + 1]) == -1)
				return (-1);
			else if (check_valid_flags(&src[x + 1]) == -1)
				return (-1);
			x = skip_arg(src, x + 1);
		}
		x++;
	}
	return (1);
}

int	check_valid_flags(const char *src)
{
	int	x;

	x = 0;
	x = skip_flags(src, x);
	if (src[x] == 'i' || src[x] == 'd')
		return (check_valid_id(src));
	else if (src[x] == 'c')
		return (check_valid_c(src));
	else if (src[x] == 's')
		return (check_valid_s(src));
	else if (src[x] == 'x' || src[x] == 'X')
		return (check_valid_x(src));
	else if (src[x] == 'p')
		return (check_valid_p(src));
	else if (src[x] == 'u')
		return (check_valid_u(src));
	else if (src[x] == '%')
		return (check_valid_perc(src));
	return (1);
}

int	check_con_sf(const char *src)
{
	int	x;

	x = 0;
	x = skip_flags(src, x);
	if (check_con(src[x]) == 0)
		return (-1);
	return (1);
}

int	skip_arg(const char *src, int x)
{
	char	*flags;

	flags = "0123456789+-. #";
	while (ft_strrchr_ez(flags, src[x]) == 1)
		x++;
	return (x);
}
