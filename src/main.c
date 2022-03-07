/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:36:37 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/07 16:42:13 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	closed(int keycode, t_vars *vars)
{
	//printf("%i", keycode);
	ft_putnbr_fd(1, keycode);
	fflush(stdout);

	mlx_destroy_window(vars->mlx, vars->window);
	exit(EXIT_SUCCESS);
	return (0);
}


int	main(int argc, char **argv)
{
	t_data	img;
	t_vars	my_window;

	my_window.mlx = mlx_init();
	my_window.window = mlx_new_window(my_window.mlx, WIDTH, HEIGHT, "fractol");
	img.img = mlx_new_image(my_window.mlx, WIDTH, HEIGHT);
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


	mlx_put_image_to_window(my_window.mlx, my_window.window , img.img, 0, 0);

	//mlx_hook(my_window.window, 2, 0, closed, &my_window);
	//mlx_hook(my_window.window, 2, 1L<<0, closed, &my_window);=

	//mlx_hook(my_window.window, 2, 1L<<0, key_controls, &my_window);
	mlx_key_hook(my_window.window, key_controls, &my_window);			// mouse click

	//mlx_hook(my_window.window, 4, 1L<<0, mouse_press_hook, &my_window);
	mlx_mouse_hook(my_window.window, mouse_press_hook, &my_window);		// key pressed
	//mlx_hook(mlx_win, 17, 0, close, &verra);

	mlx_hook(my_window.window, 17, 0, close, &my_window);		// red cross clicked

	mlx_loop(my_window.mlx);
}

