/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:04:10 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/12 13:45:39 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n);

static int	itoarec(long n, char *str, int x);

static int	ifzeroorneg(long n, char *str);

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	long	nmb;
	int		x;

	str = (char *)malloc ((intlen(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	nmb = n;
	x = 0;
	neg = ifzeroorneg (nmb, str);
	if (neg == 1)
		nmb = nmb * -1;
	if (n != 0)
		itoarec (nmb, str, x);
	x = ft_strlen (str);
	if (neg == 1)
	{
		str[x] = '-';
		str[x + 1] = '\0';
	}
	ft_strrev (str);
	return (str);
}

static int	ifzeroorneg(long n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = 0;
	}
	if (n < 0)
		return (1);
	return (0);
}

static int	itoarec(long n, char *str, int x)
{
	if (n != 0)
	{
		str[x] = (n % 10) + 48;
		return (itoarec((n / 10), str, (x + 1)));
	}
	else
	{
		str[x] = 0;
		return (0);
	}
}

static int	intlen(int n)
{
	int	x;

	x = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		x++;
	while (n != 0)
	{
		n = n / 10;
		x++;
	}
	return (x);
}
