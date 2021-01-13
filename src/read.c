/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:27:23 by jarodrig          #+#    #+#             */
/*   Updated: 2021/01/12 21:14:16 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Lee el mapa .cub utilizando el get_next_line(), y se guarda en
** la variable **world_map de la estructura.
*/
void	read_map(t_player *player, t_raycaster *raycaster, char **argv)
{
	int		fd;
	int		x;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while ((x = get_next_line(fd, &line)) > 0)
	{
		// Para saber si lo lee correctamente.
		printf("%s", line);
		raycaster->r_map = line;
		free(line);
	}
	close(fd);
}