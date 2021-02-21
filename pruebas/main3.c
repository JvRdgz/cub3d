/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:13:00 by jarodrig          #+#    #+#             */
/*   Updated: 2021/02/21 13:24:08 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

typedef	struct	s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;
/*
int		key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook! %d\n", keycode);
}
*/
int				main(void)
{
	t_vars vars;
	t_data data;
	void	*img;
	int		img_width;
	int		img_height;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	// mlx_key_hook(vars.win, key_hook, &vars); // Reconoce cuando se presiona una tecla del teclado.
	img = mlx_xpm_file_to_image(vars.mlx, "../img/wood.xpm", &img_width, &img_height);
	mlx_loop(vars.mlx);
}