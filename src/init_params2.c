/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:57:13 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/03 18:57:42 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/cub3d.h"

void	reset_mlx(t_mlx *mlx, t_config config)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->win_height = config.height;
	mlx->win_width = config.width;
	mlx->finalmap = config.mapa.worldmap;
}
