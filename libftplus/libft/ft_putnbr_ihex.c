/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ihex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:21:44 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/24 14:51:31 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_ihex(unsigned int nbr, int lettcase)
{
	if (nbr < 10)
		ft_putchar('0' + nbr);
	else if (nbr >= 10 && nbr < 16)
	{
		if (lettcase == 0)
			ft_putchar(87 + nbr);
		else if (lettcase == 1)
			ft_putchar(55 + nbr);
	}
	else
	{
		ft_putnbr_ihex(nbr / 16, lettcase);
		ft_putnbr_ihex(nbr % 16, lettcase);
	}
}
