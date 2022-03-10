/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:36:37 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/10 18:00:53 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc == 4 && valid_arg(argv))
	{
		img.window.mlx = mlx_init();
		img.window.window = mlx_new_window(img.window.mlx, WIDTH, HEIGHT, "fractol");
		img.img = mlx_new_image(img.window.mlx, WIDTH, HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
		img.fractal = argv[1];
		img.place = ft_atoi(argv[2]);
		img.color = ft_atoi(argv[3]);

		if (img.place == 1)		// place
			setup_place1(&img);
		if (img.place == 2)
			setup_place2(&img);

		fractal(&img);
	}
	else
		arg_error();
	mlx_put_image_to_window(img.window.mlx, img.window.window , img.img, 0, 0);
	//mlx_hook(my_window.window, 2, 0, closed, &my_window);
	//mlx_hook(my_window.window, 2, 1L<<0, closed, &my_window);=
	//mlx_hook(my_window.window, 2, 1L<<0, key_controls, &my_window);

	//mlx_key_hook(my_window.window, key_controls, &my_window);			// key pressed

	mlx_key_hook(img.window.window, key_controls, &img);			// key pressed
	//mlx_hook(my_window.window, 4, 1L<<0, mouse_press_hook, &my_window);

	mlx_mouse_hook(img.window.window, mouse_press_hook, &img);		// mouse


	//mlx_hook(mlx_win, 17, 0, close, &verra);
	mlx_hook(img.window.window, 17, 0, close_window, &img.window);		// red cross clicked
	mlx_loop(img.window.mlx);
}


int	valid_arg(char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) != 0  && ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) != 0
		&& ft_strncmp(argv[1], "burningship", ft_strlen(argv[1])) != 0 )
		return (0);
	if (ft_atoi(argv[2]) != 1 && ft_atoi(argv[2]) != 2)
		return (0);
	if (ft_atoi(argv[3]) != 1 && ft_atoi(argv[3]) != 2 && ft_atoi(argv[3]) != 3)		// degeu
		return (0);
	return (1);
}

void	arg_error()
{
	ft_putendl_fd("Arguments :", 1);
	ft_putendl_fd("fractal > 'julia' 'mandelbrot' 'burningship'", 1);
	ft_putendl_fd("place > '1' '2'", 1);
	ft_putendl_fd("color > '1' '2' '3'", 1);
	ft_putendl_fd("Controls :", 1);
	ft_putendl_fd("press arrow keys to move the view", 1);
	ft_putendl_fd("press mouse wheel to zoom in/out", 1);
	exit(EXIT_SUCCESS);
}


void	setup_place1(t_data *img)
{
	if (ft_strncmp(img->fractal, "mandelbrot", ft_strlen(img->fractal)) == 0)	// mandelbrot
	{
		img->range.remin = -2.5;
		img->range.remax = 1.5;
		img->range.immax = 1.2;
	}
	else if (ft_strncmp(img->fractal, "julia", ft_strlen(img->fractal)) == 0) // julia
	{
		img->range.remin = -2.5;
		img->range.remax = 1.5;
		img->range.immax = 1.2;
	}
	else if (ft_strncmp(img->fractal, "burningship", ft_strlen(img->fractal)) == 0)	// burningship
	{
		img->range.remin = -2.5;
		img->range.remax = 1.5;
		img->range.immax = 1.5;
	}
}

void	setup_place2(t_data *img)
{
	if (ft_strncmp(img->fractal, "mandelbrot", ft_strlen(img->fractal)) == 0)	// mandelbrot
	{
		img->range.remin = -0.75;
		img->range.remax = -0.58;
		img->range.immax = 0.5;
	}
	else if (ft_strncmp(img->fractal, "julia", ft_strlen(img->fractal)) == 0) // julia
	{
		img->range.remin = -0.75;
		img->range.remax = -0.58;
		img->range.immax = 0.5;
	}
	else if (ft_strncmp(img->fractal, "burningship", ft_strlen(img->fractal)) == 0)	// burningship
	{
		img->range.remin = -1.85;
		img->range.remax = -1.68;
		img->range.immax = 0.1;
	}
}
