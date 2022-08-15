/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:39:11 by hskowron          #+#    #+#             */
/*   Updated: 2021/10/20 15:32:13 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_instr
{
	int	length;
	int	precision;
	int	min_width;
	int	flag_minus;
	int	flag_0;
	int	flag_hash;
	int	flag_space;
	int	flag_plus;
	int	flag_dot;
	int	neg;
}			t_instr;

int		ft_printf(const char *src, ...);
int		con_decider(const char src, va_list arg, t_instr *instr);
int		skip_flags(const char *src, int x);
int		check_valid(const char *src);
int		check_valid_flags(const char *src);
int		check_con_sf(const char *src);
int		skip_arg(const char *src, int x);
int		check_valid_id(const char *src);
int		check_valid_c(const char *src);
int		check_valid_s(const char *src);
int		check_valid_x(const char *src);
int		check_valid_p(const char *src);
int		check_valid_u(const char *src);
int		check_valid_perc(const char *src);
int		get_width(const char *src);
t_instr	*check_first_flags(const char src, t_instr *instr);
t_instr	*flag_check(const char *src, t_instr *instr);
void	initialise(t_instr	*instr);
int		check_con(const char src);
void	check_min_w_prec(int dnbr, t_instr *instr);
int		handle_sign(t_instr *instr, int pos);
int		handle_width_int(int dnbr, int width, char *zorsp);
int		handle_width_c(int width, char *zorsp);
int		handle_width(char *str, int width, char *zorsp);
int		handle_hash(int lettcase);
int		print_hex(va_list arg, t_instr *instr, int lettcase);
int		print_ptr(va_list arg, t_instr *instr);
int		print_hex_w_hash(int pint, int dnbr, int lettcase, t_instr *instr);
int		print_u_int(va_list arg, t_instr *instr);
int		print_int(va_list arg, t_instr *instr);
int		print_str(va_list arg, t_instr *instr);
int		print_perc(t_instr *instr);
int		print_char(va_list arg, t_instr *instr);
int		print_all(t_instr *instr, const char *src, va_list arg);
long	handle_neg(long pint, t_instr *instr);
int		handle_minus(t_instr *instr, int pos);
int		handle_base(t_instr *instr, int pos);

#endif