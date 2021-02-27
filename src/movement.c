/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:28:01 by jarodrig          #+#    #+#             */
/*   Updated: 2021/02/27 12:14:35 by jarodrig         ###   ########.fr       */
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
		// if (raycaster->world_map[x][y] == '0')
		if (raycaster->world_map[x][y] == '0')
		{
			ft_putendl_fd("up", 1);
			player->pos_x += player->dir_x * player->speed;
			player->pos_y += player->dir_y * player->speed;
			// redraw(raycaster, player);
		}
	}
}

void	down_move(t_raycaster *raycaster, t_player *player)
{
	int		x;
	int		y;

	x = (int)(player->pos_x - player->dir_x * player->speed);
	y = (int)(player->pos_y - player->dir_y * player->speed);
	if (player->up == 0 && player->down == 1)
	{
		// if (raycaster->world_map[x][y] == '0')
		if (raycaster->world_map[x][y] == '0')
		{
			ft_putendl_fd("up", 1);
			player->pos_x += player->dir_x * player->speed;
			player->pos_y += player->dir_y * player->speed;
			// redraw(raycaster, player);
		}
	}
}

void	right_move(t_raycaster *raycaster, t_player *player)
{
	if (player->right == 1 && player->left == 0)
	{
		ft_putendl_fd("right", 1);
		player->old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-player->root_speed) - player->dir_y * sin(-player->root_speed);
		player->dir_y = player->old_dir_x * sin(-player->root_speed) + player->dir_y * cos(-player->root_speed);
		player->old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-player->root_speed) -
			player->plane_y * sin(-player->root_speed);
		player->plane_y = player->old_plane_x * sin(-player->root_speed) +
			player->plane_y * cos(-player->root_speed);
		// redraw(raycaster, player);
	}
}

void	left_move(t_raycaster *raycaster, t_player *player)
{
	if (player->right == 0 && player->left == 1)
	{
		ft_putendl_fd("left", 1);
		player->old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(player->root_speed) - player->dir_y * sin(player->root_speed);
		player->dir_y = player->old_dir_x * sin(player->root_speed) + player->dir_y * cos(player->root_speed);
		player->old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(player->root_speed) -
		player->plane_y * sin(player->root_speed);
		player->plane_y = player->old_plane_x * sin(player->root_speed) +
		player->plane_y * cos(player->root_speed);
		// redraw(raycaster, player);
	}
}

int		key_hooks(int key, t_raycaster *raycaster, t_player *player)
{
	if (key == ESC)
		quit("Closing...");
	else if (key == UP)
		up_move(raycaster, player);
	else if (key == DOWN)
		down_move(raycaster, player);
	else if (key == LEFT)
		left_move(raycaster, player);
	else if (key == RIGHT)
		right_move(raycaster, player);
	return(0);
}