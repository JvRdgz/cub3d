/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:41:57 by jarodrig          #+#    #+#             */
/*   Updated: 2021/01/11 13:01:00 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	// Tiene que leer como el mapa por argumento. argc == 1.
	t_raycaster	raycaster;
	if (argc < 1)
		printf("\nNumero de argumentos invalido\n");
	else
	{
		printf("\nLeyendo mapa:\n");
		read_map(&raycaster, &argv[1]);
		printf("\nMapa leido.\n");
	}
	return (0);
}
