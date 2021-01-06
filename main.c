#include <mlx.h>
#include <stdio.h>

// Funcion que crea colores con transparencia (TRGB)
/*
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
*/

/*
int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	// Crea una ventana de 1930x1080 con el titulo "Hello world!"
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// mlx_loop(), renderiza la ventana
	mlx_loop(mlx);
	return (0);
} 
*/

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

/**
 * Creamos mi propia version de la funcion mlx_pixel_put() que ya
 * en la propia libreria de mlx. El problema de usar la funcion
 * original, es que es demasiado lenta, dado que intenta escribir
 * los pixeles de forma instantanea en la ventana, sin esperar a
 * que se termine de renderizar.
 * */

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// int     offset = (y * line_length + x * (bits_per_pixel / 8));
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_data *data)
{
	int		i;

	i = 50;
	while (i < 101)
		ft_mlx_pixel_put(data, 50, i++, 0x00FF0000);
	i = 50;
	while (i < 101)
		ft_mlx_pixel_put(data, i++, 50, 0x00FF0000);
	i = 50;
	while (i < 101)
		ft_mlx_pixel_put(data, 101, i++, 0x00FF0000);
	i = 50;
	while (i < 101)
		ft_mlx_pixel_put(data, i++, 101, 0x00FF0000);
}

void	draw_circle(t_data *data)
{
	int		i;
	int		j;

	i = 150;
	j = 150;
	while (i < 201 && j > -1)
		ft_mlx_pixel_put(data, i++, j--, 0x00FFFFFF);
	i = 150;
	j = 0;
	while (i < 201 && j < 151)
		ft_mlx_pixel_put(data, i++, j++, 0x00FFFFFF);
}
/////////	PINTAR EN VENTANA	///////////
// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 600, 600, "Hello world!");
// 	img.img = mlx_new_image(mlx, 600, 600);

// 	// Calcular siempre el desplazamiento de memoria (offset), usando la
// 	// longitud de la linea establecida por mlx_get_data_addr.
// 	// Esto es, la diferencia de memoria entre el line_length y el width de
// 	// la ventana. Esto se calcula con dicha formula:
// 	// int     offset = (y * line_length + x * (bits_per_pixel / 8));

// 	/*
// 	** After creating an image, we can call `mlx_get_data_addr`, we pass
// 	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
// 	** then be set accordingly for the *current* data address.
// 	*/

// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	draw_square(&img);
// 	draw_circle(&img);
// 	// ft_mlx_pixel_put(&img, 15, 16, 0x00FF0000);
// 	// ft_mlx_pixel_put(&img, 15, 17, 0x00FF0000);
// 	// ft_mlx_pixel_put(&img, 15, 18, 0x00FF0000);
// 	// ft_mlx_pixel_put(&img, 15, 19, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	return (0);
// }

/**
 * Imprime ese mensaje cada vez que se pulsa una tecla.
 * Aquí iria el hook, es decir, el control de eventos con
 * las teclas del teclado que despues enviamos a la funcion
 * mlx_key_hook(), pasandole la funcion por argumento.
 **/
int		key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook! %d\n", keycode);
}

int		mouse_hook(int btn_num, t_vars *s_vars)
{
	printf("Boton %d del raton presionado.\n", btn_num);
}
/*
void	print_mouse_position(t_vars *s_vars)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	x = 0;
	// mlx_mouse_move(s_vars->mlx, s_vars->win, x, y);
	printf("(%d, %d)\n", x, y);

	mlx_loop_hook(s_vars->mlx, mlx_mouse_move(s_vars->mlx, s_vars->win, x, y), s_vars);
}
*/
////////	HOOKS	/////////////
// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	mlx_key_hook(vars.win, key_hook, &vars); // Reconoce cuando se presiona una tecla del teclado.
// 	// mlx_mouse_hook(vars.win, mouse_hook, &vars); // Reconoce cuando se presiona un boton del raton
// 	mlx_mouse_move(vars.mlx, vars.win, 150, 150); // El puntero del raton aparece en las coordenadas que se le indiquen en el argumento.
// 	// printf("mlx_mouse_move(): %d", mlx_mouse_move(vars.mlx, vars.win, 150, 150));
// 	// mlx_mouse_show(vars.mlx, vars.win); // Muestra el puntero del raton por la ventana cuando éste pasa por encima.
// 	// mlx_mouse_hide(vars.mlx, vars.win); // Desaparece el puntero del raton cuando éste se mueve por la ventana.
// 	// print_mouse_position(&vars);
// 	mlx_loop(vars.mlx);
// 	return (0);
// }

int		close(int keycode, t_vars *vars)
{
	// Si se pulsa la letra ESC
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	printf("\nKey pressed: %d\n", keycode);
}
////////////	EVENTOS		///////////////
int		main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello World!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}