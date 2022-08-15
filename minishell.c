/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:41:07 by hskowron          #+#    #+#             */
/*   Updated: 2022/07/26 16:35:46 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_flag	g_flag;

void	prompt(t_data *data)
{
	while (1)
	{
		set_tings();
		data->prompt = get_prompt(data);
		signal(SIGINT, sig_int);
		signal(SIGQUIT, SIG_IGN);
		data->line = readline(data->prompt);
		prompt_flags(1);
		signal(SIGQUIT, sig_quit);
		set_tingsrev();
		if (!data->line)
		{
			write(1, "logout\n", 7);
			break ;
		}
		if (ft_strlen(data->line) > 0)
			add_history(data->line);
		data->nmb_cmd = get_nmb_cmd(data->line);
		if (handle_input(data->line, data) != 1)
			execute_cmd_lst(data);
		free_prompt(data);
		prompt_flags(0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data			*data;
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(1, 0, &term);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		err_exit("allocation error", 1, data);
	data = data_init(envp, data);
	prompt(data);
	free_all(data);
	term.c_lflag |= ECHOCTL;
	tcsetattr(1, 0, &term);
	return (g_flag.exit_val);
	(void)argc;
	(void)argv;
}
