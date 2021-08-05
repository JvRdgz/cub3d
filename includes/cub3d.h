/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:22:30 by jarodrig          #+#    #+#             */
/*   Updated: 2021/08/05 21:22:32 by jarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "select_os.h"

# define PI		3.14159265359
# define SPEED 0.06
# define ROT_SPEED 0.0336
# define AMB_LIGHT 7

typedef struct s_map
{
	int				**worldmap;
}					t_map;

typedef struct s_config
{
	int				flag;
	int				flag_path;
	int				height;
	int				width;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*s;
	int				ceil[3];
	int				floor[3];
	int				**map;
	int				map_max_lines;
	int				map_max_rows;
	int				maxr;
	int				i;
	int				player_begin[2];
	char			player_pos_begin;
	int				numsprites;
	int				wall_up_down;
	int				wall_left_right;
	unsigned long	hexaceil;
	unsigned long	hexafloor;
	t_map			mapa;
}					t_config;

typedef struct s_bitmap
{
	unsigned int	filesize;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	pixeldataoffset;
	unsigned int	headersize;
	unsigned int	imagewidth;
	unsigned int	imageheight;
	unsigned short	planes;
	unsigned short	bitsperpixel;
	unsigned int	compression;
	unsigned int	imagesize;
	unsigned int	xpixelspermeter;
	unsigned int	ypixelspermeter;
	unsigned int	totalcolors;
	unsigned int	importantcolors;
}					t_bitmap;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				linesize;
	int				endian;
	int				bpp;
}					t_img;

typedef struct s_sprite
{
	int				id;
	double			x;
	double			y;
	double			dist;
	t_img			tex;
}					t_sprite;

typedef struct s_raycasting
{
	double			player_pos_x;
	double			player_pos_y;
	double			player_dir_x;
	double			player_dir_y;
	double			player_plane_x;
	double			player_plane_y;
	char			player_dir;
	double			ray_dir_x;
	double			ray_dir_y;
	double			dirx;
	double			diry;
	double			camerax;
	double			wallx;
	double			movespeed;
	int				hit;
	int				map_rows;
	int				map_lines;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	int				side;
	int				draw_start;
	int				draw_end;
	double			perp_wall_dist;
	int				line_height;
	int				up;
	int				down;
	int				right;
	int				left;
	int				run;
	int				rot_right;
	int				rot_left;
	int				hexaceil;
	int				hexafloor;
	int				tex_height;
	int				tex_width;
	int				tex_x;
	int				tex_y;
	int				tex_id;
	int				tex_side;
	int				drawstartx;
	int				drawendx;
	int				sprtexx;
	int				sprtexy;
	int				spritescreenx;
	int				spriteheight;
	double			spritex;
	double			spritey;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				stripe;
	double			transformx;
	double			transformy;
	int				d;
	int				savebpm;
	double			invdet;
	int				sprites_count;
	double			*spr_buffer;
	int				textnum;
	t_sprite		*sprite;
	t_img			tex[12];
}					t_raycasting;

typedef struct s_mlx
{
	void			*ptr;
	void			*win;
	int				win_height;
	int				win_width;
	int				flag_bmp;
	unsigned long	hexa_ceil;
	unsigned long	hexa_floor;
	int				**finalmap;
	t_img			image;
	t_raycasting	rc;
}					t_mlx;

void				final_check(t_config *config);
void				print_values(t_config config);
void				check_final_paths(t_config *config);
t_config			file_procesator(char *file, int argc);
void				check_errors(char *line, t_config config);
t_config			load_file(char *file, t_config config);
t_config			check_file(char *line, t_config config);
void				reset_t_config(t_config *config);
void				init_config(t_config *config);
t_config			check_r(char *file, t_config config);
t_config			check_cardinals(char *file, t_config config);
char				*give_me_a_path(char *line, int i);
t_config			check_ceil_floor(char *line, t_config config);
void				check_ceil_floor2(char *line);
void				check_cf(char conmut, char **splitter, t_config *config);
void				error_xpm(char *final);
char				*change_char(char *line, char a, char b);
t_map				read_map(char *file, t_config *config);
char				**read_map_aux(int fd, t_config *config, int count_sprites);
int					check_valid_map(char *line, char *chain2,
						int tab, int coincide);
int					check_valid_map_aux(int tab, int coincide);
void				check_map(t_config *config, char **map);
void				check_map_aux(t_config *config, char **map, int i, int j);
void				valid_map(char **map);
void				valid_map2(char **map, int i, int j);
void				print_map(char **map);
char				*change_char(char *line, char a, char b);
char				*fill_me(char c, int lenght);
t_map				parser(char **map, t_config *config);
void				ceil_floor_parser(t_map	*mapa, t_config *config);
unsigned long		creatergb(int r, int g, int b);
int					check_lines(char *line, char *chars);
void				check_params(t_config config);
void				drifting_r_path(char *line, t_config *config);
int					only_this_chars(char *line, char *chars);
void				check_wall(t_config *config, char **map, int i, int j);

void				init_raycast_params3(t_config *config, t_mlx *mlx);
void				init_raycast_params2(t_config *config, t_mlx *mlx);
void				init_raycast_params(t_mlx *mlx, t_config *config);
void				init_player(t_mlx *mlx, t_config *config);
int					key_press(int key, t_mlx *mlx);
int					key_release(int key, t_mlx *mlx);
void				move_right(t_mlx *mlx);
void				move_left(t_mlx *mlx);
int					handle_events(t_mlx *mlx);
void				handle_events2(t_mlx *mlx);
void				handle_events3(t_mlx *mlx);
void				handle_events4(t_mlx *mlx,
						double olddirx, double oldplanex);
void				create_window(t_mlx *mlx, t_config config);
int					exit_game(t_mlx *mlx);
int					close_win(int keycode, t_mlx *mlx);
void				reset_mlx(t_mlx *mlx, t_config config);
float				radians_to_grads(float radians);
float				grads_to_radians(float grads);
void				draw_player(t_mlx *mlx, int num);
void				draw_map(t_mlx *mlx);
void				sky_draw(t_mlx *mlx, int x);
void				floor_draw(t_mlx *mlx, int x);
void				init_raycast_params(t_mlx *mlx, t_config *config);
int					raycasting(t_mlx *mlx);
void				raycasting2(t_mlx *mlx, int x);
void				sprite_drawing2(t_mlx *mlx, int i, int y);
void				motionless_2(t_mlx *mlx, int x);
void				motionless_3(t_mlx *mlx);
void				dda(t_mlx *mlx);
void				motionless_4(t_mlx *mlx);
void				calcule_wall(t_mlx *mlx);
void				draw_wall(t_mlx *mlx, int x);
void				load_textures(t_mlx *mlx, t_config *config);
void				save_sprites_position(t_mlx *mlx);
void				sprite_casting(t_mlx *mlx);
void				sprite_casting2(t_mlx *mlx);
void				sprite_drawing(t_mlx *mlx, int i, int y);
void				sprite_order(t_mlx *mlx);
void				sprite_preorder(t_mlx *mlx);
int					save_bmp(t_mlx *mlx);
char				*ft_strjoin_char(char *str, char c);
char				*ft_strdup2(char *str, char now, int max,
						int *count_sprites);
void				change_tabs(char *finally, char c, int n);
void				double_kill(char **str);
int					what_is_higher(int a, int b);
int					char_to_num(char *str);
char				*give_me_digit_without_spaces(char *str);
void				kill(char *str);
void				double_kill(char **str);
void				ace(char *str, ...);
void				print_err(char *str);
void				ft_putstr(char *str);
int					white_spaces(char c);
void				load_textures_aux(t_mlx *mlx, t_config *config);
#endif
