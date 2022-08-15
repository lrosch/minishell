/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dig_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:31:26 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/24 14:42:31 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_dig_hex(unsigned long nbr)
{
	char			str[100];
	int				x;
	unsigned long	buf;

	x = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		buf = nbr % 16;
		if (buf < 10)
			str[x] = buf + 48;
		if (buf >= 10 && buf < 16)
			str[x] = buf + 87;
		x++;
		nbr = nbr / 16;
	}
	str[x] = '\0';
	return (ft_strlen(str));
}
