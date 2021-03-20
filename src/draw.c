/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 20:50:50 by jarodrig          #+#    #+#             */
/*   Updated: 2021/03/14 19:35:51 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_draw(t_raycaster *raycaster, t_player *player)
{
	player->pos_x = 6;
	player->pos_y = 8;
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	player->time = 0;
	player->oldtime = 0;
	raycaster->w = SCREENWIDTH;
	raycaster->h = SCREENHEIGHT;
	player->up = 0;
	player->down = 0;
	player->right = 0;
	player->left = 0;
	player->speed = .2;
}

int		v_movement_toggle(int key, t_raycaster *raycaster, t_player *player)
{
	if (key == UP)
		player->up = 1;
	else if (key == DOWN)
		player->down = 1;
	else if (key == LEFT)
		player->left = 1;
	else if (key == RIGHT)
		player->right = 1;
	key_hooks(key, raycaster, player);
	return (0);
}

int		v_movement(int key, t_raycaster *raycaster, t_player *player)
{
	if (key == UP)
		player->up = 0;
	else if (key == DOWN)
		player->down = 0;
	else if (key == LEFT)
		player->left = 0;
	else if (key == RIGHT)
		player->right = 0;
	key_hooks(key, raycaster, player);
	return(0);
}

int		repeat(t_data *data)
{
	mlx_hook(data->win, 2, 0, v_movement, data);
	mlx_hook(data->win, 3, 0, v_movement_toggle, data);
	mlx_hook(data->win, 17, 0, destroy_win, data);
	return (0);
}
