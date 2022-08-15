/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:37:10 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/29 15:52:58 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_prompt(t_data *data)
{
	char	*dis_dir;
	char	*user;
	char	*prompt;
	int		alloc_size;

	dis_dir = get_displayed_dir(data);
	user = get_env(data, "USER");
	if (user == NULL)
		user = "";
	alloc_size = ft_strlen(dis_dir);
	alloc_size += ft_strlen(user) + 4;
	prompt = malloc(alloc_size * sizeof(char));
	if (prompt == NULL)
		err_exit("allocation error", 1, data);
	prompt[alloc_size] = '\0';
	prompt = fuse_prompt(prompt, dis_dir, user);
	free(dis_dir);
	return (prompt);
}

char	*fuse_prompt(char *prompt, char *dis_dir, char *user)
{
	int	x;
	int	y;

	prompt[0] = '>';
	x = 1;
	y = 0;
	if (dis_dir)
	{
		while (dis_dir[y])
		{
			prompt[x] = dis_dir[y];
			x++;
			y++;
		}
	}
	fuse_prompt_extension(prompt, user, x, y);
	return (prompt);
}

void	fuse_prompt_extension(char *prompt, char *user, int x, int y)
{
	prompt[x] = ' ';
	x++;
	y = 0;
	if (user)
	{
		while (user[y])
		{
			prompt[x] = user[y];
			x++;
			y++;
		}
	}
	prompt[x] = '$';
	prompt[x + 1] = ' ';
}

char	*get_displayed_dir(t_data *data)
{
	char	**wd_display;
	char	*ret;
	int		dir_nmb;

	if (!ft_strncmp(data->cwd, "/", 2))
		return (ft_strdup(data->cwd));
	wd_display = ft_split(data->cwd, '/');
	if (wd_display == NULL)
		err_exit("working directory not found", 1, data);
	dir_nmb = ft_arrlen(wd_display);
	ret = ft_strdup(wd_display[dir_nmb - 1]);
	free2d(wd_display);
	return (ret);
}
