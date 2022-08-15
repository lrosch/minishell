/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:17:44 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/29 17:03:44 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	export(t_cmd *cmd, t_data *data)
{	
	char	**split;
	int		i;
	int		flag;

	split = NULL;
	flag = 0;
	i = 1;
	if (!cmd->cmd[i])
		handle_export_no_arg(data);
	while (cmd->cmd[i])
	{
		flag += check_first(cmd->cmd[i]);
		if (cmd->cmd[i][0] == '=')
			i++;
		else
		{
			flag += export_routine(split, data, cmd, i);
			i++;
		}
	}
	if (flag == 0)
		return (0);
	else
		return (1);
}

int	export_routine(char **split, t_data *data, t_cmd *cmd, int i)
{
	split = ft_split_export(cmd->cmd[i]);
	if (split[1])
		split[1] = ft_handle_quotes_export(split[1]);
	if (!check_input(split))
	{
		free2d(split);
		return (1);
	}
	if (split[1])
		ft_export_var(data, split);
	else
	{
		export_without_equal(data, split[0]);
		free2d(split);
	}
	return (0);
}

int	check_first(char *cmd)
{
	if (cmd[0] == '=')
	{
		print_invalid_iden(cmd);
		return (1);
	}
	return (0);
}

void	ft_export_var(t_data *data, char **split)
{
	char	*s;
	t_env	*tmp;

	s = get_env(data, split[0]);
	tmp = data->env;
	if (get_env(data, split[0]) == NULL)
	{
		lstadd_back(&data->env, lstnew(split));
		return ;
	}
	while (tmp != NULL || s != NULL)
	{
		if (!ft_strncmpenv(tmp->var[0], split[0], ft_strlen(split[0]) + 1))
		{
			ft_assign_new_var(tmp, split);
			break ;
		}
		tmp = tmp->next;
	}
}

void	ft_assign_new_var(t_env *tmp, char **split)
{
	char	*s;

	s = ft_strdup(split[1]);
	free2d(split);
	if (tmp->var[1])
		free(tmp->var[1]);
	tmp->var[1] = s;
}
