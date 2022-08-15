/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:43:57 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/29 16:44:52 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_without_equal(t_data *data, char *cmd)
{
	t_env	*tmp;
	char	**str;
	char	*s;

	str = malloc(sizeof(char *) * 3);
	malloc_str(cmd, str);
	s = get_env(data, cmd);
	tmp = data->env;
	if (get_env(data, cmd) == NULL)
	{
		lstadd_back(&data->env, lstnew(str));
		return ;
	}
	while (tmp != NULL)
	{
		if (!ft_strncmp(tmp->var[0], cmd, ft_strlen(cmd) + 1))
		{
			if (!tmp->var[1])
				ft_assign_new_var(tmp, str);
			else
				free2d(str);
		}
		tmp = tmp->next;
	}
}

void	malloc_str(char *cmd, char **str)
{
	str[0] = ft_strdup(cmd);
	str[1] = NULL;
	str[2] = NULL;
}

int	check_input(char **split)
{
	int	i;

	i = 0;
	if (ft_isalpha(split[0][0]))
		return (check_input_nbr(*split));
	while (split[0][i])
	{
		if (!ft_isalpha(split[0][i]))
		{
			if (split[0][i] != '_')
			{
				print_invalid_iden(split[0]);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_input_nbr(char *split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!ft_isalnum(split[i]))
		{
			if (split[i] != '_')
			{
				print_invalid_iden(split);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
