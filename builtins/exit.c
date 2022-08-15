/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:40:46 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/31 12:30:45 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_builtin(t_cmd *cmd, t_data *data)
{
	int	ret;

	if (ft_strncmp(cmd->cmd[0], "exit", 5))
	{
		error_message_exit(cmd->cmd[0]);
		g_flag.exit_val = 127;
		return ;
	}
	if (cmd->cmd[1] && ft_plus(cmd->cmd[1]))
		exit_print_isnodigit(cmd->cmd[1], data);
	else if (cmd->cmd[1] && cmd->cmd[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
		get_out(1, data);
	}
	else if (cmd->cmd[1])
	{
		ret = ft_atoi(cmd->cmd[1]);
		while (ret > 255)
			ret = ret % 256;
		get_out(ret, data);
	}
	else
		get_out(g_flag.exit_val, data);
}

void	get_out(int exit_val, t_data *data)
{
	struct termios	term;

	tcgetattr(1, &term);
	free_input(data);
	free_all(data);
	write(1, "logout\n", 7);
	term.c_lflag |= ECHOCTL;
	tcsetattr(1, 0, &term);
	exit(exit_val);
}

void	exit_print_isnodigit(char *cmd, t_data *data)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putendl_fd(": numeric argument is required", STDERR_FILENO);
	get_out(255, data);
}

int	ft_plus(char *cmd)
{
	int	i;

	i = 1;
	if (cmd[0] == '+' || cmd[0] == '-')
	{
		while (cmd[i])
		{
			if (!ft_isdigit(cmd[i]))
				return (1);
			i++;
		}
	}
	else
		return (ft_isdigit_string(cmd));
	return (0);
}

void	error_message_exit(char *cmd)
{
	write(2, "minishell: ", 11);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found", 19);
	write(2, "\n", 1);
}
