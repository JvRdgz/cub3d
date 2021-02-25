/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:27:23 by jarodrig          #+#    #+#             */
/*   Updated: 2021/02/25 21:25:08 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Lee el mapa .cub utilizando el get_next_line(), y se guarda en
** la variable **world_map de la estructura.
*/

void	read_map(t_raycaster *raycaster, int *fd, char *line)
{
	// int		read;
	int		x;
	int		aux_fd;

	aux_fd = *fd;
	// read = 0;
	while ((x = get_next_line(aux_fd, &line)) > 0)
	{
		// printf("\nHOLA\n");
		// Para saber si lo lee correctamente.
		// printf("\n%s", line);
		raycaster->gnl_length = gnl_size(line);
		// printf("\nR_MAP: %s", *raycaster->r_map);
		// raycaster->r_map = memory_allocation(raycaster, *argv);
		// *raycaster->r_map = memory_allocation(raycaster, *argv);
		free(line);
		// read = 1;
	}
	// printf("\nGNL LENGTH: %zu\n", raycaster->gnl_length);
	// printf("\nMapa %s\n", *raycaster->r_map);
	// AQUI NO COGE EL free() del bucle porque sale antes de llegar ahi.
	// printf("\nLINE: %s\n", line);
	close(aux_fd);
}

size_t	gnl_size(char *line)
{
	int		i;

	i = 0;
	// printf("\nLINE: %s\n", line);
	while (line[i])
		i++;
	return (i);
}

void	memory_allocation(t_raycaster *raycaster, char *line)
{
	// char	*map;
	// int		i;

	// if (!(map = (char *)malloc(sizeof(char) * (raycaster->gnl_length + 1))))
		// return (NULL);
	raycaster->r_map = ft_calloc(raycaster->gnl_length + 1, sizeof(char));
	// if (!(*raycaster->r_map = (char *)malloc(sizeof(char) * (raycaster->gnl_length + 1))))
		// return (NULL);
	
	/**
	 * RESERVAR MEMORIA PARA EL MAPA DE LA ESTRUCTURA. PARA ELLO NECESITO HACER UN MALLOC POR
	 * CADA VEZ QUE SE LEE UNA LINEA DEL FICHERO, SUMANDO LA ANTERIOR RESERVA DE MEMORIA.
	 * PARA ELLO PUEDO CREAR UNA VARIABLE QUE GUARDE EL LENGTH DE GNL_SIZE() Y SE ACTUALICE POR
	 * CADA VEZ QUE ENTRE EN LA FUNCION DE NUEVO. A LA HORA DE RESERVAR LA MEMORIA CON MALLOC(),
	 * LE SUMO EL VALOR DE LA NUEVA VARIABLE QUE GUARDA EL SIZE DEL GNL.
	 */

	// i = 0;
/*
** 
** 	while (line[i])
** 	{
** 		map[i] = line[i];
** 		i++;
** 	}
*/
	// ft_memcpy(map, line, (raycaster->gnl_length + 1));
	// ft_memcpy(*raycaster->r_map, line, (raycaster->gnl_length + 1));
	// map[i] = '\0';
	// *raycaster->r_map = map;
	printf("\nMAP: %s\n", *raycaster->r_map);
	free(line);
	// return (map);
}

void	read_file(t_raycaster *raycaster, char **argv)
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
		read_map(raycaster, &fd, line);
		while ((x = get_next_line(fd, &line)) > 0)
		{
			// printf("\nHOLA\n");
			// Para saber si lo lee correctamente.
			printf("\n%s", line);
			// printf("\nR_MAP: %s", *raycaster->r_map);
			// raycaster->r_map = memory_allocation(raycaster, *argv);
			// *raycaster->r_map = memory_allocation(raycaster, *argv);
			ft_memcpy(*raycaster->r_map, line, (raycaster->gnl_length + 1));
			free(line);
			read = 1;
		}
	}
	if (read == 0)
		printf("\n\nNo ha entrado en el while de lectura.\n");
	else
		printf("\n\nMapa leido correctamente.\n");
	close(fd);
}
