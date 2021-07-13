/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:17:21 by jarodrig          #+#    #+#             */
/*   Updated: 2020/12/18 11:24:52 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	check_params(t_config config)
{
	if (config.flag != 8)
		print_err("Faltan datos en el archivo .cub");
	if ((config.ceil[0] < 0 || config.ceil[0] > 255) ||
	(config.ceil[1] < 0 || config.ceil[1] > 255) ||
	(config.ceil[2] < 0 || config.ceil[2] > 255) ||
	(config.floor[0] < 0 || config.floor[0] > 255) ||
	(config.floor[1] < 0 || config.floor[1] > 255) ||
	(config.floor[2] < 0 || config.floor[2] > 255))
		print_err("Los valores de ceil/floor deben ser entre 0 y 255.");
}

void	check_arg(char *argum)
{
	if (!((ft_strlen(argum) == 6) && (argum[0] == '-')
	&& (argum[1] == '-') && (argum[2] == 's')
	&& (argum[3] == 'a') && (argum[4] == 'v')
	&& (argum[5] == 'e')))
		print_err("El tercer argumento debe ser '--save'");
}
