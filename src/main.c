/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:41:57 by jarodrig          #+#    #+#             */
/*   Updated: 2021/03/03 21:33:34 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(void)
{
	t_data		data;
	t_player	player;
	t_raycaster	raycaster;
	t_color		color;
	t_img		img;

	// map_aux_hardcoded(&raycaster);
	// map_aux(&raycaster);
	// initialize_player(&player);
	initialize_window(&raycaster, &data, &player, &color, &img);
	// initialize_raycaster(&player, &raycaster, &data);
	return (0);
}

/*
int		main(int argc, char *argv[])
{
	// Tiene que leer como el mapa por argumento. argc == 1.
	t_raycaster	raycaster;
	if (argc < 2)
		printf("\nNumero de argumentos invalido\n");
	else
	{
		read_file(&raycaster, &argv[1]);
		printf("\nMAPA: %s|\n", *raycaster.r_map);
	}
	return (0);
}
*/
