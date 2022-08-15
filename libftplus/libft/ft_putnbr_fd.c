/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:51:23 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/12 13:47:00 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkedge(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	int		x;
	int		neg;
	char	str[12];

	x = 0;
	neg = 0;
	ft_bzero(str, 12);
	if (checkedge(n, fd) == 1)
		return ;
	if (n < 0)
	{
		n = n * -1;
		neg = 1;
	}
	while (n != 0)
	{
		str[x] = (n % 10) + 48;
		n = n / 10;
		x++;
	}
	if (neg == 1)
		str[x] = '-';
	ft_strrev (str);
	write (fd, str, 12);
}

static int	checkedge(int n, int fd)
{
	if (n == 0)
	{
		write (fd, "0", 1);
		return (1);
	}
	else if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return (1);
	}
	return (0);
}
