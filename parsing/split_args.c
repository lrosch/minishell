/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:15:57 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/29 11:05:37 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_part_len(char *line, int qf, t_data *data)
{
	int	ret;
	int	x;

	x = 0;
	ret = 0;
	while (line[x])
	{
		qf = set_qf(&line[x], qf);
		while ((line[0] == '<' || line[0] == '>')
			&& x < 2 && line[x] == line[0])
			x++;
		if (((line[x] == '<' || line[x] == '>') || line[x] == ' ') && qf == 0)
			return (ret);
		if (line[x] == '$' && is_valid_char(line[x + 1]) == 1
			&& qf != 1)
		{
			ret += get_env_len(&line[x], qf, data);
			x += skip_var(&line[x]);
		}
		x++;
		ret++;
	}
	return (ret);
}

int	get_nmb_parts(char *line, int quote_flag)
{
	int	x;
	int	ret;

	x = 0;
	ret = 1;
	while (line[x])
	{
		quote_flag = set_qf(&line[x], quote_flag);
		if (line[x] == ' ' || ((line[x] == '<' || line[x] == '>')
				&& line[x - 1] != ' '))
		{
			if (quote_flag == 0 && line[x + 1] != '\0' && x > 0)
				ret++;
		}
		if (line[x] == '<' || line[x] == '>')
		{
			if (line[x + 1] == line[x])
				x++;
		}
		x++;
	}
	return (ret);
}

char	**ft_split_args(char *line, t_data *data)
{
	int		x;
	int		y;
	char	**sp_line;
	int		quote_flag;
	int		nmb_parts;

	x = 0;
	y = 0;
	quote_flag = 0;
	nmb_parts = get_nmb_parts(line, quote_flag);
	sp_line = malloc(sizeof(char *) * (nmb_parts + 1));
	if (!sp_line)
		err_exit("memory allocation failed", 1, data);
	while (nmb_parts > y)
	{
		sp_line[y] = malloc(sizeof(char)
				* (get_part_len(&line[x], quote_flag, data) + 1));
		if (!sp_line[y])
			err_exit("memory allocation failed", 1, data);
		x += fill_full_part(&line[x], sp_line[y], quote_flag, data);
		y++;
	}
	sp_line[y] = NULL;
	return (sp_line);
}

int	skip_unwanted_whitespace(char *line, int quote_flag)
{
	int	x;
	int	ret;

	x = 0;
	ret = 1;
	while (quote_flag == 0 && (((line[x] > 8 && line[x] < 14) || line[x] == 32))
		&& ((line[x + 1] > 8 && line[x + 1] < 14) || line[x + 1] == 32))
	{
		ret++;
		x++;
	}
	return (ret);
}
