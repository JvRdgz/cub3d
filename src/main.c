/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:41:57 by jarodrig          #+#    #+#             */
/*   Updated: 2021/02/11 20:22:39 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(void)
{
	t_data		data;
	t_player	player;
	t_raycaster	raycaster;

	initialize_player(&player);
	initialize_window(&data);
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