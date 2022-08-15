/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:21:02 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/30 18:52:43 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_width(const char *src)
{
	int	width;

	width = 0;
	while (check_con(*src) == 0 && *(src) != '.')
	{
		width += *src - 48;
		if (check_con(*(src + 1)) == 0 && *(src + 1) != '.')
			width = width * 10;
		src++;
	}
	return (width);
}

t_instr	*check_first_flags(const char src, t_instr *instr)
{
	if (src == '-')
		instr->flag_minus = 1;
	if (src == '+')
		instr->flag_plus = 1;
	if (src == '0')
		instr->flag_0 = 1;
	if (src == ' ')
		instr->flag_space = 1;
	if (src == '#')
		instr->flag_hash = 1;
	return (instr);
}

t_instr	*flag_check(const char *src, t_instr *instr)
{
	int	x;

	x = 0;
	initialise(instr);
	while (check_con(src[x]) == 0)
	{
		instr = check_first_flags(src[x], instr);
		if (src[x] > 48 && src[x] < 58)
		{
			instr->min_width = get_width(&src[x]);
			while (src[x] > 47 && src[x] < 58)
				x++;
		}
		if (check_con(src[x]) == 1)
			return (instr);
		if (src[x] == '.')
		{
			instr->flag_dot = 1;
			instr->precision = get_width(&src[x + 1]);
			while (src[x + 1] > 47 && src[x + 1] < 58)
				x++;
		}
		x++;
	}
	return (instr);
}

void	initialise(t_instr	*instr)
{
	instr->precision = 0;
	instr->length = 0;
	instr->min_width = 0;
	instr->flag_minus = 0;
	instr->flag_0 = 0;
	instr->flag_hash = 0;
	instr->flag_space = 0;
	instr->flag_plus = 0;
	instr->flag_dot = 0;
	instr->neg = 0;
}

int	check_con(const char src)
{
	char	*conversions;

	conversions = "cspdiuxX\%";
	if (ft_strrchr_ez(conversions, src) != 0)
		return (1);
	return (0);
}
