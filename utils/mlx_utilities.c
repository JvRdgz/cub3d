/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:02:14 by jarodrig          #+#    #+#             */
/*   Updated: 2021/02/03 22:14:31 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Para salir con un mensaje.
*/

void	quit(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

/*
** Destruye la ventana.
*/
int		destroy_win(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win);
	ft_putendl_fd("Closing...", 1);
	quit("Closing");
	return (0);
}