/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:27:23 by jarodrig          #+#    #+#             */
/*   Updated: 2021/01/24 22:08:55 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Lee el mapa .cub utilizando el get_next_line(), y se guarda en
** la variable **world_map de la estructura.
*/
void	memory_allocation(t_raycaster * raycaster, char **argv, int *fd, int *x, int *read)
{
	int		cont;
	int		aux_fd;
	int		aux_x;
	int		aux_read;
	char	*line;

	aux_fd = *fd;
	aux_x = *x;
	aux_read = *read;

	while ((aux_x = get_next_line(aux_fd, &line)) > 0)
	{
		// printf("\nHOLA\n");
		// Para saber si lo lee correctamente.
		// raycaster->r_map = &line;
		// printf("\nR_MAP: %s", *raycaster->r_map);
		free(line);
		aux_read = 1;
		cont++;
	}
	// AQUI NO COGE EL free() del bucle porque sale antes de llegar ahi.
	printf("\nLINE: %s\n", line);
	raycaster->r_map = ft_calloc(sizeof (char *), cont + 1);
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
		memory_allocation(raycaster, argv, &fd, &x, &read);
		while ((x = get_next_line(fd, &line)) > 0)
		{
			// printf("\nHOLA\n");
			// Para saber si lo lee correctamente.
			printf("\n%s", line);
			raycaster->r_map = &line;
			// printf("\nR_MAP: %s", *raycaster->r_map);
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
