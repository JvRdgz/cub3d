/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:33:34 by jarodrig          #+#    #+#             */
/*   Updated: 2021/01/24 22:08:54 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

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
	// printf("\nAUX: %s|\n", aux);
	while (aux[i])
	{
		if (aux[i] == '\n')
		{
			// printf("FF");
			break ;
		}
		i++;
	}
	// printf("\nAUX[I]: %c|\n", aux[i]);
	// aux[++j] = '\0';
	// printf("\nAUX[I]: %c|\n", aux[i]);
	// printf("\nAUX: %s|\n", aux);
	// printf("\nLENGTH: %d\n", ft_strlen(aux));
	// printf("\nI: %d\n", i);
	// printf("\nRET: %d|\n", ret);
	if (i < ft_strlen(aux))
	{
		// printf("\nHHH\n");
		*line = ft_substr(aux, 0, i);
		// printf("\nHOLA: %s\n", line);
		temp = ft_substr(aux, i + 1, ft_strlen(aux));
		free(aux);
		aux = ft_strdup(temp);
		free(temp);
	}
	else if (ret == 0)
	{
		// printf("FF");
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
		// printf("\nAUX: %s|\n", aux);
		// printf("\nBUF: %s|\n", buf);
		temp = ft_strjoin(aux, buf);
		// printf("\nTEMP: %s|\n", temp);
		free(aux);
		aux = ft_strdup(temp);
		free(temp);
	}
	else
	{
		// printf("\nFF\n");
		aux = ft_strdup(buf);
	}
	// printf("\nAUX: %s|\n", aux);
	return (aux);
}

int		get_next_line(int fd, char **line)
{
	static	char	*aux[4096];
	char			buf[BUFFER_SIZE + 1];
	int				ret;

/*
** 	ret = read(fd, buf, BUFFER_SIZE);
** 	if (ret == -1)
** 		return (-1);
*/
	// printf("\nread: %d\n", read(fd, buf, BUFFER_SIZE));
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		// printf("\nHHH\n");
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
	// printf("\nAUX: %s|\n", aux[fd]);
	aux[fd] = ft_space_line(aux[fd], line, ret);
	// printf("\nLINE: %s|\n", *line);
	// printf("\nAUX: %s|\n", aux[fd]);
	if (ret <= 0 && !aux[fd])
		return (ret);
	return (1);
}
