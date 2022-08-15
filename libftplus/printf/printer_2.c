/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:05:53 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/24 17:06:06 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(va_list arg, t_instr *instr, int lettcase)
{
	unsigned int	pint;
	int				dnbr;

	pint = va_arg(arg, unsigned int);
	dnbr = ft_get_dig_hex(pint);
	check_min_w_prec(dnbr, instr);
	if (instr->flag_hash == 1 && pint != 0)
		return (print_hex_w_hash(pint, dnbr, lettcase, instr));
	if (instr->flag_minus == 0)
	{
		if (instr->flag_0 == 1 && instr->precision == 0)
			instr->length += handle_width_int(0, instr->min_width, "0");
		else if (instr->flag_0 == 0 || instr->precision != 0)
			instr->length += handle_width_int(0, instr->min_width, " ");
	}
	if (instr->precision != 0)
		instr->length += handle_width_int(0, instr->precision, "0");
	ft_putnbr_ihex(pint, lettcase);
	if (instr->flag_minus == 1)
		instr->length += handle_width_int(0, instr->min_width, " ");
	return (instr->length + dnbr);
}

int	print_ptr(va_list arg, t_instr *instr)
{
	unsigned long	ptr;
	int				dnbr;

	ptr = va_arg(arg, unsigned long);
	dnbr = ft_get_dig_hex(ptr);
	if (instr->flag_minus == 0)
	{
		instr->length += handle_width_int(dnbr + 2, instr->min_width, " ");
	}
	ft_putchar('0');
	ft_putchar('x');
	ft_putnbr_lhex(ptr);
	if (instr->flag_minus == 1)
		instr->length += handle_width_int(dnbr + 2, instr->min_width, " ");
	return (instr->length + dnbr + 2);
}

int	print_hex_w_hash(int pint, int dnbr, int lettcase, t_instr *instr)
{
	if (instr->flag_minus == 0)
	{
		if (instr->flag_0 == 1 && instr->precision == 0)
			instr->length += handle_width_int(2, instr->min_width, "0");
		else if (instr->flag_0 == 0 || instr->precision != 0)
			instr->length += handle_width_int(2, instr->min_width, " ");
	}
	if (instr->precision != 0)
	{
		instr->length += handle_hash(lettcase);
		instr->length += handle_width_int(2, instr->precision, "0");
	}
	ft_putchar('0');
	if (lettcase == 0)
		ft_putchar('x');
	else
		ft_putchar('X');
	ft_putnbr_ihex(pint, lettcase);
	if (instr->flag_minus == 1)
		instr->length += handle_width_int(2, instr->min_width, " ");
	return (instr->length + dnbr + 2);
}
