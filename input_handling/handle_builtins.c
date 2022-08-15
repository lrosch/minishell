/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:09:31 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/29 10:36:59 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_builtins(t_cmd *cmd, t_data *data, int bi_id)
{
	if (bi_id == 0)
		g_flag.exit_val = cd(cmd, data);
	else if (bi_id == 1)
		g_flag.exit_val = echo(cmd, data);
	else if (bi_id == 2)
		g_flag.exit_val = pwd(cmd, data);
	else if (bi_id == 3)
		g_flag.exit_val = export(cmd, data);
	else if (bi_id == 4)
		g_flag.exit_val = unset(cmd, data);
	else if (bi_id == 5)
		g_flag.exit_val = env(cmd, data);
	else if (bi_id == 6)
		exit_builtin(cmd, data);
}

int	handle_builtins_parent(t_cmd *cmd, t_data *data, int x)
{
	int		bi_id;
	int		og_fd[2];

	og_fd[0] = dup(STDIN_FILENO);
	og_fd[1] = dup(STDOUT_FILENO);
	bi_id = check_builtins(cmd, data);
	dup2(data->tmp_fd, STDIN_FILENO);
	if (data->cmd_lst[x + 1])
	{
		dup2(data->pipe[1], STDOUT_FILENO);
		set_next_pipe(data);
	}
	set_redirections(cmd, data);
	handle_builtins(cmd, data, bi_id);
	close(data->pipe[1]);
	dup2(og_fd[0], STDIN_FILENO);
	dup2(og_fd[1], STDOUT_FILENO);
	return (1);
}

int	check_builtins(t_cmd *cmd, t_data *data)
{
	int		x;

	x = 0;
	while (data->builtins[x])
	{
		if (cmd->cmd_low)
		{
			if (ft_strncmp(cmd->cmd_low, data->builtins[x], 10) == 0)
				return (x);
		}
		x++;
	}
	return (-1);
}

int	get_nmb_extern(t_data *data)
{
	int	x;
	int	ret;

	x = 0;
	ret = 0;
	while (x < data->nmb_cmd)
	{
		if (check_builtins(data->cmd_lst[x], data) == -1)
			ret++;
		x++;
	}
	return (ret);
}
