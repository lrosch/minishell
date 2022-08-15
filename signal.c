/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:38:48 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/29 11:55:54 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_for_minishell(t_data *data)
{
	int		x;
	char	*s;

	x = 0;
	if (data->cmd_lst)
	{
		while (data->cmd_lst[x])
		{
			if (data->cmd_lst[x]->cmd_low)
			{		
				s = ft_substr(data->cmd_lst[x]->cmd_low,
						ft_strlen(data->cmd_lst[x]->cmd_low) - 10, 10);
				if (ft_strncmp(s, "/minishell", 10) == 0)
				{
					g_flag.int_flag = 3;
					g_flag.quit_flag = 0;
					g_flag.here_doc = 0;
				}
				free(s);
			}
			x++;
		}
	}
}

void	sig_int(int sig)
{
	(void)sig;
	if (g_flag.int_flag == 2)
	{
		printf("\n");
		close(STDIN_FILENO);
	}
	else
	{
		if ((g_flag.int_flag == 0 || g_flag.int_flag == 1)
			&& g_flag.here_doc == 0)
			printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		if (g_flag.int_flag == 0)
			rl_redisplay();
		g_flag.exit_val = 1;
	}
	if (g_flag.int_flag == 1 || g_flag.int_flag == 2)
	{
		if (g_flag.int_flag == 1)
			g_flag.exit_val = 130;
		if (g_flag.int_flag == 2)
			g_flag.exit_val = 1;
		g_flag.int_flag = 5;
	}
}

void	sig_quit(int sig)
{
	(void)sig;
	if (g_flag.quit_flag == 1)
	{
		printf("Quit: 3");
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		g_flag.quit = 1;
		g_flag.exit_val = 131;
	}
	else if (g_flag.quit_flag == 2)
	{
		printf("\n");
		g_flag.quit = 1;
		g_flag.exit_val = 131;
		close(STDIN_FILENO);
	}
}
