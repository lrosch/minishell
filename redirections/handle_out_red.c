/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_out_red.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:56:10 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/31 12:54:52 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	handle_out_red(t_cmd **cmd_lst, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (cmd_lst[x])
	{
		if (cmd_lst[x]->cmd)
		{
			while (cmd_lst[x]->cmd[y])
			{
				if (cmp_out_red(cmd_lst[x]->cmd[y]))
				{
					if (find_right_out_red(cmd_lst[x], data, y) == 1)
						return (1);
					y = -1;
				}
				y++;
			}
			y = 0;
		}
		x++;
	}
	return (0);
}

int	find_right_out_red(t_cmd *cmd, t_data *data, int y)
{
	int	len;

	len = ft_strlen(cmd->cmd[y]);
	if (len <= 2)
	{
		if (ft_strncmp(cmd->cmd[y], ">>", 2) == 0)
			cmd->append = 1;
		if (ft_strncmp(cmd->cmd[y], ">", 1) == 0
			|| ft_strncmp(cmd->cmd[y], ">>", 2) == 0)
		{
			if (apply_out_red(cmd, cmd->cmd[y + 1]) == 1)
				return (1);
			cut_redirect(cmd, y, data, 2);
		}
	}
	else
	{
		if (out_red_cmb(cmd, data, y) == 1)
			return (1);
	}
	return (0);
}

int	out_red_cmb(t_cmd *cmd, t_data *data, int y)
{
	(void)data;
	if (ft_strncmp(cmd->cmd[y], ">>", 2) == 0)
	{
		cmd->append = 1;
		if (apply_out_red(cmd, (cmd->cmd[y] + 2)) == 1)
			return (1);
		cut_redirect(cmd, y, data, 1);
	}
	else if (ft_strncmp(cmd->cmd[y], ">", 1) == 0)
	{
		if (apply_out_red(cmd, (cmd->cmd[y] + 1)) == 1)
			return (1);
		cut_redirect(cmd, y, data, 1);
	}
	return (0);
}

int	apply_out_red(t_cmd *cmd, char *red)
{
	if (!red || red[0] == '\0')
	{
		write(2, "minishell: syntax error near output redirection\n", 48);
		g_flag.exit_val = 2;
		return (1);
	}
	cmd->out_path = red;
	if (cmd->append == 0)
		cmd->out_fd = open(cmd->out_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (cmd->append == 1)
		cmd->out_fd = open(cmd->out_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (cmd->out_fd == -1)
	{
		write(2, "minishell: ", 11);
		write(2, cmd->out_path, ft_strlen(cmd->out_path));
		write(2, ": ", 2);
		perror(NULL);
		g_flag.exit_val = 1;
		return (1);
	}
	return (0);
}

int	cmp_out_red(char *part)
{
	if (ft_strncmp(part, ">>", 2) != 0)
	{
		if (ft_strncmp(part, ">", 1) != 0)
			return (0);
	}
	return (1);
}
