/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 20:47:26 by jarodrig          #+#    #+#             */
/*   Updated: 2021/05/26 22:50:14 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h";

void		init_ray_params(t_raycaster *raycaster, t_data *data, t_player *player)
{
	data->mlx_ptr = NULL;
	data->win = NULL;
	raycaster->ceil = 0;
	raycaster->floor = 0;
	init_player(player);
	raycaster->map_lines = raycaster->max_map_lines;
	raycaster->map_rows = raycaster->max_map_rows;
	raycaster->text_side = 1;
	raycaster->text_height = 64;
	raycaster->text_width = 64;
	player->speed = 0.060;
	raycaster->w = SCREENWIDTH;
	raycaster->h = SCREENHEIGHT;
	player->up = 0;
	player->down = 0;
	player->right = 0;
	player->left = 0;
	raycaster->flag = 0;
	raycaster->sprite->save_bpm = raycaster->save;
	raycaster->sprite->sprites_count = raycaster->sprite->num_sprites;
	raycaster->sprite = ft_calloc(sizeof(t_sprite) * raycaster->sprite->num_sprites, 1);
	raycaster->sprite->sprites_buffer = (double *)malloc(sizeof(double) * raycaster->w);
	init_pos_player_ns(raycaster, data, player);
	init_pos_player_ew(raycaster, data, player);
}

void		init_pos_player_ns(t_raycaster *raycaster, t_data *data, t_player *player)
{
	if (player->first_init_pos == 'N')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (player->first_init_pos == 'S')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

void		init_pos_player_ew(t_raycaster *raycaster, t_data *data, t_player *player)
{
	if (player->first_init_pos == 'E')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = 0,66;
		player->plane_y = 0;
	}
	else if (player->first_init_pos == 'W')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}
