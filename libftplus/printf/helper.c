/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:53:32 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/30 19:44:00 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_min_w_prec(int dnbr, t_instr *instr)
{
	if (instr->flag_plus == 1 || instr->flag_space == 1)
		instr->min_width--;
	if (instr->precision != 0)
	{
		if (dnbr >= instr->precision)
			instr->precision = 0;
		else
			instr->precision -= dnbr;
	}
	if (instr->min_width <= instr->precision || instr->min_width <= dnbr)
		instr->min_width = 0;
	else
		instr->min_width -= dnbr + instr->precision;
}

long	handle_neg(long pint, t_instr *instr)
{
	if (pint < 0)
	{
		instr->neg = 1;
		pint = pint * -1;
		if (instr->precision != 0)
			instr->precision++;
	}
	return (pint);
}

int	handle_minus(t_instr *instr, int pos)
{
	if (instr->neg == 0)
		return (0);
	if (instr->flag_0 == 1 && pos == 0 && instr->precision == 0)
		write(1, "-", 1);
	else if (instr->precision != 0 && pos == 1)
		write(1, "-", 1);
	else if (instr->flag_minus == 1 && pos == 1)
		write(1, "-", 1);
	else if (instr->min_width == 0 && instr->precision == 0 && pos == 1)
	{
		if (instr->flag_0 == 0)
			write(1, "-", 1);
	}
	else if (instr->min_width != 0 && instr->precision == 0 && pos == 1)
		if (instr->flag_0 == 0)
			write(1, "-", 1);
	return (0);
}

int	handle_base(t_instr *instr, int pos)
{
	if (pos == 1 && instr->flag_dot == 1 && instr->min_width == 0)
	{
		if (instr->flag_0 == 0)
			return (1);
	}
	else if (instr->flag_0 == 0 && instr->flag_dot == 0)
		if (instr->flag_minus == 0 && instr->min_width == 0)
			if (pos == 1)
				return (1);
	return (0);
}
