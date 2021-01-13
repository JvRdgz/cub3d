/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:34:09 by jarodrig          #+#    #+#             */
/*   Updated: 2020/02/17 14:07:29 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			get_next_line(int fd, char **line);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s1, unsigned int start, size_t len);

#endif
