/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:30:40 by hskowron          #+#    #+#             */
/*   Updated: 2021/10/04 14:56:01 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_digits(int nmbr)
{
	int	x;

	x = 0;
	if (nmbr == 0)
		return (1);
	if (nmbr < 0)
		x++;
	while (nmbr != 0)
	{
		nmbr = nmbr / 10;
		x++;
	}
	return (x);
}
