/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_bf_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:30:06 by hskowron          #+#    #+#             */
/*   Updated: 2021/11/10 12:53:26 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_bf_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->next->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
