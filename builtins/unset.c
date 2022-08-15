/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:03:59 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/29 15:03:38 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	unset(t_cmd *cmd, t_data *data)
{
	t_env	*tmp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	check_unset_input(cmd->cmd);
	while (cmd->cmd[i])
	{
		tmp = data->env;
		while (tmp != NULL)
		{
			if (!ft_strncmpenv(cmd->cmd[i], tmp->var[0],
					ft_strlen(cmd->cmd[i])))
			{
				ft_cases(j, data);
				break ;
			}
			j++;
			tmp = tmp->next;
		}
		j = 0;
		i++;
	}
	return (check_unset_input2(cmd->cmd));
}

void	ft_cases(int j, t_data *data)
{
	if (j == 0)
		lst_delete_first(&data->env);
	else
		lst_delete(data->env, j);
}

void	check_unset_input(char **split)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (split[j])
	{
		while (split[j][i])
		{
			if (!ft_isalnum(split[j][i]))
			{
				if (split[j][i] != '_')
				{
					print_invalid_iden(split[j]);
					break ;
				}
			}
			i++;
		}
		i = 0;
		j++;
	}
}

int	check_unset_input2(char **split)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (split[j])
	{
		while (split[j][i])
		{
			if (!ft_isalnum(split[j][i]))
			{
				if (split[j][i] != '_')
					return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
