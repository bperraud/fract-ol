/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:36:37 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/11 00:01:09 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc == 4 && valid_arg(argv))
	{
		img.win.mlx = mlx_init();
		img.win.window = mlx_new_window(img.win.mlx, WIDTH, HEIGHT, "fractol");
		img.img = mlx_new_image(img.win.mlx, WIDTH, HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.endian);
		img.fractal = argv[1];
		img.place = ft_atoi(argv[2]);
		img.color = ft_atoi(argv[3]);
		if (img.place == 1)
			setup_place1(&img);
		if (img.place == 2)
			setup_place2(&img);
		fractal(&img);
	}
	else
		arg_error();
	mlx_put_image_to_window(img.win.mlx, img.win.window, img.img, 0, 0);
	mlx_key_hook(img.win.window, key_controls, &img);
	mlx_mouse_hook(img.win.window, mouse_press_hook, &img);
	mlx_hook(img.win.window, 17, 0, close_window, &img.win);
	mlx_loop(img.win.mlx);
}

int	valid_arg(char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) != 0
		&& ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) != 0
		&& ft_strncmp(argv[1], "burningship", ft_strlen(argv[1])) != 0)
		return (0);
	if (ft_atoi(argv[2]) != 1 && ft_atoi(argv[2]) != 2)
		return (0);
	if (ft_atoi(argv[3]) != 1 && ft_atoi(argv[3]) != 2 && ft_atoi(argv[3]) != 3)
		return (0);
	return (1);
}

void	arg_error(void)
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
	if (!ft_strncmp(img->fractal, "mandelbrot", ft_strlen(img->fractal)))
	{
		img->range.remin = -2.5;
		img->range.remax = 1.5;
		img->range.immax = 1.2;
	}
	else if (!ft_strncmp(img->fractal, "julia", ft_strlen(img->fractal)))
	{
		img->range.remin = -2.5;
		img->range.remax = 1.5;
		img->range.immax = 1.2;
	}
	else if (!ft_strncmp(img->fractal, "burningship", ft_strlen(img->fractal)))
	{
		img->range.remin = -2.5;
		img->range.remax = 1.5;
		img->range.immax = 1.5;
	}
}

void	setup_place2(t_data *img)
{
	if (!ft_strncmp(img->fractal, "mandelbrot", ft_strlen(img->fractal)))
	{
		img->range.remin = -0.75;
		img->range.remax = -0.58;
		img->range.immax = 0.5;
	}
	else if (!ft_strncmp(img->fractal, "julia", ft_strlen(img->fractal)))
	{
		img->range.remin = -0.75;
		img->range.remax = -0.58;
		img->range.immax = 0.5;
	}
	else if (!ft_strncmp(img->fractal, "burningship", ft_strlen(img->fractal)))
	{
		img->range.remin = -1.85;
		img->range.remax = -1.68;
		img->range.immax = 0.1;
	}
}
