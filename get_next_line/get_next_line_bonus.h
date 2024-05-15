/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvargom <alvargom@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:36:19 by alvargom          #+#    #+#             */
/*   Updated: 2024/05/15 14:56:37 by alvargom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

# include <unistd.h>
# include <stdlib.h>

char				*get_next_line(int fd);
void				*ft_calloc(unsigned long int size, unsigned long int c);
char				*ft_strjoin(char *s1, char *s2);
unsigned long int	ft_strlen(char *s);
char				*ft_strchr(char *save, int character);

#endif