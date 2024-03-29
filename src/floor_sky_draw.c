/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_sky_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:35:16 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/03 18:35:50 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/cub3d.h"

void	sky_draw(t_mlx *mlx, int x)
{
	int		y;
	int		pixel;
	int		color;

	y = 0;
	color = mlx->hexa_ceil;
	while (y < mlx->rc.draw_start)
	{
		pixel = (y * mlx->win_width + x) * 4;
		if (mlx->image.endian == 1)
		{
			mlx->image.addr[pixel + 0] = (color >> 24);
			mlx->image.addr[pixel + 1] = (color >> 16) & 0xFF;
			mlx->image.addr[pixel + 2] = (color >> 8) & 0xFF;
			mlx->image.addr[pixel + 3] = (color) & 0xFF;
		}
		else if (mlx->image.endian == 0)
		{
			mlx->image.addr[pixel + 0] = (color) & 0xFF;
			mlx->image.addr[pixel + 1] = (color >> 8) & 0xFF;
			mlx->image.addr[pixel + 2] = (color >> 16) & 0xFF;
			mlx->image.addr[pixel + 3] = (color >> 24);
		}
		y++;
	}
}

void	floor_draw(t_mlx *mlx, int x)
{
	int		y;
	int		pixel;
	int		color;

	y = mlx->rc.draw_end;
	color = mlx->hexa_floor;
	while (y < mlx->win_height)
	{
		pixel = (y * mlx->win_width + x) * 4;
		if (mlx->image.endian == 1)
		{
			mlx->image.addr[pixel + 0] = (color >> 24);
			mlx->image.addr[pixel + 1] = (color >> 16) & 0xFF;
			mlx->image.addr[pixel + 2] = (color >> 8) & 0xFF;
			mlx->image.addr[pixel + 3] = (color) & 0xFF;
		}
		else if (mlx->image.endian == 0)
		{
			mlx->image.addr[pixel + 0] = (color) & 0xFF;
			mlx->image.addr[pixel + 1] = (color >> 8) & 0xFF;
			mlx->image.addr[pixel + 2] = (color >> 16) & 0xFF;
			mlx->image.addr[pixel + 3] = (color >> 24);
		}
		y++;
	}
}
