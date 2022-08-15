/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:17:37 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/29 16:47:41 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_export_no_arg(t_data *data)
{
	t_env	*tmp;

	tmp = data->env;
	while (tmp != NULL)
	{
		write(1, "declare -x ", 11);
		write(1, tmp->var[0], ft_strlen(tmp->var[0]));
		if (tmp->var[1])
		{
			write(1, "=\"", 2);
			write(1, tmp->var[1], ft_strlen(tmp->var[1]));
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

void	print_invalid_iden(char *cmd)
{
	write(2, "not a valid identifier: ", 24);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
}

char	*ft_handle_quotes_export(char *delim)
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
	free(delim);
	newdelim[j] = '\0';
	return (newdelim);
}
