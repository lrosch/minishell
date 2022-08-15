/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:36:19 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/31 14:02:30 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env(t_data *data, char *to_srch)
{
	char	*s;
	t_env	*tmp;

	tmp = data->env;
	while (tmp != NULL)
	{
		if (!ft_strncmpenv(to_srch, tmp->var[0], ft_strlen(to_srch)))
		{
			s = tmp->var[1];
			if (tmp->var[1] == NULL)
				return ("");
			return (s);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

char	**get_path_variable(t_data *data)
{
	char	*buf;
	char	**ret;
	int		x;

	x = 0;
	buf = get_env(data, "PATH");
	if (buf == NULL)
		return (NULL);
	ret = ft_split(buf + 5, ':');
	if (ret == NULL)
		err_exit("failed to split PATH", 1, data);
	while (ret[x])
	{
		buf = ret[x];
		ret[x] = ft_strjoin(buf, "/");
		free(buf);
		x++;
	}
	return (ret);
}

char	*find_exe_path(t_cmd *cmd, t_data *data)
{
	int		x;
	char	**path;
	char	*full_exe;

	x = 0;
	if (empty_input(cmd->cmd_low) == 1)
		return (NULL);
	if (check_exe(data, cmd->cmd_low, NULL) == 1)
		return (cmd->cmd_low);
	path = get_path_variable(data);
	if (!path)
		return (NULL);
	check_input_error(cmd, data, path);
	while (path[x])
	{
		full_exe = ft_strjoin(path[x], cmd->cmd_low);
		if (check_exe(data, full_exe, path) == 1)
		{
			free2d(path);
			return (full_exe);
		}
		x++;
	}
	free2d(path);
	return (NULL);
}

int	check_exe(t_data *data, char *path, char **path2d)
{
	struct stat	stat_loc;

	if (access(path, F_OK) == 0)
	{
		stat(path, &stat_loc);
		if (S_ISDIR(stat_loc.st_mode) == 1)
			err_command_not_found(path, data, path2d);
		if (access(path, X_OK) == 0)
		{
			return (1);
		}
		err_no_exe_rights(path, data, path2d);
	}
	return (0);
}

void	check_input_error(t_cmd *cmd, t_data *data, char **path)
{
	if (cmd->cmd_low[0] == '.' || cmd->cmd_low[0] == '/')
	{
		write(2, ">minishell: ", 12);
		write(2, cmd->cmd[0], ft_strlen(cmd->cmd[0]));
		write(2, ": No such file or directory\n", 28);
		free2d(path);
		free_all(data);
		exit(127);
	}
}
