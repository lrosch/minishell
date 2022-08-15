/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:53:10 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/29 15:44:02 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cd(t_cmd *cmd, t_data *data)
{
	char	*oldwd;

	oldwd = data->cwd;
	if (cmd->cmd[1])
		cmd->cmd[1] = ft_handle_quotes_export(cmd->cmd[1]);
	if (!cmd->cmd[1])
	{
		if (chdir(get_env(data, "HOME")) == -1)
			return (error_cd());
		data->cwd = getcwd(NULL, 0);
		assign_wds_home(data, oldwd);
		free(oldwd);
		return (0);
	}
	if (chdir(cmd->cmd[1]) == -1)
		return (error_cd());
	else
	{
		data->cwd = getcwd(NULL, 0);
		assign_wds(data, oldwd);
		free(oldwd);
		return (0);
	}
}

void	assign_wds(t_data *data, char *oldwd)
{
	t_env	*tmp;

	tmp = data->env;
	while (tmp != NULL && oldwd != NULL)
	{
		if (!ft_strncmp(tmp->var[0], "OLDPWD", 6))
			ft_assign_new_wd(tmp, oldwd);
		tmp = tmp->next;
	}
	tmp = data->env;
	while (tmp != NULL && oldwd != NULL)
	{
		if (!ft_strncmp(tmp->var[0], "PWD", 3))
			ft_assign_new_wd(tmp, data->cwd);
		tmp = tmp->next;
	}
}

void	assign_wds_home(t_data *data, char *oldwd)
{
	t_env	*tmp;

	tmp = data->env;
	while (tmp != NULL && oldwd != NULL)
	{
		if (!ft_strncmp(tmp->var[0], "OLDPWD", 6))
			ft_assign_new_wd(tmp, oldwd);
		tmp = tmp->next;
	}
	tmp = data->env;
	while (tmp != NULL && oldwd != NULL)
	{
		if (!ft_strncmp(tmp->var[0], "PWD", 3))
			ft_assign_new_wd(tmp, get_env(data, "HOME"));
		tmp = tmp->next;
	}
}

void	ft_assign_new_wd(t_env *tmp, char *wd)
{
	char	*s;

	s = ft_strdup(wd);
	free(tmp->var[1]);
	tmp->var[1] = s;
}

int	error_cd(void)
{
	write(2, "No such file or directory\n", 26);
	return (1);
}
