/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:48:02 by hskowron          #+#    #+#             */
/*   Updated: 2022/02/28 20:29:31 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	setnull(char **str, int fd)
{
	free(str[fd]);
	str[fd] = NULL;
}

char	*ft_getline(char **str, int fd)
{
	int		x;
	char	*line;
	char	*tmp;

	x = 0;
	while (str[fd][x] != '\n' && str[fd][x] != 0)
		x++;
	if (str[fd][x] == '\n')
	{
		line = ft_substr(str[fd], 0, x + 1);
		tmp = ft_substr(str[fd], x + 1, ft_strlen(str[fd]));
		if (tmp == NULL)
			return (NULL);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			setnull(str, fd);
	}
	else
	{
		line = ft_substr(str[fd], 0, ft_strlen(str[fd]));
		setnull(str, fd);
	}
	return (line);
}

int	puttogether(int bufl, char **str, char *buf, int fd)
{
	char	*tmp;

	if ((bufl == 0 && str[fd] == NULL) || bufl < 0)
	{
		free(buf);
		return (1);
	}
	buf[bufl] = '\0';
	if (str[fd] == NULL)
		str[fd] = ft_substr(buf, 0, bufl + 1);
	else if (buf[0] != '\0')
	{
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
	}
	if (str[fd] == NULL)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str[FOPEN_MAX];
	char		*buf;
	int			bufl;

	if (fd < 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	bufl = 1;
	while (bufl > 0)
	{
		bufl = read(fd, buf, BUFFER_SIZE);
		if (puttogether(bufl, str, buf, fd) == 1)
			return (NULL);
		if (ft_strrchr_ez(str[fd], '\n') != 0)
			break ;
	}
	free(buf);
	return (ft_getline(str, fd));
}
