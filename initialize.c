/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:39:34 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/29 16:10:46 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**define_builtins(t_data *data)
{
	char	**builtins;

	builtins = malloc(sizeof(char *) * 7);
	if (builtins == NULL)
		err_exit("allocation failed", 1, data);
	builtins[0] = "cd";
	builtins[1] = "echo";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	builtins[7] = NULL;
	return (builtins);
}

t_data	*data_init(char **envp, t_data *data)
{
	g_flag.int_flag = 0;
	g_flag.here_doc = 0;
	g_flag.exit_val = 0;
	g_flag.quit = 0;
	g_flag.quit_flag = 0;
	data->builtins = define_builtins(data);
	env_init(envp, data);
	data->cwd = getcwd(NULL, 0);
	return (data);
}

void	env_init(char **envp, t_data *data)
{
	int		i;

	i = 0;
	data->env = NULL;
	while (envp[i])
	{
		if (!lstadd_back(&data->env, lstnew(ft_split(envp[i], '='))))
			err_exit("allocation failed", 1, data);
		i++;
	}
}
