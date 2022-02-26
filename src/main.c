#include "../mlx_linux/mlx.h"

#include "../include/fractol.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	put_pixel_in_img(t_data *d, int x, int y, int color)
{
	*(int *)&d->addr[(x * d->bpp / 8) + (y * d->bpp)] = color;
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 500, "fractol");
	img.img = mlx_new_image(mlx, 1000, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
								&img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//my_mlx_pixel_put(&img, 1, 1, 0x00FF0000);
	
	mlx_pixel_put(mlx, mlx_win, 1, 1, 0x00FF0000);
	mlx_pixel_put(mlx, mlx_win, 5, 5, 0x00FF0000);


	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

