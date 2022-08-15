/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:00:16 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/29 15:15:16 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 47 || str[i] >= 58)
			return (1);
		else
			i++;
	}
	return (0);
}
