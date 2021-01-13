/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:33:34 by jarodrig          #+#    #+#             */
/*   Updated: 2020/02/17 11:30:33 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*sr;

	sr = (char *)s;
	while (*sr != c)
	{
		if (!*sr)
			return (NULL);
		sr++;
	}
	return (sr);
}

char	*ft_space_line(char *aux, char **line, int ret)
{
	char				*temp;
	unsigned	int		i;

	i = 0;
	while (aux[i])
	{
		if (aux[i] == '\n')
			break ;
		i++;
	}
	aux[i] = '\0';
	if (i < ft_strlen(aux))
	{
		*line = ft_substr(aux, 0, i);
		temp = ft_substr(aux, i + 1, ft_strlen(aux));
		free(aux);
		aux = ft_strdup(temp);
		free(temp);
	}
	else if (ret == 0)
	{
		*line = aux;
		aux = NULL;
	}
	// printf("\nHOLA\n");
	return (aux);
}

char	*resize_memory(char *buf, char *aux)
{
	char	*temp;

	if (aux)
	{
		// printf("\nAUX: %s HHH\n", aux);
		temp = ft_strjoin(aux, buf);
		free(aux);
		aux = ft_strdup(temp);
		free(temp);
	}
	else
		aux = ft_strdup(buf);
	printf("\nAUX: %s HHH\n", aux);
	return (aux);
}

int		get_next_line(int fd, char **line)
{
	static	char	*aux[4096];
	char			buf[BUFFER_SIZE + 1];
	int				ret;

	ret = 0;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		aux[fd] = resize_memory(buf, aux[fd]);
		if (ft_strchr(buf, '\n'))
		{
			// printf("\nHHH\n");
			break ;
		}
	}
	if (ret <= 0 && !aux[fd])
	{
		*line = ft_strdup("");
		return (ret);
	}
	aux[fd] = ft_space_line(aux[fd], line, ret);
	if (ret <= 0 && !aux[fd])
		return (ret);
	return (1);
}
