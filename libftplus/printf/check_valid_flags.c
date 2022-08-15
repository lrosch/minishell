/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:43:28 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/24 17:08:34 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_valid_id(const char *src)
{
	char	*valid_flags;
	int		x;

	valid_flags = "-0. +123456789";
	x = 0;
	while (check_con(src[x]) == 0)
	{
		if (ft_strrchr_ez(valid_flags, src[x]) == 0)
			return (-1);
		x++;
	}
	return (1);
}

int	check_valid_c(const char *src)
{
	char	*valid_flags;
	int		x;

	valid_flags = "-123456789";
	x = 0;
	while (check_con(src[x]) == 0)
	{
		if (src[x] == '0')
			if (ft_strrchr_ez(valid_flags, src[x - 1]) == 1)
				while ((src[x]) == '0')
					x++;
		if (check_con(src[x]) == 1)
			break ;
		if (ft_strrchr_ez(valid_flags, src[x]) == 0)
			if (src[x] != '-')
				return (-1);
		x++;
	}
	return (1);
}

int	check_valid_s(const char *src)
{
	char	*valid_flags;
	int		x;

	valid_flags = "-. 123456789";
	x = 0;
	while (check_con(src[x]) == 0)
	{
		if (src[x] == '0')
			if (ft_strrchr_ez(valid_flags, src[x - 1]) == 1)
				while ((src[x]) == '0')
					x++;
		if (check_con(src[x]) == 1)
			break ;
		if (ft_strrchr_ez(valid_flags, src[x]) == 0)
			if (src[x] != '-')
				return (-1);
		x++;
	}
	return (1);
}

int	check_valid_x(const char *src)
{
	char	*valid_flags;
	int		x;

	valid_flags = "-0.#123456789";
	x = 0;
	while (check_con(src[x]) == 0)
	{
		if (ft_strrchr_ez(valid_flags, src[x]) == 0)
			return (-1);
		x++;
	}
	return (1);
}

int	check_valid_p(const char *src)
{
	char	*valid_flags;
	int		x;

	valid_flags = "-123456789";
	x = 0;
	while (check_con(src[x]) == 0)
	{
		if (src[x] == '0')
			if (ft_strrchr_ez(valid_flags, src[x - 1]) == 1)
				while ((src[x]) == '0')
					x++;
		if (check_con(src[x]) == 1)
			break ;
		if (ft_strrchr_ez(valid_flags, src[x]) == 0)
			if (src[x] != '-')
				return (-1);
		x++;
	}
	return (1);
}
