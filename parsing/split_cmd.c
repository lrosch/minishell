/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:04:58 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/29 10:40:13 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	split_cmd(char *line, t_data *data, int parts)
{
	int		x;
	char	**sp_line;

	x = 0;
	sp_line = ft_split_cmd(line, parts, data);
	while (sp_line[x])
	{
		init_cmd(data->cmd_lst[x], x);
		data->cmd_lst[x]->cmd = ft_split_args(sp_line[x], data);
		x++;
	}
	data->cmd_lst[x] = NULL;
	free2d(sp_line);
}

int	fill_full_part(char *line, char *dest, int qf, t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (line[x])
	{
		qf = set_qf(&line[x], qf);
		if (line[x] == '$' && qf != 1
			&& (is_valid_char(line[x + 1]) == 1 || line[x + 1] == '?'))
		{
			y += exchange_var(&dest[y], get_var_name(&line[x + 1],
						qf, data), data);
			x++;
			x += skip_var(&line[x]);
		}
		else
			cpy(line, dest, &x, &y);
		if (((line[x] == '<' || line[x] == '>') || line[x] == ' ') && qf == 0)
			return (ret_terminated(line, dest, y, x));
	}
	dest[y] = '\0';
	return (x);
}

char	**ft_split_cmd(char *line, int parts, t_data *data)
{
	int		x;
	int		y;
	char	**sp_line;
	int		quote_flag;

	x = 0;
	y = 0;
	quote_flag = 0;
	if (!line)
		err_exit("input line corrupted", 0, data);
	sp_line = malloc(sizeof(char *) * (parts + 1));
	if (!sp_line)
		err_exit("allocation error", 1, data);
	while (parts > y)
	{
		sp_line[y] = malloc(sizeof(char)
				* (get_full_cmd_len(&line[x], quote_flag) + 1));
		if (!sp_line[y])
			err_exit("memory allocation failed", 1, data);
		x += fill_full_cmd(&line[x], sp_line[y], quote_flag);
		y++;
	}
	sp_line[y] = NULL;
	return (sp_line);
}

int	fill_full_cmd(char *line, char *dest, int quote_flag)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while ((line[x] > 8 && line[x] < 14) || line[x] == 32)
		x++;
	while (line[x])
	{
		quote_flag = set_qf(&line[x], quote_flag);
		if (line[x] == '|' && quote_flag == 0)
		{
			dest[y] = '\0';
			return (x + 1);
		}
		dest[y] = line[x];
		x += skip_unwanted_whitespace(&line[x], quote_flag);
		y++;
	}
	dest[y] = '\0';
	return (x);
}

int	get_full_cmd_len(char *line, int quote_flag)
{
	int	ret;
	int	x;

	ret = 0;
	x = 0;
	while (line[x] > 8 && line[x] < 33)
		x++;
	while (line[x])
	{
		quote_flag = set_qf(&line[x], quote_flag);
		if (line[x] == '|' && quote_flag == 0)
			return (ret);
		x += skip_unwanted_whitespace(&line[x], quote_flag);
		ret++;
	}
	return (ret);
}
