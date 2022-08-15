/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:04:48 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/30 19:17:55 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u_int(va_list arg, t_instr *instr)
{
	unsigned int	pint;
	int				dnbr;

	pint = va_arg(arg, unsigned int);
	dnbr = ft_get_digits_u(pint);
	check_min_w_prec(dnbr, instr);
	if (instr->flag_minus == 0)
	{
		if (instr->flag_0 == 1 && instr->precision == 0)
			instr->length += handle_width_int(0, instr->min_width, "0");
		else if (instr->flag_0 == 0 || instr->precision != 0)
			instr->length += handle_width_int(0, instr->min_width, " ");
	}
	if (instr->precision != 0)
		instr->length += handle_width_int(0, instr->precision, "0");
	ft_putnbr_u(pint);
	if (instr->flag_minus == 1)
		instr->length += handle_width_int(0, instr->min_width, " ");
	return (instr->length + dnbr);
}

int	print_int(va_list arg, t_instr *instr)
{
	long	pint;
	int		dnbr;

	pint = va_arg(arg, int);
	dnbr = ft_get_digits(pint);
	pint = handle_neg(pint, instr);
	check_min_w_prec(dnbr, instr);
	handle_minus(instr, 0);
	instr->length += handle_sign(instr, 0);
	if (instr->flag_minus == 0)
	{
		if (instr->flag_0 == 1 && instr->precision == 0)
			instr->length += handle_width_int(0, instr->min_width, "0");
		else if (instr->flag_0 == 0 || instr->precision != 0)
			instr->length += handle_width_int(0, instr->min_width, " ");
	}
	instr->length += handle_sign(instr, 1);
	handle_minus(instr, 1);
	if (instr->precision != 0)
		instr->length += handle_width_int(0, instr->precision, "0");
	ft_putnbr(pint);
	if (instr->flag_minus == 1)
		instr->length += handle_width_int(0, instr->min_width, " ");
	return (instr->length + dnbr);
}

int	print_str(va_list arg, t_instr *instr)
{
	char	*str;

	str = va_arg(arg, char *);
	if (instr->flag_dot == 1 && str != NULL)
	{
		str = ft_substr(str, 0, instr->precision);
		if (str == NULL)
			return (-1);
	}
	if (instr->flag_minus == 0)
		instr->length += handle_width(str, instr->min_width, " ");
	if (str == NULL)
	{
		write(1, "(null)", 6);
		instr->length += 6;
	}
	else
		write(1, str, ft_strlen(str));
	if (instr->flag_dot == 1 && str != NULL)
		free(str);
	if (instr->flag_minus == 1)
		instr->length += handle_width(str, instr->min_width, " ");
	if (str != NULL)
		instr->length += ft_strlen(str);
	return (instr->length);
}

int	print_perc(t_instr *instr)
{
	if (instr->flag_minus == 0)
	{
		if (instr->flag_0 == 1)
			instr->length += handle_width_c(instr->min_width, "0");
		else if (instr->flag_0 == 0)
			instr->length += handle_width_c(instr->min_width, " ");
	}
	write(1, "%", 1);
	if (instr->flag_minus == 1)
		instr->length += handle_width_c(instr->min_width, " ");
	return (instr->length + 1);
}

int	print_char(va_list arg, t_instr *instr)
{
	char	cprint;

	cprint = va_arg(arg, int);
	if (instr->flag_minus == 0)
		instr->length += handle_width_c(instr->min_width, " ");
	write(1, &cprint, 1);
	if (instr->flag_minus == 1)
		instr->length += handle_width_c(instr->min_width, " ");
	return (instr->length + 1);
}
