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

#include "../mlx_linux/mlx.h"
#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


int	color_pixel(int n)
{
	float	red;
	float	green;
	float	blue;
	float	t;

	t = (float) n / NMAX;
	red = 9.0 * (1.0 - t) * t * t * t * 255.0;
	green = 15.0 * (1.0 - t) * (1.0 - t) * t * t * 255.0;
	blue = 8.5 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t * 255.0;
	return (create_trgb(0, red, green, blue));
}

void	mandelbrot(t_data *img)
{
	int			y;
	int			x;
	int			n;
	t_complex	z;
	t_complex	c;

	double pixelSize = (float)(Remax - Remin) / (float) WIDTH;
	y = -1;
	x = -1;
	while (y++ < HEIGHT)
	{
		x = -1;
		while (x++ < WIDTH)
		{
			c.real = Remin + x * pixelSize;
			c.imag = Immax - y * pixelSize;
			z.real = 0;
			z.imag = 0;
			n = -1;
			while (n++ < NMAX - 1)		// n = NMAX possible, sinon n > NMAX apres le ++
			{
				if (module(z) > 2)		//diverge
					break;
				z = add(mult(z, z), c); 	// z = z^2 + c
			}
			my_mlx_pixel_put(img, x, y, color_pixel(n));
		}
	}
}

void	julia(t_data *img)
{
	int			y;
	int			x;
	int			n;
	t_complex	z;
	t_complex	c;

	double pixelSize = (float)(Remax - Remin) / (float) WIDTH;
	y = -1;
	x = -1;
	while (y++ < HEIGHT)
	{
		x = -1;
		while (x++ < WIDTH)
		{
			z.real = Remin + x * pixelSize;
			z.imag = Immax - y * pixelSize;
			c.real = 0.285;
			c.imag = 0.01;
			n = -1;
			while (n++ < NMAX - 1)		// n = NMAX possible, sinon n > NMAX apres le ++
			{
				if (module(z) > 2)		//diverge
					break;
				z = add(mult(z, z), c); 	// z = z^2 + c
			}
			my_mlx_pixel_put(img, x, y, color_pixel(n));
		}
	}
}
