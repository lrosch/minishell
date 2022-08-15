/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:08:53 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/30 19:46:33 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_sign(t_instr *instr, int pos)
{
	int	print;

	print = 0;
	if (instr->flag_plus == 1 || instr->flag_space == 1)
	{
		print = handle_base(instr, pos);
		if (instr->neg == 1)
			return (0);
		if (pos == 0 && instr->flag_0 == 1 && instr->flag_dot == 0)
			print = 1;
		else if (pos == 1 && instr->flag_minus == 1)
			print = 1;
		else if (pos == 1 && instr->flag_0 == 1 && instr->flag_dot == 1)
			print = 1;
		else if (pos == 1 && instr->min_width != 0 && instr->flag_minus == 0)
			if (instr->flag_0 == 0)
				print = 1;
		if (instr->flag_plus == 1 && print == 1)
			if (instr->neg == 0)
				write(1, "+", 1);
		if (instr->flag_space == 1 && instr->flag_plus == 0 && print == 1)
			if (instr->neg == 0)
				write(1, " ", 1);
	}
	return (print);
}

int	handle_width_int(int dnbr, int width, char *zorsp)
{
	int	x;

	x = 0;
	if (dnbr < width)
		width -= dnbr;
	else if (dnbr >= width)
		width = 0;
	while (width > x)
	{
		write (1, zorsp, 1);
		x++;
	}
	return (width);
}

int	handle_width_c(int width, char *zorsp)
{
	int	x;

	x = 0;
	if (width == 1)
		return (0);
	if (1 < width)
		width -= 1;
	while (width > x)
	{
		write (1, zorsp, 1);
		x++;
	}
	return (width);
}

int	handle_width(char *str, int width, char *zorsp)
{
	int	len;
	int	x;

	if (str == NULL)
		len = 6;
	else
		len = ft_strlen(str);
	x = 0;
	if (len < width)
		width -= len;
	else if (len >= width)
		width = 0;
	while (width > x)
	{
		write (1, zorsp, 1);
		x++;
	}
	return (width);
}

int	handle_hash(int lettcase)
{
	if (lettcase == 0)
		write(1, "0x", 2);
	if (lettcase == 1)
		write(1, "0X", 2);
	return (2);
}
