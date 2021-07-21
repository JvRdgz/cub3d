/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:35:10 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/21 16:32:20 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/cub3d.h"

void		reset_mlx(t_mlx *mlx, t_config config)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->win_height = config.height;
	mlx->win_width = config.width;
	mlx->finalmap = config.mapa.worldmap;
}
