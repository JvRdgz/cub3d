/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:59:26 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/04 18:28:19 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "../includes/cub3d.h"

void	load_textures(t_mlx *mlx, t_config *config)
{
	mlx->rc.tex[1].img = mlx_xpm_file_to_image(mlx->ptr,
			config->no, &mlx->rc.tex_width, &mlx->rc.tex_height);
	if (!mlx->rc.tex[1].img)
		print_err("Textura NO no existe");
	mlx->rc.tex[1].addr = mlx_get_data_addr(mlx->rc.tex[1].img,
			&mlx->rc.tex[1].bpp, &mlx->rc.tex[1].linesize,
			&mlx->rc.tex[1].endian);
	mlx->rc.tex[2].img = mlx_xpm_file_to_image(mlx->ptr, config->so,
			&mlx->rc.tex_width, &mlx->rc.tex_height);
	if (!mlx->rc.tex[2].img)
		print_err("Textura SO no existe");
	mlx->rc.tex[2].addr = mlx_get_data_addr(mlx->rc.tex[2].img,
			&mlx->rc.tex[2].bpp, &mlx->rc.tex[2].linesize,
			&mlx->rc.tex[2].endian);
	mlx->rc.tex[3].img = mlx_xpm_file_to_image(mlx->ptr, config->ea,
			&mlx->rc.tex_width, &mlx->rc.tex_height);
	if (!mlx->rc.tex[3].img)
		print_err("Textura EA no existe");
	mlx->rc.tex[3].addr = mlx_get_data_addr(mlx->rc.tex[3].img,
			&mlx->rc.tex[3].bpp, &mlx->rc.tex[3].linesize,
			&mlx->rc.tex[3].endian);
	load_textures_aux(mlx, config);
}

void	load_textures_aux(t_mlx *mlx, t_config *config)
{
	mlx->rc.tex[4].img = mlx_xpm_file_to_image(mlx->ptr, config->we,
			&mlx->rc.tex_width, &mlx->rc.tex_height);
	if (!mlx->rc.tex[4].img)
		print_err("Textura WE no existe");
	mlx->rc.tex[4].addr = mlx_get_data_addr(mlx->rc.tex[4].img,
			&mlx->rc.tex[4].bpp, &mlx->rc.tex[4].linesize,
			&mlx->rc.tex[4].endian);
	mlx->rc.tex[5].img = mlx_xpm_file_to_image(mlx->ptr,
			config->s, &mlx->rc.tex_width, &mlx->rc.tex_height);
	if (!mlx->rc.tex[5].img)
		print_err("Textura de Sprite no existe");
	mlx->rc.tex[5].addr = mlx_get_data_addr(mlx->rc.tex[5].img,
			&mlx->rc.tex[5].bpp, &mlx->rc.tex[5].linesize,
			&mlx->rc.tex[5].endian);
}
