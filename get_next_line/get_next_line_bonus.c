/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvargom <alvargom@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:36:15 by alvargom          #+#    #+#             */
/*   Updated: 2024/05/15 14:30:34 by alvargom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_join_fr(char *buffer, char *t)
{
	char	*joined;

	joined = ft_strjoin(buffer, t);
	free(buffer);
	return (joined);
}

static char	*sv_rest(char *buffer)
{
	int		c;
	int		sc;
	char	*rest;

	c = 0;
	while (buffer[c] != '\0' && buffer[c] != '\n')
		c++;
	if (buffer[c] == '\0')
	{
		free(buffer);
		return (0);
	}
	rest = ft_calloc(sizeof(char), ft_strlen(buffer) - c + 1);
	c++;
	sc = 0;
	while (buffer[c] != '\0')
		rest[sc++] = buffer[c++];
	free(buffer);
	return (rest);
}

static char	*cpy_line(char *buffer)
{
	int		c;
	char	*cpy;

	c = 0;
	if (buffer[c] == '\0')
		return (0);
	while (buffer[c] != '\0' && buffer[c] != '\n')
		c++;
	if (buffer[c] != '\n')
		cpy = ft_calloc(sizeof(char), (c + 1));
	else
		cpy = ft_calloc(sizeof(char), (c + 2));
	c = 0;
	while (buffer[c] != '\0' && buffer[c] != '\n')
	{
		cpy[c] = buffer[c];
		c++;
	}
	if (buffer[c] == '\n')
		cpy[c] = '\n';
	return (cpy);
}

static char	*read_u_ent(int fd, char *buffer)
{
	int		cc;
	char	*t;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	t = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	cc = 1;
	while (cc > 0)
	{
		cc = read(fd, t, BUFFER_SIZE);
		if (cc == -1)
		{
			free(t);
			free(buffer);
			return (0);
		}
		t[cc] = '\0';
		buffer = ft_join_fr(buffer, t);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(t);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*cpy;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (0);
	}
	buffer[fd] = read_u_ent(fd, buffer[fd]);
	if (buffer[fd] == 0)
	{
		free(buffer);
		return (0);
	}
	cpy = cpy_line(buffer[fd]);
	buffer[fd] = sv_rest(buffer[fd]);
	return (cpy);
}
