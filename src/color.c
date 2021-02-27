/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:38:12 by jarodrig          #+#    #+#             */
/*   Updated: 2021/02/17 22:29:35 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			choose_color(t_raycaster *raycaster, t_color *color)
{
	char	get_color;

	// get_color = raycaster->r_map[raycaster->map_x][raycaster->map_y];
	get_color = raycaster->world_map[raycaster->map_x][raycaster->map_y];
	if (get_color == '1')
		color->color = 0x00FFFF;
	else if (get_color == '2')
		color->color = 0x0000FF;
	else if (get_color == '3')
		color->color = 0x9400D3;
	else if (get_color == '4')
		color->color = 0xFF8C00;
	else if (get_color == '0')
		color->color = 0x008080;
	if (raycaster->side == 1)
		color->color /= 2;
}
