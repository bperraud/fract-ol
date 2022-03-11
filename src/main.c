/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:36:37 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/11 15:44:19 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc == 4 && valid_arg(argv))
	{
		set_img(argv, &img);
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
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")) != 0
		&& ft_strncmp(argv[1], "julia", ft_strlen("julia")) != 0
		&& ft_strncmp(argv[1], "burningship", ft_strlen("burningship")) != 0)
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
	ft_putendl_fd("- fractal > 'julia' 'mandelbrot' 'burningship'", 1);
	ft_putendl_fd("- place > '1' '2'", 1);
	ft_putendl_fd("- color > '1' '2' '3'", 1);
	ft_putendl_fd("Controls :", 1);
	ft_putendl_fd("- press ESC to quit", 1);
	ft_putendl_fd("- press arrow keys to move the view", 1);
	ft_putendl_fd("- press mouse wheel to zoom in/out", 1);
	exit(EXIT_SUCCESS);
}
