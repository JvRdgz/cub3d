/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:31:56 by jarodrig          #+#    #+#             */
/*   Updated: 2021/05/26 22:39:13 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
void	initialize_player(t_player *player)
{
	player->pos_x = 22;
	player->pos_y = 12;
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	player->time = 0;
	player->oldtime = 0;
}
*/
/*
void	init_player(t_player *player)
{
	int		num;

	num = 200;
	if (player->up == 1 || player->down == 1)
	{
		while (num < 250)
			num += 25;
		while (num > 250)
			num -= 25;
	}
}
*/
void	init_player(t_player *player)
{
	player->pos_x = (double)player->first_pos[1] + 0.5;
	player->pos_y = (double)player->first_pos[0] + 0.5;
}
