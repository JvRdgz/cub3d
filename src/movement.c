/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:28:01 by jarodrig          #+#    #+#             */
/*   Updated: 2021/02/08 22:45:11 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	up_move(t_raycaster *raycaster, t_player *player)
{
	int		x;
	int		y;

	x = (int)(player->pos_x + player->dir_x * player->speed);
	y = (int)(player->pos_y + player->dir_y * player->speed);
	if (player->up == 1 && player->down == 0)
	{
		if (raycaster->world_map[x][y] == '0')
		{
			ft_putendl_fd("up", 1);
			player->pos_x += player->dir_x * player->speed;
			player->pos_y += player->dir_y * player->speed;
			// redraw();
		}
	}
}