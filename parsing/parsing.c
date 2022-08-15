/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:34:27 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/31 11:56:23 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	handle_input(char *line, t_data *data)
{
	int		x;

	x = 0;
	if (initial_pipe_check(line) == 1)
		return (1);
	data->cmd_lst = malloc(sizeof(t_cmd *) * (data->nmb_cmd + 1));
	if (data->cmd_lst == NULL)
		err_exit("allocation error: cmd_lst", 1, data);
	while (x < data->nmb_cmd)
	{
		data->cmd_lst[x] = malloc(sizeof(t_cmd));
		x++;
	}
	split_cmd(line, data, data->nmb_cmd);
	if (handle_redirect(data->cmd_lst, data) == 1)
		return (1);
	x = 0;
	while (data->cmd_lst[x])
	{
		if (data->cmd_lst[x]->cmd[0])
			data->cmd_lst[x]->cmd_low = ft_strdup_low(data->cmd_lst[x]->cmd[0]);
		x++;
	}
	return (0);
}

int	get_nmb_cmd(char *line)
{
	int	x;
	int	cmd_c;
	int	quote_flag;

	g_flag.here_doc = 0;
	x = 0;
	cmd_c = 1;
	quote_flag = 0;
	if (!line[x])
		return (0);
	while (line[x])
	{
		quote_flag = set_qf(&line[x], quote_flag);
		if (line[x] == '|' && quote_flag == 0)
			cmd_c++;
		x++;
	}
	return (cmd_c);
}

void	init_cmd(t_cmd *cmd, int x)
{
	cmd->in_fd = 0;
	cmd->out_fd = 1;
	cmd->in_path = NULL;
	cmd->out_path = NULL;
	cmd->nmb = x + 1;
	cmd->append = 0;
	cmd->here_doc = NULL;
	cmd->cmd_low = NULL;
}

char	*ft_strdup_low(char *str)
{
	int		str_size;
	char	*nstr;
	int		x;

	x = 0;
	str_size = 0;
	while (str[x])
	{
		if (str[x] != '\'' && str[x] != '"')
			str_size++;
		x++;
	}
	nstr = malloc(sizeof(char) * (str_size + 1));
	if (!nstr)
		return (NULL);
	nstr = cpy_no_quotes(nstr, str);
	return (nstr);
}

char	*cpy_no_quotes(char *nstr, char *str)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	quote_decider(&str[x], 0);
	while (str[x])
	{
		if (quote_decider(&str[x], x) == 1)
		{
			nstr[y] = ft_tolower(str[x]);
			y++;
		}
		x++;
	}
	nstr[y] = '\0';
	return (nstr);
}
