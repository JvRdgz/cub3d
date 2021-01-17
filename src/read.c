/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:27:23 by jarodrig          #+#    #+#             */
/*   Updated: 2021/01/17 15:34:07 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Lee el mapa .cub utilizando el get_next_line(), y se guarda en
** la variable **world_map de la estructura.
*/
void	read_map(t_raycaster *raycaster, char **argv)
{
	int		fd;
	int		x;
	char	*line;
	int		read;

	read = 0;
	fd = open(argv[1], O_RDONLY);
	while ((x = get_next_line(fd, &line)) > 0)
	{
		printf("\nHOLA\n");
		// Para saber si lo lee correctamente.
		printf("Linea: %s", line);
		raycaster->r_map = &line;
		free(line);
		read = 1;
	}
	if (read == 0)
		printf("\nNo ha entrado en el while de lectura.\n");
	else
		printf("\nMapa leido correctamente.\n");
	close(fd);
}
