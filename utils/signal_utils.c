/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:55:34 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/29 11:34:39 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_tings(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(1, 0, &term);
}

void	set_tingsrev(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag |= ECHOCTL;
	tcsetattr(1, 0, &term);
}

void	prompt_flags(int i)
{
	g_flag.int_flag = i;
	g_flag.quit_flag = i;
	if (i == 0)
		g_flag.quit = 0;
}

void	here_doc_settings(void)
{
	g_flag.int_flag = 2;
	g_flag.quit_flag = 2;
	g_flag.here_doc = 1;
	set_tings();
}
