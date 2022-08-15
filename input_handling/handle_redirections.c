/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:17:45 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/17 14:44:52 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	handle_redirect(t_cmd **cmd_lst, t_data *data)
{
	if (handle_in_red(cmd_lst, data) == 1)
		return (1);
	if (handle_out_red(cmd_lst, data) == 1)
		return (1);
	return (0);
}

void	cut_redirect(t_cmd *cmd, int red_index, t_data *data, int pieces)
{
	char	**tmp;
	int		prev_l;
	int		len;

	tmp = cmd->cmd;
	prev_l = ft_arrlen(tmp);
	len = prev_l - pieces;
	cmd->cmd = malloc(sizeof(char *) * (len + 1));
	if (cmd->cmd == NULL)
		err_exit("allocation error: cmd, cut_redirect", 1, data);
	cmd->cmd[len] = NULL;
	if (prev_l == pieces)
		free2d(tmp);
	else
		fill_new_cmd(red_index, tmp, cmd->cmd, pieces);
}

void	set_redirections_redacted(t_cmd *cmd, t_data *data)
{
	if (cmd->in_path)
	{
		if (dup2(cmd->in_fd, STDIN_FILENO) == -1)
			err_exit("failed to apply in_fd", 1, data);
	}
	if (cmd->out_path)
	{
		if (dup2(cmd->out_fd, STDOUT_FILENO) == -1)
			err_exit("failed to apply out_fd", 1, data);
	}
	if (cmd->here_doc)
	{
		close(cmd->here_doc_pipe[1]);
		if (dup2(cmd->here_doc_pipe[0], STDIN_FILENO) == -1)
			err_exit("here_doc dup2 failed", 1, data);
		close(cmd->here_doc_pipe[0]);
	}
}

void	set_redirections(t_cmd *cmd, t_data *data)
{
	if (cmd->in_path)
	{
		if (dup2(cmd->in_fd, STDIN_FILENO) == -1)
			err_exit("failed to apply in_fd", 1, data);
		close(cmd->in_fd);
	}
	if (cmd->out_path)
	{
		if (dup2(cmd->out_fd, STDOUT_FILENO) == -1)
			err_exit("failed to apply out_fd", 1, data);
		close(cmd->out_fd);
	}
	if (cmd->here_doc)
	{
		close(cmd->here_doc_pipe[1]);
		if (dup2(cmd->here_doc_pipe[0], STDIN_FILENO) == -1)
			err_exit("here_doc dup2 failed", 1, data);
		close(cmd->here_doc_pipe[0]);
	}
}
