/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:10:13 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/29 10:38:31 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	echo(t_cmd *cmd, t_data *data)
{
	int	i;

	i = 1;
	if (cmd->cmd[i])
	{
		if (cmd->cmd[i][0] == '-' && cmd->cmd[i][1] == 'n')
		{
			i++;
			echo_print(cmd, i);
			return (0);
		}
	}
	echo_print(cmd, i);
	write(1, "\n", 1);
	return (0);
	(void)data;
}

void	echo_print(t_cmd *cmd, int i)
{
	while (cmd->cmd[i])
	{
		print_decider(cmd, i);
		if (cmd->cmd[i + 1])
			write(1, " ", 1);
		i++;
	}
}

void	print_decider(t_cmd *cmd, int i)
{
	int	quote_flag;
	int	x;

	quote_flag = 0;
	x = 0;
	while (cmd->cmd[i][x])
	{
		quote_flag = set_qf(&cmd->cmd[i][x], quote_flag);
		if (ignore_quote(cmd->cmd[i][x], quote_flag) == 1)
			x++;
		else
		{
			write(1, &cmd->cmd[i][x], 1);
			x++;
		}
		if (ignore_quote(cmd->cmd[i][x], quote_flag) == 1)
		{
			quote_flag = 0;
			x++;
		}
	}
}

int	ignore_quote(char chr, int quote_flag)
{
	if ((chr == '\'' && quote_flag == 1)
		|| (chr == '"' && quote_flag == 2))
		return (1);
	return (0);
}
