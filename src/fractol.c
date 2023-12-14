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
		red = 17.0 * (1.0 - t) * t * t * t * 255.0;
		green = 5.0 * (1.0 - t) * (1.0 - t) * t * t * 255.0;
		blue = 8.0 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t * 255.0;
	}
	else
	{
		red = 2.0 * (1.0 - t) * t * t * t * 255.0;
		green = 15.0 * (1.0 - t) * (1.0 - t) * t * t * 255.0;
		blue = 3.0 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t * 255.0;
	}
	return (create_trgb(0, red, green, blue));
}

void	burningship(t_data *img)
{
	t_complex	z;
	t_complex	c;
    int x;
    int y;
    int n;

    n = 0;
    y = 0;
	while (y++ < img->dim.height)
	{
		x = 0;
		while (x++ < img->dim.width)
		{
			if (x >= img->dim.start_x && y >= img->dim.start_y)
			{
				c.real = img->range.remin + x * img->pixel_size;
				c.imag = img->range.immax - y * img->pixel_size;
				z.real = 0;
				z.imag = 0;
				n = -1;
				while (n++ < NMAX - 1)
				{
					if (dot(z) > 4)
						break ;
					z = add(mult_absolute(z, z), c);
				}
				my_mlx_pixel_put(img, x, y, color_pixel(img->color, n));
			}
		}
	}
}

void	julia(t_data *img)
{
	t_complex	z;
	t_complex	c;

    int x;
    int n;

    n = 0;
	for (int y = 0; y <= img->dim.height; y++)
	{
		x = 0;
		while (x++ < img->dim.width)
		{
			if (x >= img->dim.start_x && y >= img->dim.start_y)
			{
				z.real = img->range.remin + x * img->pixel_size;
				z.imag = img->range.immax - y * img->pixel_size;
				c.real = img->c_real;
				c.imag = img->c_imag;
				n = -1;
				while (n++ < NMAX - 1)
				{
					if (dot(z) > 4)
						break ;
					z = add(mult(z, z), c);
				}
				my_mlx_pixel_put(img, x, y, color_pixel(img->color, n));
			}
		}
	}
}

void	mandelbrot(t_data *img)
{
	t_complex	z;
	t_complex	c;

    int n;
    #pragma omp parallel for
	for (int y = 0; y <= img->dim.height; y++)
	{
        #pragma omp parallel for
		for (int x = 0; x < img->dim.width; x++)
		{
			if (x >= img->dim.start_x && y >= img->dim.start_y)
			{
				c.real = img->range.remin + x * img->pixel_size;
				c.imag = img->range.immax - y * img->pixel_size;
				z.real = 0;
				z.imag = 0;
				n = -1;
				while (n++ < NMAX - 1)
				{
					if (z.real * z.real + z.imag * z.imag > 4)
						break ;
					z = add(mult(z, z), c);
				}
				my_mlx_pixel_put(img, x, y, color_pixel(img->color, n));
			}
		}
	}
}

#include <time.h>

void	fractal(t_data *img)
{
    clock_t start_time = clock();

	img->pixel_size = (img->range.remax - img->range.remin) / (float) WIDTH;
	if (!ft_strncmp(img->fractal, "mandelbrot", ft_strlen(img->fractal)))
		mandelbrot(img);
	else if (!ft_strncmp(img->fractal, "julia", ft_strlen(img->fractal)))
        julia(img);
	else if (!ft_strncmp(img->fractal, "burningship", ft_strlen(img->fractal)))
        burningship(img);

    double cpu_time_used = ((double) (clock() - start_time)) / CLOCKS_PER_SEC;

    printf("Le temps d'exécution est %f secondes.\n", cpu_time_used);
}
