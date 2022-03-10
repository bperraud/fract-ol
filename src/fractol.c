/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:36:34 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/01 20:36:34 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	color_pixel(int color, int n)
{
	float	red;
	float	green;
	float	blue;
	float	t;

	t = (float) n / NMAX;
	if (color == 1)
	{
		red = 9.0 * (1.0 - t) * t * t * t * 255.0;
		green = 15.0 * (1.0 - t) * (1.0 - t) * t * t * 255.0;
		blue = 8.5 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t * 255.0;
	}
	else if (color == 2)
	{
		red = 18.0 * (1.0 - t) * t * t * t * 255.0;
		green = 2.0 * (1.0 - t) * (1.0 - t) * t * t * 255.0;
		blue = 3.0 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t * 255.0;
	}
	else
	{
		red = 5.0 * (1.0 - t) * t * t * t * 255.0;
		green = 8.0 * (1.0 - t) * (1.0 - t) * t * t * 255.0;
		blue = 2.0 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t * 255.0;
	}
	return (create_trgb(0, red, green, blue));
}


void	burningship(t_data *img, int n, int x, int y, double pixelSize)
{
	t_complex	z;
	t_complex	c;

	while (y++ < HEIGHT)
	{
		x = -1;
		while (x++ < WIDTH)
		{
			c.real = img->range.remin + x * pixelSize;
			c.imag = img->range.immax - y * pixelSize;
			z.real = 0;
			z.imag = 0;
			n = -1;
			while (n++ < NMAX - 1)
			{
				if (module(z) > 2)
					break;
				z = mult(absolute(z), absolute(z));
				z.imag = -z.imag;
				z = add(z, c);
			}
			my_mlx_pixel_put(img, x, y, color_pixel(img->color, n));
		}
	}
}

void	julia(t_data *img, int n, int x, int y, double pixelSize)
{
	t_complex	z;
	t_complex	c;

	while (y++ < HEIGHT)
	{
		x = -1;
		while (x++ < WIDTH)
		{
			z.real = img->range.remin + x * pixelSize;
			z.imag = img->range.immax - y * pixelSize;
			c.real = CREAL;
			c.imag = CIMAG;
			n = -1;
			while (n++ < NMAX - 1)
			{
				if (module(z) > 2)
					break;
				z = add(mult(z, z), c);
			}
			my_mlx_pixel_put(img, x, y, color_pixel(img->color, n));
		}
	}
}


void	mandelbrot(t_data *img, int n, int x, int y, double pixelSize)
{
	t_complex	z;
	t_complex	c;

	while (y++ < HEIGHT)
	{
		x = -1;
		while (x++ < WIDTH)
		{
			c.real = img->range.remin + x * pixelSize;
			c.imag = img->range.immax - y * pixelSize;
			z.real = 0;
			z.imag = 0;
			n = -1;
			while (n++ < NMAX - 1)
			{
				if (module(z) > 2)
					break;
				z = add(mult(z, z), c);
			}
			my_mlx_pixel_put(img, x, y, color_pixel(img->color, n));
		}
	}
}

void	fractal(t_data *img)
{
	int			y;
	int			x;
	double		pixelSize;
	int			n;

	y = -1;
	x = -1;
	n = 0;
	pixelSize = (float)(img->range.remax - img->range.remin) / (float) WIDTH;
	if (ft_strncmp(img->fractal, "mandelbrot", ft_strlen(img->fractal)) == 0)
		mandelbrot(img, n, x, y, pixelSize);
	else if (ft_strncmp(img->fractal, "julia", ft_strlen(img->fractal)) == 0)
		julia(img, n, x, y, pixelSize);
	else if (ft_strncmp(img->fractal, "burningship", ft_strlen(img->fractal)) == 0)
		burningship(img, n, x, y, pixelSize);
}
