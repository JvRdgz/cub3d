/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:41:57 by jarodrig          #+#    #+#             */
/*   Updated: 2021/01/17 15:32:32 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char *argv[])
{
	// Tiene que leer como el mapa por argumento. argc == 1.
	t_raycaster	raycaster;
	if (argc < 2)
		printf("\nNumero de argumentos invalido\n");
	else
		read_map(&raycaster, &argv[1]);
	return (0);
}