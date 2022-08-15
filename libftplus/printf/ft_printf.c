/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:48:06 by hskowron          #+#    #+#             */
/*   Updated: 2021/10/20 16:00:58 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	con_decider(const char src, va_list arg, t_instr *instr)
{
	if (src == 's')
		return (print_str(arg, instr));
	if (src == 'c')
		return (print_char(arg, instr));
	if (src == 'p')
		return (print_ptr(arg, instr));
	if (src == 'd' || src == 'i')
		return (print_int(arg, instr));
	if (src == 'x')
		return (print_hex(arg, instr, 0));
	if (src == 'X')
		return (print_hex(arg, instr, 1));
	if (src == '%')
		return (print_perc(instr));
	if (src == 'u')
		return (print_u_int(arg, instr));
	return (0);
}

int	print_all(t_instr *instr, const char *src, va_list arg)
{
	int	wlen;
	int	x;

	wlen = 0;
	x = 0;
	while (src[x] != 0)
	{
		if (src[x] == '%')
		{
			instr = flag_check(&src[x + 1], instr);
			if (instr->flag_0 == 1 && instr->flag_minus == 1)
				instr->flag_0 = 0;
			wlen += (con_decider(src[skip_flags(src, x + 1)], arg, instr));
			x = skip_arg(src, x + 1);
		}	
		else
		{
			write(1, &src[x], 1);
			wlen++;
		}
		x++;
	}
	return (wlen);
}

int	ft_printf(const char *src, ...)
{
	va_list	arg;
	t_instr	*instr;
	int		wlen;

	wlen = 0;
	if (check_valid(src) == -1)
		return (-1);
	instr = malloc(sizeof(t_instr));
	if (instr == NULL)
		return (-1);
	va_start(arg, src);
	wlen = print_all(instr, src, arg);
	free(instr);
	va_end(arg);
	return (wlen);
}
