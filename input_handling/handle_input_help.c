/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:23:02 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/26 16:26:03 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ext_exec_help(t_data *data, int x, int y)
{
	data->ch_pid[y] = handle_cmd(data->cmd_lst[x], data, x);
	return (1);
}
