/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:37:09 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/31 12:27:09 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	empty_input(char *cmd)
{
	int	x;

	x = 0;
	while (cmd[x] >= 9 && cmd[x] <= 32)
		x++;
	if (cmd[x] == '\0')
		return (1);
	return (0);
}

int	handle_other(t_cmd *cmd, t_data *data)
{
	int	x;

	x = 1;
	while (cmd->cmd[x])
	{
		cmd->cmd[x] = ft_handle_quotes_export(cmd->cmd[x]);
		x++;
	}
	if (g_flag.int_flag != 5)
	{
		cmd->exe_path = find_exe_path(cmd, data);
		if (cmd->exe_path == NULL)
			err_cmd_not_found(cmd->cmd[0], data);
		if (execve(cmd->exe_path, cmd->cmd, form_array(data)) == -1)
			err_exit("execve failed", 1, data);
	}
	exit(-1);
}

int	handle_cmd(t_cmd *cmd, t_data *data, int x)
{
	int	ch_pid;

	ch_pid = e_fork(data);
	if (ch_pid == 0)
	{
		dup2(data->tmp_fd, STDIN_FILENO);
		close(data->tmp_fd);
		if (data->cmd_lst[x + 1])
		{
			dup2(data->pipe[1], STDOUT_FILENO);
			close(data->pipe[1]);
			close(data->pipe[0]);
		}
		set_redirections(cmd, data);
		handle_other(cmd, data);
	}
	else if (data->cmd_lst[x + 1])
		set_next_pipe(data);
	return (ch_pid);
}

void	execute_cmd_lst(t_data *data)
{
	int	x;
	int	ext;
	int	y;

	x = 0;
	y = 0;
	check_for_minishell(data);
	data->tmp_fd = dup(STDIN_FILENO);
	ext = get_nmb_extern(data);
	if (ext > 0)
		data->ch_pid = malloc(sizeof(int) * ext);
	while (data->cmd_lst[x])
	{
		if (data->cmd_lst[x + 1])
			e_pipe(data);
		if (check_builtins(data->cmd_lst[x], data) == -1)
			y += ext_exec_help(data, x, y);
		else
			handle_builtins_parent(data->cmd_lst[x], data, x);
		x++;
	}
	close(data->tmp_fd);
	wait_all(ext, data);
	free_input(data);
}

void	wait_all(int ext, t_data *data)
{
	int	stat_loc;
	int	x;

	x = 0;
	if (ext == 0)
		return ;
	while (x < ext)
	{
		waitpid(data->ch_pid[x], &stat_loc, 0);
		x++;
	}
	if (check_builtins(data->cmd_lst[data->nmb_cmd - 1], data) == -1
		&& g_flag.int_flag != 5 && g_flag.quit != 1)
		g_flag.exit_val = WEXITSTATUS(stat_loc);
	free(data->ch_pid);
}
