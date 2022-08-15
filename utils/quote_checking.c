/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:06:16 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/29 14:24:06 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	set_qf(char *line, int quote_flag)
{
	if (quote_flag == 0)
	{
		if (line[0] == '\'')
			return (check_closed_quote(line, '\''));
		if (line[0] == '"')
			return (check_closed_quote(line, '"'));
	}
	else
	{
		if (line[0] == '\'' && quote_flag == 1)
			return (0);
		if (line[0] == '"' && quote_flag == 2)
			return (0);
	}
	return (quote_flag);
}

int	check_closed_quote(char *line, char quote)
{
	int	x;
	int	ret;

	x = 1;
	if (quote == '\'')
		ret = 1;
	else if (quote == '"')
		ret = 2;
	while (line[x])
	{
		if (line[x] == quote)
			return (ret);
		x++;
	}
	return (0);
}

int	count_quotes(char *line, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		i++;
		if (line[i] == c)
			j++;
	}
	return (j);
}

char	*ft_handle_quotes(char *delim)
{
	int		i;
	int		j;
	char	*newdelim;
	int		len;

	len = ft_strlen(delim) - (count_quotes(delim, '\'')
			+ count_quotes(delim, '"'));
	newdelim = malloc(len + 1);
	i = 0;
	j = 0;
	while (delim[i])
	{
		if (delim[i] != '\'' && delim[i] != '"')
		{
			newdelim[j] = delim[i];
			j++;
		}
		i++;
	}
	newdelim[j] = '\0';
	return (newdelim);
}
