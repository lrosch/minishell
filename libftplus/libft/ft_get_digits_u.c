/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digits_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:30:40 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/24 14:28:43 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_digits_u(unsigned int nmbr)
{
	int	x;

	x = 0;
	if (nmbr == 0)
		return (1);
	while (nmbr != 0)
	{
		nmbr = nmbr / 10;
		x++;
	}
	return (x);
}
