/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:50:49 by lrosch            #+#    #+#             */
/*   Updated: 2022/03/13 14:22:00 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*lstnew(char **str)
{
	t_env	*newelement;

	newelement = malloc(sizeof(t_env));
	if (newelement == NULL)
		return (NULL);
	newelement->var = str;
	newelement->next = NULL;
	return (newelement);
}

int	lstadd_back(t_env **lst, t_env *new)
{
	t_env	*end;

	if (new == NULL)
		return (0);
	if (!*lst)
		*lst = new;
	else
	{
		end = lstlast(*lst);
		end->next = new;
	}
	return (1);
}

t_env	*lstlast(t_env *lst)
{
	t_env	*end;

	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->next == NULL)
		{
			end = lst;
		}
		lst = lst->next;
	}
	return (end);
}

void	lst_delete(t_env *lst, int i)
{
	t_env	*prev;
	t_env	*tmp;

	while (i > 0)
	{
		if (i == 1)
			prev = lst;
		i--;
		lst = lst->next;
	}
	tmp = lst;
	lst = lst->next;
	free_tmp(tmp);
	prev->next = lst;
}

void	lst_delete_first(t_env **lst)
{
	t_env	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	free_tmp(tmp);
}
