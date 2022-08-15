/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:01:42 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/29 12:40:20 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	quote_decider(char *str, int start)
{
	static int	closed_flag;

	if (start == 0)
		closed_flag = 0;
	if (closed_flag == 0)
	{
		if (str[0] == '\'')
			closed_flag = check_closed_quote(str, '\'');
		if (str[0] == '"')
			closed_flag = check_closed_quote(str, '"');
		if (closed_flag != 0)
			return (0);
	}
	else
	{
		if ((str[0] == '\'' && closed_flag == 1)
			|| (str[0] == '"' && closed_flag == 2))
		{
			if (start != 0)
				closed_flag = 0;
			return (0);
		}
	}
	return (1);
}

void	cpy(char *line, char *dest, int *x, int *y)
{
	if ((line[*x] == '<' || line[*x] == '>') && line[*x + 1] == line[*x])
	{
		dest[*y] = line[*x];
		dest[*y + 1] = line[*x + 1];
		*x = *x + 2;
		*y = *y + 2;
	}
	else
	{
		dest[*y] = line[*x];
		*x = *x + 1;
		*y = *y + 1;
	}
}

int	fill_exit_val(char *dest)
{
	int		x;
	char	*value;

	x = 0;
	value = ft_itoa(g_flag.exit_val);
	while (value[x])
	{
		dest[x] = value[x];
		x++;
	}
	free(value);
	return (x);
}

int	initial_pipe_check(char *line)
{
	int	x;
	int	flag;
	int	quote_flag;

	x = 0;
	flag = 0;
	quote_flag = 0;
	while (line[x])
	{
		quote_flag = set_qf(&line[x], quote_flag);
		if (flag == 0 && quote_flag == 0)
		{
			x += skip_whitespace_pipe_check(&line[x], quote_flag);
			if (line[x] == '|' || line[x] == '\0')
				return (err_pipe());
			else
				flag = 1;
		}
		flag = initial_pipe_check_help(&line[x], flag);
		if (flag == 2)
			return (1);
		x++;
	}
	return (0);
}

int	initial_pipe_check_help(char *line, int flag)
{
	if (line[0] == '|' && flag == 1)
	{
		if (!line[1])
		{
			err_pipe();
			return (2);
		}
		return (0);
	}
	return (flag);
}
