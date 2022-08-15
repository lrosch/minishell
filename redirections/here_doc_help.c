/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:09:13 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/31 12:17:58 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*append_onto_old(char *line, char *input, t_data *data, int mode)
{
	int		x;
	int		y;
	char	*ret;

	x = 0;
	ret = malloc(sizeof(char) * (get_new_len(line, input, data, mode) + 2));
	y = fill_already_existing(input, ret);
	while (line[x])
	{
		if (line[x] == '$' && is_valid_char(line[x + 1]) == 1 && mode == 0)
		{
			y += exchange_var(&ret[y], get_var_name(&line[x + 1],
						0, data), data);
			x++;
			x += skip_var(&line[x]);
		}
		else
		{
			ret[y] = line[x];
			x++;
			y++;
		}
	}
	return (return_term_nl(ret, y));
}

int	skip_var(char *line)
{
	int	x;

	x = 0;
	if (line[x] == '?' && is_valid_char(line[x + 1]) == 0)
		return (1);
	while (is_valid_char(line[x]) == 1 && line[x])
		x++;
	return (x);
}

char	*return_term_nl(char *ret, int y)
{
	ret[y] = '\n';
	ret[y + 1] = '\0';
	return (ret);
}

int	fill_already_existing(char *input, char *ret)
{
	int	x;

	x = 0;
	if (input)
	{
		while (input[x])
		{
			ret[x] = input[x];
			x++;
		}
	}
	return (x);
}

int	get_new_len(char *line, char *input, t_data *data, int mode)
{
	int	x;
	int	len;

	x = 0;
	len = ft_strlen(input);
	while (line[x])
	{
		if (line[x] == '$' && is_valid_char(line[x + 1]) == 1 && mode == 0)
		{
			len += get_env_len(&line[x], 0, data);
			x++;
			while (is_valid_char(line[x]) == 1 && line[x])
				x++;
		}
		else
		{
			len++;
			x++;
		}
	}
	return (len);
}
