/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processor_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 21:14:56 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/05 19:26:21 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_params(t_config config)
{
	if (config.flag != 8)
		print_err("Faltan datos por especificar en el .cub");
	if ((config.ceil[0] < 0 || config.ceil[0] > 255)
		|| (config.ceil[1] < 0 || config.ceil[1] > 255)
		|| (config.ceil[2] < 0 || config.ceil[2] > 255)
		|| (config.floor[0] < 0 || config.floor[0] > 255)
		|| (config.floor[1] < 0 || config.floor[1] > 255)
		|| (config.floor[2] < 0 || config.floor[2] > 255))
		print_err("Los valores de C y F deben estar entre 0 y 255.");
}
