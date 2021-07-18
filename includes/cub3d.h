/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <jarodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:36:00 by jarodrig          #+#    #+#             */
/*   Updated: 2021/05/26 22:50:13 by jarodrig         ###   ########.fr       */
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
# define SCREENHEIGHT 480
# include <mlx.h>
# include "../libft/libft.h"
// # include "../mlx/minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line_bonus.h"
# include "key_linux.h"
# include "key_macos.h"
# include "select_os.h"

typedef	struct			s_data
{
	void				*mlx_ptr;
	void				*win;
}						t_data;

/*
** Estructura para control de memoria de la imagen.
*/
typedef	struct			s_img
{
	void				*img_ptr;
	char				*addr;
	// int					*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_img;

typedef	struct			s_player
{
/*
** Posiciones del jugador
*/
	double				pos_x;
	double				pos_y;
	int					first_pos[2];
	char				first_init_pos;
/*
** Direccion del jugador
*/
	double				dir_x;
	double				dir_y;
/*
** ¿?
*/
	double				old_dir_x;
	double				old_plane_x;
	double				root_speed;
/*
** Plano de la camara del jugador
** (Perpendicular a dir, aunque puede cambiar length)
*/
	double				plane_x;
	double				plane_y;
	// FOV = length de dir: length del plano de la camara.
/*
** Tiempo. Determina cuanto debe moverse el jugador entre frames.
*/
	double				time;
	double				oldtime;
/*
** Velocidad del jugador
*/
	double				speed;
/*
** Variables de direccion del personaje.
*/
	int					up;
	int					down;
	int					left;
	int					right;
}						t_player;

typedef struct			s_sprite
{
	int					id;
	double				x;
	double				y;
	double				dist;
	int					save_bpm;
	int					sprites_count;
	int					num_sprites;
	double				*sprites_buffer;
	t_img				text;
}						t_sprite;

typedef	struct			s_raycaster
{
/*
** Variables para el loop del raycasting:
** camerax => Coordenada x del plano de la camara representada en
** la pantalla del lado derecho de la pantalla = 1; centro = 0;
** izquierdo = -1
*/
	double				camera_x;
	double				camera_y;
	double				ray_dir_x;
	double				ray_dir_y;
/*
** Variables del mapa que representan el cuadrado actual del mapa
** en el que se encuentra el rayo.
*/
	int					map_x;
	int					map_y;
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
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
/*
** Para calcular la longitud del rayo:
*/
	double				perp_wall_dist;
/*
** Direccion del rayo para ver si los rayos se mueven en:
** + o - X o Y
*/
	double				step_x;
	double				step_y;
/*
** Variable booleana para saber si el rayo ha golpeado la pared.
*/
	double				hit;
/*
** Variable booleana para saber que lado es el golpeado.
** Si el lado golpeado es el de X, entonces side = 0
** Si el lado golpeado es el de Y, entonces side = 1.
*/
	double				side;
/*
** Variable del mapa para algoritmo DDA. Es de tipo int debido a que
** de esta forma nos permitira saber cuando estamos chocando contra una pared
** (1) o no (0).
*/
// char		*world_map[MAPHEIGTH];
	int					world_map[MAPHEIGTH][MAPWIDTH];
/*
** Variable para guardar el mapa leido.
*/
	char				**r_map;
/*
**  Para calcular la altura de la linea que se va a dibujar en la pantalla.
*/
	double				line_heigth;
/*
** Para calcular la altura mas alta y mas baja de la misma pared.
*/
	double				draw_start;
	double				draw_end;
/*
** Variable para calcular el length total del gnl
*/
	size_t				gnl_length;
/*
** Variables para el procesamiento de imagenes
*/
	void				*img;
/*
** h es la altura en pixeles de la pantalla, para llevarlas a las
** coordenadas del pixel. Podemos multiplicar h por lo que sea para
** hacer las paredes mas altas.
*/
	int					h;
	int					w;
/*
** ¿?
*/
	int					x;
	int					y;
	int					d;

/*
** Techo y suelo
*/
	int					ceil[3];
	int					floor[3];
	unsigned	long			hexaceil;
	unsigned	long			hexafloor;

/*
** Filas y columnas
*/
	int					map_lines;
	int					map_rows;
	int					max_map_lines;
	int					max_map_rows;

	int					save;

/*
 ** Texturizado
*/

	int					text_num;
	int					text_height;
	int					text_width;
	int					text_x;
	int					text_y;
	int					text_id;
	int					text_side;

/*
** SPRITES
*/
	t_sprite			*sprite;
	int					flag;
/*
 ** Instanciacion de img
*/
	t_img				text[12];
/*
** Variables para el procesamiento de datos.
*/
	int					flag;
	int					flag_path;
	char					*no;
	char					*so;
	char					*ea;
	char					*we;
	char					*s;
	int					i;
	int					wall_left_right;
	int					wall_up_down;
}						t_raycaster;
/*
** Gestion de colores.
*/
typedef	struct			s_color
{
	int					color;
	int					x_color;
	int					y_color;
}						t_color;

// typedef	struct		s_map
// {
// /*
// ** Variable del mapa para algoritmo DDA.
// */
// 	int					**world_map;
// }					t_map;
// int					map_aux();

// void					map_aux_hardcoded(t_raycaster *raycaster);
int						map_aux();
void					initialize_raycaster(t_player *player, t_raycaster *raycaster, t_data *data, t_color *color);
void					dda_algorithm(t_player *player, t_raycaster *raycaster, t_color *color);
void					set_wall_dimensions(t_raycaster *raycaster, t_player *player, t_color *color);
// void					read_file(t_raycaster *raycaster, char **argv);
void					memory_allocation(t_raycaster *raycaster, char *line);
size_t					gnl_size(char *line);
void					read_map(t_raycaster *raycaster, int *fd, char *line);
void					initialize_window(t_raycaster *raycaster, t_data *data, t_player *player, t_color *color, t_img *img);
// void					initialize_player(t_player *player);
int						destroy_win(t_data *data);
void					quit(char *str);
int						choose_color(t_raycaster *raycaster, t_color *color);
void					init_draw(t_raycaster *raycaster, t_player *player);
void					up_move(t_raycaster *raycaster, t_player *player);
void					down_move(t_raycaster *raycaster, t_player *player);
void					left_move(t_raycaster *raycaster, t_player *player);
void					right_move(t_raycaster *raycaster, t_player *player);
int						key_hooks(int key, t_raycaster *raycaster, t_player *player);
void					init_player(t_player *player);
int						repeat(t_data *data);
int						v_movement(int key, t_raycaster *raycaster, t_player *player);
int						v_movement_toggle(int key, t_raycaster *raycaster, t_player *player);
void					raycasting_control(t_player *player, t_raycaster *raycaster, t_data *data, t_color *color);
void					init_ray_params(t_raycaster *raycaster, t_data *data, t_player *player);
// void					load_img(t_data *data, t_raycaster *raycaster, t_img *img);
void					init_pos_player_ns(t_raycaster *raycaster, t_data *data, t_player *player);
void					init_pos_player_ew(t_raycaster *raycaster, t_data *data, t_player *player);
void					drifting_r_path(char *line, t_raycaster *raycaster);

#endif
