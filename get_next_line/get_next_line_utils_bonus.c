/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvargom <alvargom@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:36:08 by alvargom          #+#    #+#             */
/*   Updated: 2024/05/14 11:53:51 by alvargom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned long int	ft_strlen(char *s)
{
	unsigned long int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *save, int character)
{
	unsigned long int	i;

	i = 0;
	while (save[i] != character && save[i] != '\0')
		i++;
	if (save[i] == character)
		return (save);
	return (NULL);
}

void	ft_bzero(void *str, unsigned long int n)
{
	char				*s;
	unsigned long int	i;

	s = (char *)str;
	i = 0;
	while (i < n)
		s[i++] = '\0';
}

void	*ft_calloc(unsigned long int size, unsigned long int c)
{
	char	*result;

	result = malloc(size * c);
	if (!result)
		return (0);
	ft_bzero(result, (size * c));
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;

	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s || !s1 || !s2)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		s[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		s[ft_strlen(s1) + i] = s2[i];
	s[ft_strlen(s1) + i] = '\0';
	return (s);
}
