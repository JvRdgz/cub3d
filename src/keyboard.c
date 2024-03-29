/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:58:33 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/03 18:58:44 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/cub3d.h"

int	key_press(int key, t_mlx *mlx)
{
	if (key == KEY_UP || key == KEY_W)
		mlx->rc.up = 1;
	if (key == KEY_DOWN || key == KEY_S)
		mlx->rc.down = 1;
	if (key == KEY_RIGHT)
		mlx->rc.rot_right = 1;
	if (key == KEY_D)
		mlx->rc.right = 1;
	if (key == KEY_LEFT)
		mlx->rc.rot_left = 1;
	if (key == KEY_A)
		mlx->rc.left = 1;
	if (key == KEY_SHIFT_L)
		mlx->rc.run = 1;
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(mlx->ptr);
		exit(-1);
	}
	return (0);
}

int	key_release(int key, t_mlx *mlx)
{
	if (key == KEY_UP || key == KEY_W)
		mlx->rc.up = 0;
	if (key == KEY_DOWN || key == KEY_S)
		mlx->rc.down = 0;
	if (key == KEY_RIGHT)
		mlx->rc.rot_right = 0;
	if (key == KEY_D)
		mlx->rc.right = 0;
	if (key == KEY_LEFT)
		mlx->rc.rot_left = 0;
	if (key == KEY_A)
		mlx->rc.left = 0;
	if (key == KEY_SHIFT_L)
		mlx->rc.run = 0;
	return (0);
}
