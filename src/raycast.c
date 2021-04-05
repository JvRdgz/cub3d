/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:04:27 by jarodrig          #+#    #+#             */
/*   Updated: 2021/03/03 21:17:22 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			initialize_window(t_raycaster *raycaster, t_data *data, t_player *player, t_color *color, t_img *img)
{
	// char	*path;

	// path = "../img/wood.xpm";
	raycaster->x = -1;
	data->mlx_ptr = mlx_init();
	img->img_ptr = mlx_new_image(data->mlx_ptr, SCREENWIDTH, SCREENHEIGHT);
	data->win = mlx_new_window(data->mlx_ptr, SCREENWIDTH, SCREENHEIGHT, "cub3d");
	// img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &(raycaster->w), &(raycaster->h));
	// load_img(data, raycaster, img);
	img->addr = mlx_get_data_addr(img->img_ptr, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	init_draw(raycaster, player);
	while (++raycaster->x < raycaster->w)
		initialize_raycaster(player, raycaster, data, color);
	mlx_put_image_to_window(data->mlx_ptr, data->win, img->img_ptr, 0, 0);
	init_player(player);
	mlx_loop_hook(data->mlx_ptr, repeat, data);
	// printf("\nFFF\n");
	mlx_loop(data->mlx_ptr);
}

/*
void			load_img(t_data *data, t_raycaster *raycaster, t_img *img)
{
	char	*path;

	path = "../img/wood.xpm";
	img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &(raycaster->img_width), &(raycaster->img_height));
}
*/

/*
void          calc_wall_height(t_raycaster *rc)
{
  int         line_height;

  if (rc->side == 0)
    rc->perp_wall_dist = (rc->map_x - rc->player_pos_x + (1 - rc->step_x) / 2) / rc->ray_dir_x;
  else
    rc->perp_wall_dist = (rc->map_y - rc->player_pos_y + (1 - rc->step_y) / 2) / rc->ray_dir_y;
  line_height = (int)(WIN_Y / rc->perp_wall_dist);
  rc->draw_start = -line_height / 2 + WIN_Y / 2;
  if (rc->draw_start < 0)
    rc->draw_start = 0;
  rc->draw_end = line_height / 2 + WIN_Y / 2;
  if (rc->draw_end >= WIN_Y)
    rc->draw_end = WIN_Y - 1;
}
*/
/*
void			draw_wall(t_data *data, t_raycaster *raycaster)
{
	int		line_height;

	if (raycaster->side == 0)
		raycaster->perp_wall_dist = 
}
*/

void			set_wall_dimensions(t_raycaster *raycaster, t_color *color)
{
	raycaster->line_heigth = (int)(raycaster->h / raycaster->perp_wall_dist);
	raycaster->draw_start = (((-1) * raycaster->line_heigth) / 2) + (raycaster->h / 2);
	if (raycaster->draw_start < 0)
		raycaster->draw_start = 0;
	raycaster->draw_end = (raycaster->line_heigth / 2) + (raycaster->h / 2);
	if (raycaster->draw_end >= raycaster->h)
		raycaster->draw_end = raycaster->h - 1;
	choose_color(raycaster, color);
	if (raycaster->side == 1)
		color->color = color->color / 2;
}

void			dda_algorithm(t_player *player, t_raycaster *raycaster, t_color *color)
{
	while (raycaster->hit == 0)
	{
		if (raycaster->side_dist_x < raycaster->side_dist_y)
		{
			printf("1");
			raycaster->side_dist_x += raycaster->delta_dist_x;
			raycaster->map_x += raycaster->step_x;
			raycaster->side = 0;
		}
		else
		{
			printf("2");
			raycaster->side_dist_y += raycaster->delta_dist_y;
			raycaster->map_y += raycaster->step_y;
			raycaster->side = 1;
		}
		// raycaster->world_map[raycaster->map_x][raycaster->map_y] = map_aux();
		// if (raycaster->world_map[raycaster->map_x][raycaster->map_y] > 0)
		if (raycaster->world_map[raycaster->map_x][raycaster->map_y] != '0')
		{
			raycaster->hit = 1;
			printf("3");
		}
	}
/*
** Calcula la distancia proyectada desde la direccion de la camara.
*/
	if (raycaster->side == 0)
	{
		printf("4");
		raycaster->perp_wall_dist = (raycaster->map_x - player->pos_x + (1 - raycaster->step_x) / 2) / raycaster->ray_dir_x;
		// printf("perp_wall_dist: %f", raycaster->perp_wall_dist);
	}
	else
	{
		printf("5");
		raycaster->perp_wall_dist = (raycaster->map_y - player->pos_y + (1 - raycaster->step_y) / 2) / raycaster->ray_dir_y;
	}
	set_wall_dimensions(raycaster, color);
}

void			initialize_raycaster(t_player *player, t_raycaster *raycaster, t_data *data, t_color *color)
{
	int			i;
/*
** 	raycaster->camerax = 2 * X / (double)data->win_width -1;
*/
	i = 0;
	while (i < SCREENWIDTH)
	{
		// raycaster->world_map[raycaster->map_x][raycaster->map_y] = map_aux();
		// raycaster->world_map[raycaster->map_x][raycaster->map_y];
		raycaster->camera_x = 2 * i / (double)raycaster->w - 1;
		raycaster->ray_dir_x = player->dir_x + player->plane_x * raycaster->camera_x;
		raycaster->ray_dir_y = player->dir_y + player->plane_y * raycaster->camera_y;
		raycaster->map_x = (int)player->pos_x;
		raycaster->map_y = (int)player->pos_y;
		// raycaster->delta_dist_x = abs(1 / raycaster->ray_dir_x);
		// raycaster->delta_dist_y = abs(1 / raycaster->ray_dir_y);
		raycaster->delta_dist_x = sqrt(1 + pow(raycaster->ray_dir_y, 2) / pow(raycaster->ray_dir_x, 2));
		raycaster->delta_dist_y = sqrt(1 + pow(raycaster->ray_dir_x, 2) / pow(raycaster->ray_dir_y, 2));
		// printf("HOLA");
		if (raycaster->ray_dir_x < 0)
		{
			raycaster->step_x = -1;
			raycaster->side_dist_x = raycaster->delta_dist_x * (player->pos_x - raycaster->map_x);
		}
		else
		{
			raycaster->step_x = 1;
			// raycaster->side_dist_x = raycaster->delta_dist_x * ((raycaster->map_x + 1) - player->pos_x);
			raycaster->side_dist_x = (raycaster->map_x + 1.0 - player->pos_x) * raycaster->delta_dist_x;
		}
		if (raycaster->ray_dir_y < 0)
		{
			raycaster->step_y = -1;
			raycaster->side_dist_y = raycaster->delta_dist_y * (player->pos_y - raycaster->map_y);	
		}
		else
		{
			raycaster->step_y = 1;
			// raycaster->side_dist_y = raycaster->delta_dist_y * ((raycaster->map_y + 1) - player->pos_y);
			raycaster->side_dist_y = (raycaster->map_y + 1.0 - player->pos_y) * raycaster->delta_dist_y;
		}
		dda_algorithm(player, raycaster, color);
		i++;
	}
}
