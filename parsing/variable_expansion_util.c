/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion_util.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:34:36 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/24 14:15:11 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid_char(char cha)
{
	if ((cha > 47 && cha < 58)
		|| (cha > 64 && cha < 91)
		|| (cha > 96 && cha < 123)
		|| cha == '_')
		return (1);
	else
		return (0);
}
