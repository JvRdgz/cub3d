/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:31:56 by jarodrig          #+#    #+#             */
/*   Updated: 2021/02/27 18:26:20 by jarodrig         ###   ########.fr       */
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