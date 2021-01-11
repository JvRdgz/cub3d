#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

typedef	struct	s_data
{
    void    *mlx_ptr;
    void    *win;
    struct      s_img
    {
        void	*img_ptr;
	    int	    *addr;
	    int	bits_per_pixel;
	    int	line_length;
	    int	endian;
    }   t_img;
    
}		t_data;

int     main(void)
{
    t_data  mlx;
    int     count_w;
    int     count_h;

    count_h = -1;
    mlx.mlx_ptr = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx_ptr, 800, 900, "Hello World!");
    mlx.t_img.img_ptr = mlx_new_image(mlx.mlx_ptr, 800, 900);
    mlx.t_img.addr = (int *) mlx_get_data_addr(mlx.t_img.img_ptr,
        &mlx.t_img.bits_per_pixel, &mlx.t_img.line_length, &mlx.t_img.endian);
    
    while (++count_h < 900)
    {
        count_w = -1;
        while (++count_w < 800)
        {
            if (count_w % 2)
                mlx.t_img.addr[count_h * 800 + count_w] = 0xFF0000;
            else
                mlx.t_img.addr[count_h * 800 + count_w] = 0;
        }
    }
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.t_img.img_ptr, 0, 0);
    mlx_loop(mlx.mlx_ptr);
    return (0);
}