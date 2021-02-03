/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:04:27 by jarodrig          #+#    #+#             */
/*   Updated: 2021/02/03 22:48:30 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/key_linux.h"
#include "../includes/key_macos.h"
#include "../includes/select_os.h"

void			initialize_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win = mlx_new_window(data->mlx_ptr, SCREENWIDTH, SCREENHEIGTH, "cub3d");
}

void			choose_color(t_raycaster *raycaster, t_color *color)
{
	char	get_color;

	get_color = raycaster->r_map[raycaster->map_x][raycaster->map_y];
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
}

static	void	dda_algorithm(t_player *player, t_raycaster *raycaster)
{
	while (raycaster->hit == 0)
	{
		if (raycaster->side_dist_x < raycaster->side_dist_y)
		{
			raycaster->side_dist_x += raycaster->delta_dist_x;
			raycaster->map_x += raycaster->step_x;
			raycaster->side = 0;
		}
		else
		{
			raycaster->side_dist_y += raycaster->delta_dist_y;
			raycaster->map_y += raycaster->step_y;
			raycaster->side = 1;
		}
		raycaster->world_map[raycaster->map_x][raycaster->map_y] = map_aux();
		if (raycaster->world_map[raycaster->map_x][raycaster->map_y] > 0)
			raycaster->hit = 1;
	}
/*
** Calcula la distancia proyectada desde la direccion de la camara.
*/
	if (raycaster->side == 0)
		raycaster->perp_wall_dist = (raycaster->map_x - player->pos_x + (1 - raycaster->step_x) / 2) / raycaster->ray_dir_x;
	else
		raycaster->perp_wall_dist = (raycaster->map_y - player->pos_y + (1 - raycaster->step_y) / 2) / raycaster->ray_dir_y;
}

static	void	set_wall_dimensions(t_raycaster *raycaster)
{
	raycaster->line_heigth = (int)(raycaster->h / raycaster->perp_wall_dist);
	raycaster->draw_start = (((-1) * raycaster->line_heigth) / 2) + (raycaster->h / 2);
	if (raycaster->draw_start < 0)
		raycaster->draw_start = 0;
	raycaster->draw_end = (raycaster->line_heigth / 2) + (raycaster->h / 2);
	if (raycaster->draw_end >= raycaster->h)
		raycaster->draw_end = raycaster->h - 1;
}

static	void	initialize_raycaster(t_player *player, t_raycaster *raycaster, t_data *data)
{
	int			i;
/*
** 	raycaster->camerax = 2 * X / (double)data->win_width -1;
*/
	i = 0;
	while (i < SCREENWIDTH)
	{
		raycaster->camera_x = 2 * i / (double)SCREENWIDTH - 1;
		raycaster->ray_dir_x = player->dir_x + player->plane_x * raycaster->camera_x;
		raycaster->ray_dir_y = player->dir_y + player->plane_y * raycaster->camera_y;
		raycaster->delta_dist_x = abs(1 / raycaster->ray_dir_x);
		raycaster->delta_dist_y = abs(1 / raycaster->ray_dir_y);
		if (raycaster->ray_dir_x < 0)
		{
			raycaster->step_x = -1;
			raycaster->side_dist_x = raycaster->delta_dist_x * (player->pos_x - raycaster->map_x);
		}
		else
		{
			raycaster->step_x = 1;
			raycaster->side_dist_x = raycaster->delta_dist_x * ((raycaster->map_x + 1) - player->pos_x);
		}
		if (raycaster->ray_dir_y)
		{
			raycaster->step_y = -1;
			raycaster->side_dist_y = raycaster->delta_dist_y * (player->pos_y - raycaster->map_y);
		}
		else
		{
			raycaster->step_y = 1;
			raycaster->side_dist_y = raycaster->delta_dist_y * ((raycaster->map_y + 1) - player->pos_y);
		}
		dda_algorithm(player, raycaster);
		i++;
	}
}
