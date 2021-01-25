/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:27:23 by jarodrig          #+#    #+#             */
/*   Updated: 2021/01/25 21:02:38 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Lee el mapa .cub utilizando el get_next_line(), y se guarda en
** la variable **world_map de la estructura.
*/

size_t		gnl_size(char *line)
{
	int		i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

char	*memory_allocation(t_raycaster *raycaster, char *line)
{
	char	*map;
	// int		i;

	if (!(map = (char *)malloc(sizeof(char) * (gnl_size(line) + 1))))
		return (NULL);
	// i = 0;
/*
** 
** 	while (line[i])
** 	{
** 		map[i] = line[i];
** 		i++;
** 	}
*/
	ft_memcpy(map, line, (gnl_size(line)) + 1);
	// map[i] = '\0';
	printf("\nMAP: %s\n", map);
	free(line);
	return (map);
}
void	read_map(t_raycaster *raycaster, char **argv)
{
	int		fd;
	int		x;
	char	*line;
	int		read;

	read = 0;
	// printf("Argumento: %s\n", argv[0]);
	fd = open(argv[0], O_RDONLY);
	if (fd == -1)
		printf("\nError al leer el fichero\n");
	else
	{
		while ((x = get_next_line(fd, &line)) > 0)
		{
			// printf("\nHOLA\n");
			// Para saber si lo lee correctamente.
			printf("\n%s", line);
			// printf("\nR_MAP: %s", *raycaster->r_map);
			*raycaster->r_map = memory_allocation(raycaster, *argv);
			free(line);
			read = 1;
		}

		// AQUI NO COGE EL free() del bucle porque sale antes de llegar ahi.
		// printf("\nLINE: %s\n", line);

		if (read == 0)
			printf("\n\nNo ha entrado en el while de lectura.\n");
		else
			printf("\n\nMapa leido correctamente.\n");
	}
	close(fd);
}
