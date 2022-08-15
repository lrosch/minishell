/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:19:16 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/17 13:03:03 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fill_new_cmd(int red_index, char **tmp, char **cmd, int pieces)
{
	int	y;
	int	z;
	int	prev_l;

	y = 0;
	z = 0;
	prev_l = ft_arrlen(tmp);
	while (z < prev_l)
	{
		if (z == red_index)
		{
			while (pieces > 0)
			{
				free(tmp[z]);
				z++;
				pieces--;
			}
		}
		cmd[y] = tmp[z];
		y++;
		z++;
	}
	free(tmp);
}

char	**form_array(t_data *data)
{
	char	**arr;
	char	*buf;
	int		x;
	t_env	*tmp;

	x = 0;
	tmp = data->env;
	while (tmp)
	{
		x++;
		tmp = tmp->next;
	}
	arr = malloc(sizeof(char *) * (x + 1));
	arr[x] = NULL;
	x = 0;
	tmp = data->env;
	while (tmp)
	{
		buf = ft_strjoin(tmp->var[0], "=");
		arr[x] = ft_strjoin(buf, tmp->var[1]);
		free(buf);
		tmp = tmp->next;
		x++;
	}
	return (arr);
}
