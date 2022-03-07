/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:36:37 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/07 02:13:13 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../include/fractol.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "fractol");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//my_mlx_pixel_put(&img, 5, 5, 16711680);

	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0)
			julia(&img);
		else if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
			mandelbrot(&img);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

