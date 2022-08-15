/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:14:12 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/31 14:02:42 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	err_exit(char *msg, int p_err, t_data *data)
{
	if (p_err == 1)
	{
		perror(msg);
	}
	else
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	free_all(data);
	exit(EXIT_FAILURE);
}

void	err_no_exe_rights(char *cmd, t_data *data, char **path)
{
	write(2, ">minishell: ", 12);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": no execution rights\n", 22);
	free2d(path);
	free_all(data);
	exit(126);
}

void	err_cmd_not_found(char *cmd, t_data *data)
{
	int	exit_value;

	exit_value = EXIT_FAILURE;
	if (cmd)
	{
		if (empty_input(cmd) == 1)
			exit_value = EXIT_SUCCESS;
		else
		{
			write(2, ">minishell: ", 12);
			write(2, cmd, ft_strlen(cmd));
			write(2, ": command not found\n", 20);
			exit_value = 127;
		}
	}
	else
		err_exit("cmd string corrupted", 0, data);
	free_all(data);
	exit(exit_value);
}

int	err_pipe(void)
{
	g_flag.exit_val = 258;
	write(2, "minishell: syntax error near unexpected token '|'\n", 50);
	return (1);
}

void	err_command_not_found(char *cmd, t_data *data, char **path)
{
	if (cmd[0] == '.' && cmd[1] == '\0')
	{
		write(2, ">minishell: ", 12);
		write(2, cmd, ft_strlen(cmd));
		write(2, ": filename argument required\n", 30);
		free2d(path);
		free_all(data);
		exit(2);
	}
	write(2, ">minishell: ", 12);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 21);
	free2d(path);
	free_all(data);
	exit(127);
}
