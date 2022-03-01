/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:36:37 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/01 23:55:53 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../include/fractol.h"

int	main(void)
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

/*
	int i = -1;
	while (i++ < WIDTH)
		my_mlx_pixel_put(&img, i, 0, create_trgb(0, 255, 0, 0));

	int j = 1;
	while (j++ < HEIGHT )
		my_mlx_pixel_put(&img, 0, j, create_trgb(0, 255, 0, 0));
		*/

	escape(&img);

/*
	int			n;
	t_complex	z;
	t_complex	c;

	n = -1;
	c.real = -1.5;
	c.imag = 1;
	z.real = 0;
	z.imag = 0;
	while (n++ < 10)
	{
		printf(" z mod %f\n", module(z));
		if (module(z) > 2)		//diverge
			break;
		z = add(mult(z, z), c); 	// z = z^2 + c
		printf(" z real %f\n", z.real);
		printf(" z ima %f\n", z.imag);
		printf(" n %i\n", n);
	}
*/
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

