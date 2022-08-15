/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:53:58 by hskowron          #+#    #+#             */
/*   Updated: 2021/07/13 14:53:00 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	fsize;

	fsize = count * size;
	ptr = malloc(fsize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero (ptr, fsize);
	return (ptr);
}
