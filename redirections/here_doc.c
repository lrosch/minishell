/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:03:18 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/31 12:29:19 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_here_doc(t_cmd *cmd, t_data *data, char *delim, int mode)
{
	char	*line;
	char	*input;
	int		stdin_fd;

	stdin_fd = dup(STDIN_FILENO);
	input = allocate_input();
	while (1)
	{
		signal(SIGINT, sig_int);
		line = readline("heredoc> ");
		if (!line)
		{
			dup2(stdin_fd, STDIN_FILENO);
			break ;
		}	
		if (ft_strncmp(line, delim, ft_strlen(delim) + 1) == 0)
		{
			g_flag.here_doc = 0;
			break ;
		}
		else
			input = append_input(line, input, data, mode);
	}
	free(line);
	set_up_here_doc_pipe(cmd, data, input, delim);
}

char	*allocate_input(void)
{
	char	*input;

	input = malloc(sizeof(char) * 1);
	input[0] = '\0';
	return (input);
}

void	set_up_here_doc_pipe(t_cmd *cmd, t_data *data, char *input, char *del)
{
	free(del);
	cmd->here_doc = input;
	if (pipe(cmd->here_doc_pipe) == -1)
		err_exit("here_doc pipe failed", 1, data);
	if (g_flag.int_flag != 5 || g_flag.here_doc != 1)
		write(cmd->here_doc_pipe[1], cmd->here_doc, ft_strlen(cmd->here_doc));
	free(cmd->here_doc);
	close(cmd->here_doc_pipe[1]);
}

char	*append_input(char *line, char *input, t_data *data, int mode)
{
	char	*tmp;

	if (input[0] == '\0')
	{
		free(input);
		input = append_onto_old(line, NULL, data, mode);
		return (input);
	}
	tmp = input;
	input = append_onto_old(line, tmp, data, mode);
	if (!input)
		err_exit("here_doc failed to allocate", 1, data);
	free(tmp);
	free(line);
	g_flag.here_doc = 0;
	return (input);
}
