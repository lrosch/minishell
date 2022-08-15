/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:36:15 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/18 13:25:57 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env(t_cmd *cmd, t_data *data)
{
	t_env	*tmp;

	(void)cmd;
	tmp = data->env;
	while (tmp != NULL)
	{
		if (tmp->var[1])
		{
			write(1, tmp->var[0], ft_strlen(tmp->var[0]));
			write(1, "=", 1);
			write(1, tmp->var[1], ft_strlen(tmp->var[1]));
			write(1, "\n", 1);
		}
		tmp = tmp->next;
	}
	return (0);
}
