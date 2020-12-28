#include <mlx.h>

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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 600, 600);

	// Calcular siempre el desplazamiento de memoria (offset), usando la
	// longitud de la linea establecida por mlx_get_data_addr.
	// Esto es, la diferencia de memoria entre el line_length y el width de
	// la ventana. Esto se calcula con dicha formula:
	// int     offset = (y * line_length + x * (bits_per_pixel / 8));

	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = 20;
	while (i < 101)
		ft_mlx_pixel_put(&img, 20, i++, 0x00FF0000);
	i = 20;
	while (i < 101)
		ft_mlx_pixel_put(&img, i++, 20, 0x00FF0000);
	i = 20;
	while (i < 101)
		ft_mlx_pixel_put(&img, 101, i++, 0x00FF0000);
	i = 20;
	while (i < 101)
		ft_mlx_pixel_put(&img, i++, 101, 0x00FF0000);
	// ft_mlx_pixel_put(&img, 15, 16, 0x00FF0000);
	// ft_mlx_pixel_put(&img, 15, 17, 0x00FF0000);
	// ft_mlx_pixel_put(&img, 15, 18, 0x00FF0000);
	// ft_mlx_pixel_put(&img, 15, 19, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
} 
