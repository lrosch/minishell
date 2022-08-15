/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:15:11 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/29 10:44:52 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	e_pipe(t_data *data)
{
	int	fail;

	fail = pipe(data->pipe);
	if (fail == -1)
		err_exit("Creation of the pipe failed", 1, data);
}

int	e_fork(t_data *data)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		err_exit("creation of child process failed", 1, data);
	return (pid);
}

void	set_next_pipe(t_data *data)
{
	close(data->tmp_fd);
	data->tmp_fd = dup(data->pipe[0]);
	close(data->pipe[0]);
	close(data->pipe[1]);
}
