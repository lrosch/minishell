/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:16:28 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/26 19:01:51 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	skip_whitespace_pipe_check(char *line, int quote_flag)
{
	int	x;
	int	ret;

	x = 0;
	ret = 0;
	while (quote_flag == 0 && ((line[x] > 8 && line[x] < 14) || line[x] == 32))
	{
		ret++;
		x++;
	}
	return (ret);
}
