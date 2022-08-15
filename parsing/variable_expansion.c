/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:14:00 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/29 10:40:24 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_env_len(char *line, int quote_flag, t_data *data)
{
	char	*var_name;
	char	*var_value;
	int		ret;

	var_name = get_var_name(&line[1], quote_flag, data);
	if (!var_name)
		err_exit("var_name corrupted", 0, data);
	if (ft_strncmp(var_name, "?", 2) == 0)
	{
		free(var_name);
		var_value = ft_itoa(g_flag.exit_val);
		ret = ft_strlen(var_value);
		free(var_value);
		return (ret);
	}
	else
	{
		var_value = get_env(data, var_name);
		free(var_name);
	}
	if (!var_value || !var_value[0])
		return (0);
	else
		return (ft_strlen(var_value));
}

char	*get_var_name(char *line, int quote_flag, t_data *data)
{
	int		x;
	int		y;
	char	*var_name;

	x = 0;
	y = 0;
	if (!line || line[x] == '\0')
		return (NULL);
	if (line[x] == '?' && is_valid_char(line[x + 1]) == 0)
		return (return_ret_val());
	while ((is_valid_char(line[x]) == 1
			&& quote_flag == set_qf(&line[x], quote_flag)))
		x++;
	var_name = malloc(sizeof(char) * (x + 1));
	if (!var_name)
		err_exit("allocation error", 1, data);
	while (x > y)
	{
		var_name[y] = line[y];
		y++;
	}
	var_name[x] = '\0';
	return (var_name);
}

char	*return_ret_val(void)
{
	char	*ret;

	ret = malloc(sizeof(char) * 2);
	ret[0] = '?';
	ret[1] = '\0';
	return (ret);
}

int	exchange_var(char *dest, char *var_name, t_data *data)
{
	int		x;
	char	*var_value;

	x = 0;
	if (ft_strncmp(var_name, "?", 2) == 0)
	{
		free(var_name);
		return (fill_exit_val(dest));
	}
	var_value = get_env(data, var_name);
	if (!var_value)
	{
		free(var_name);
		return (0);
	}
	while (var_value[x])
	{
		dest[x] = var_value[x];
		x++;
	}
	free(var_name);
	return (x);
}

int	ret_terminated(char *line, char *dest, int y, int x)
{
	if (line[x] == '<' || line[x] == '>')
	{
		dest[y] = '\0';
		return (x);
	}
	dest[y] = '\0';
	return (x + 1);
}
