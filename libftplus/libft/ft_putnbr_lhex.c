/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_lhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:53:44 by hskowron          #+#    #+#             */
/*   Updated: 2021/09/21 15:45:53 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_lhex(unsigned long nbr)
{
	if (nbr < 10)
		ft_putchar('0' + nbr);
	else if (nbr >= 10 && nbr < 16)
		ft_putchar(87 + nbr);
	else
	{
		ft_putnbr_lhex(nbr / 16);
		ft_putnbr_lhex(nbr % 16);
	}
}
