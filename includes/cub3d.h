/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:36:00 by jarodrig          #+#    #+#             */
/*   Updated: 2021/02/08 22:35:11 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define MAPWIDTH 24
# define MAPHEIGTH 24
/*
** Coger la resolucion del archivo del mapa con el gnl
*/
# define SCREENWIDTH 640
# define SCREENHEIGTH 480
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line_bonus.h"
# include "key_linux.h"
// # include "key_macos.h"
# include "select_os.h"
# include "../libft/libft.h"

typedef	struct	s_data
{
	void		*mlx_ptr;
	void		*win;
	struct		s_img
	{
		void	*img_ptr;
		int		*addr;
		int		bits_per_pixel;
		int		line_length;
		int		endian;
	}			t_img;
}				t_data;

typedef	struct	s_player
{
/*
** Posiciones del jugador
*/
	double		pos_x;
	double		pos_y;
/*
** Direccion del jugador
*/
	double		dir_x;
	double		dir_y;
/*
** Plano de la camara del jugador
** (Perpendicular a dir, aunque puede cambiar length)
*/
	double		plane_x;
	double		plane_y;
	// FOV = length de dir: length del plano de la camara.
/*
** Tiempo. Determina cuanto debe moverse el jugador entre frames.
*/
	double		time;
	double		oldtime;
/*
** Velocidad del jugador
*/
	double		speed;
/*
** Variables de direccion del personaje.
*/
	int			up;
	int			down;
	int			left;
	int			right;
}				t_player;

typedef	struct	s_raycaster
{
/*
** Variables para el loop del raycasting:
** camerax => Coordenada x del plano de la camara representada en
** la pantalla del lado derecho de la pantalla = 1; centro = 0;
** izquierdo = -1
*/
	double		camera_x;
	double		camera_y;
	double		ray_dir_x;
	double		ray_dir_y;
/*
** Variables del mapa que representan el cuadrado actual del mapa
** en el que se encuentra el rayo.
*/
	int			map_x;
	int			map_y;
/*
** Distancia de recorrido del rayo. (raycasting)
** side_direct_x: distancia desde el comienzo del rayo hasta la
** 		primera interseccion con X
** side_direct_y: distancia desde el comienzo del rayo hasta la
**		primera interseccion con Y.
** delta_direct_x: distancia de la interseccion de X hasta la
**		siguiente interseccion de X.
** delta_direct_y: distancia de la interseccion de Y hasta la
**		siguiente interseccion de Y.
*/
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
/*
** Para calcular la longitud del rayo:
*/
	double		perp_wall_dist;
/*
** Direccion del rayo para ver si los rayos se mueven en:
** + o - X o Y
*/
	double		step_x;
	double		step_y;
/*
** Variable booleana para saber si el rayo ha golpeado la pared.
*/
	double		hit;
/*
** Variable booleana para saber que lado es el golpeado.
** Si el lado golpeado es el de X, entonces side = 0
** Si el lado golpeado es el de Y, entonces side = 1.
*/
	double		side;
/*
** Variable del mapa para algoritmo DDA. Es de tipo int debido a que
** de esta forma nos permitira saber cuando estamos chocando contra una pared
** (1) o no (0).
*/
	int			**world_map;
/*
** Variable para guardar el mapa leido.
*/
	char		**r_map;
/*
** h es la altura en pixeles de la pantalla, para llevarlas a las
** coordenadas del pixel. Podemos multiplicar h por lo que sea para
** hacer las paredes mas altas.
*/
	double		h;
/*
**  Para calcular la altura de la linea que se va a dibujar en la pantalla.
*/
	double		line_heigth;
/*
** Para calcular la altura mas alta y mas baja de la misma pared.
*/
	double		draw_start;
	double		draw_end;
/*
** Variable para calcular el length total del gnl
*/
	size_t		gnl_length;
}				t_raycaster;
/*
** Gestion de colores.
*/
typedef	struct	s_color
{
	int			color;
	int			x_color;
	int			y_color;
}				t_color;

// typedef	struct		s_map
// {
// /*
// ** Variable del mapa para algoritmo DDA.
// */
// 	int				**world_map;
// }					t_map;
static	void	initialize_raycaster(t_player *player, t_raycaster *raycaster, t_data *data);
static	void	dda_algorithm(t_player *player, t_raycaster *raycaster);
static	void	set_wall_dimensions(t_raycaster *raycaster);
void			read_file(t_raycaster *raycaster, char **argv);
void			memory_allocation(t_raycaster *raycaster, char *line);
size_t			gnl_size(char *line);
void			read_map(t_raycaster *raycaster, int *fd, char *line);
static	int		**map_aux();
void			initialize_window(t_data *data);
void			initialize_player(t_player *player);
int				destroy_win(t_data *data);
void			quit(char *str);
void			choose_color(t_raycaster *raycaster, t_color *color);
void			init_draw(t_raycaster *raycaster, t_player *player);
void			up_move(t_raycaster *raycaster, t_player *player);
void			down_move(t_raycaster *raycaster, t_player *player);
void			left_move(t_raycaster *raycaster, t_player *player);
void			right_move(t_raycaster *raycaster, t_player *player);

#endif
