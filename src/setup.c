/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:35:21 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/11 17:25:34 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
		img->range.remin = -2.0;
		img->range.remax = 1.8;
		img->range.immax = 1.2;
		img->c_real = -0.4;
		img->c_imag = 0.6;
	}
	else if (!ft_strncmp(img->fractal, "burningship", ft_strlen(img->fractal)))
	{
		img->range.remin = -2.5;
		img->range.remax = 1.5;
		img->range.immax = 1.7;
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
		img->range.remin = -2.0;
		img->range.remax = 1.8;
		img->range.immax = 1.2;
		img->c_real = 0.285;
		img->c_imag = 0.01;
	}
	else if (!ft_strncmp(img->fractal, "burningship", ft_strlen(img->fractal)))
	{
		img->range.remin = -1.85;
		img->range.remax = -1.68;
		img->range.immax = 0.1;
	}
}

void	set_img(char **argv, t_data *img)
{
	img->win.mlx = mlx_init();
	img->win.window = mlx_new_window(img->win.mlx, WIDTH, HEIGHT, "fractol");
	img->img = mlx_new_image(img->win.mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
	img->fractal = argv[1];
	img->place = ft_atoi(argv[2]);
	img->color = ft_atoi(argv[3]);
	img->dim.height = HEIGHT;
	img->dim.width = WIDTH;
	img->dim.start_x = 0;
	img->dim.start_y = 0;
}
