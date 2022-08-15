/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_in_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:23:00 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/31 12:57:54 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	handle_in_red(t_cmd **cmd_lst, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (cmd_lst[x])
	{
		while (cmd_lst[x]->cmd[y])
		{
			if (cmp_in_red(cmd_lst[x]->cmd[y]))
			{
				if (find_right_in_red(cmd_lst[x], data, y) == 1)
					return (1);
				y = -1;
			}
			y++;
		}
	y = 0;
	x++;
	}
	return (0);
}

int	find_right_in_red(t_cmd *cmd, t_data *data, int y)
{
	int	len;

	len = ft_strlen(cmd->cmd[y]);
	if (ft_strncmp(cmd->cmd[y], "<<", 2) == 0)
	{
		if (check_here_doc(cmd, data, y, len) == 1)
			return (1);
	}
	else if (ft_strncmp(cmd->cmd[y], "<", 1) == 0)
	{
		if (len == 1)
		{
			if (apply_in_red(cmd, cmd->cmd[y + 1]) == 1)
				return (1);
			cut_redirect(cmd, y, data, 2);
		}	
		else
		{
			if (apply_in_red(cmd, (cmd->cmd[y] + 1)) == 1)
				return (1);
			cut_redirect(cmd, y, data, 1);
		}
	}
	return (0);
}

int	check_here_doc(t_cmd *cmd, t_data *data, int y, int len)
{
	char	*delim;
	int		mode;

	here_doc_settings();
	signal(SIGQUIT, SIG_IGN);
	if (len == 2)
	{
		if (!cmd->cmd[y + 1])
		{
			input_fail();
			return (1);
		}
		mode = set_qf_here_doc(cmd->cmd[y + 1]);
		delim = ft_handle_quotes(cmd->cmd[y + 1]);
		handle_here_doc(cmd, data, delim, mode);
		cut_redirect(cmd, y, data, 2);
	}
	else
	{
		mode = set_qf_here_doc(cmd->cmd[y] + 2);
		delim = ft_handle_quotes(cmd->cmd[y] + 2);
		handle_here_doc(cmd, data, delim, mode);
		cut_redirect(cmd, y, data, 1);
	}
	return (0);
}

int	apply_in_red(t_cmd *cmd, char *red)
{
	if (!red || red[0] == '\0')
	{
		input_fail();
		write(2, "minishell: syntax error near input redirection\n", 47);
		return (1);
	}
	cmd->in_path = red;
	cmd->in_fd = open(cmd->in_path, O_RDWR | O_APPEND);
	if (cmd->in_fd == -1)
	{
		write(2, "minishell: ", 11);
		write(2, cmd->in_path, ft_strlen(cmd->in_path));
		write(2, ": ", 2);
		perror(NULL);
		g_flag.exit_val = 1;
		return (1);
	}
	return (0);
}

int	cmp_in_red(char *part)
{
	if (ft_strncmp(part, "<<", 2) != 0)
	{
		if (ft_strncmp(part, "<", 1) != 0)
			return (0);
	}
	return (1);
}
