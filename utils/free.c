/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:40:13 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/21 09:03:41 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_all(t_data *data)
{
	t_env	*tmp;

	rl_clear_history();
	if (data->builtins)
		free(data->builtins);
	while (data->env)
	{
		tmp = data->env;
		if (tmp->var)
			free2d(tmp->var);
		if (tmp)
			free(tmp);
		data->env = data->env->next;
	}
	if (data->line)
		free(data->line);
	if (data->prompt)
		free(data->prompt);
	if (data->cwd)
		free(data->cwd);
	if (data)
		free(data);
}

void	free_tmp(t_env *tmp)
{
	if (tmp)
	{
		if (tmp->var[0])
			free(tmp->var[0]);
		if (tmp->var[1])
			free(tmp->var[1]);
		if (tmp->var)
			free(tmp->var);
		if (tmp)
			free(tmp);
	}
}

void	free2d(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i])
				free(str[i]);
			i++;
		}
		if (str)
			free(str);
	}
}

void	free_input(t_data *data)
{
	int	x;

	x = 0;
	if (data->cmd_lst)
	{
		while (data->cmd_lst[x])
		{
			if (data->cmd_lst[x]->in_fd > 2)
				close(data->cmd_lst[x]->in_fd);
			if (data->cmd_lst[x]->out_fd > 2)
				close(data->cmd_lst[x]->out_fd);
			free2d(data->cmd_lst[x]->cmd);
			if (data->cmd_lst[x]->cmd_low)
				free(data->cmd_lst[x]->cmd_low);
			if (data->cmd_lst[x])
				free(data->cmd_lst[x]);
			x++;
		}
		if (data->cmd_lst)
			free(data->cmd_lst);
	}
}

void	free_prompt(t_data *data)
{
	free(data->line);
	free(data->prompt);
}
