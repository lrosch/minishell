/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:22:59 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/31 12:57:41 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	set_qf_here_doc(char *delim)
{
	int	i;
	int	sq;
	int	dq;

	sq = 0;
	dq = 0;
	i = 0;
	while (delim[i])
	{
		if (delim[i] == '\'')
			sq++;
		if (delim[i] == '"')
			dq++;
		i++;
	}
	if (sq >= 2 || dq >= 2)
		return (1);
	return (0);
}

void	input_fail(void)
{
	write(2, "minishell: syntax error near input redirection\n", 47);
	g_flag.exit_val = 2;
}
