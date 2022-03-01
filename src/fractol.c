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
	return (n * 10000);
}

void	escape(t_data *img)
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

			//printf(" c real %f\n", c.real);
			//printf(" c ima %f\n", c.imag);

			z.real = 0;
			z.imag = 0;
			n = -1;
			while (n++ < NMAX)
			{
				if (module(z) > 2)		//diverge
					break;
				z = add(mult(z, z), c); 	// z = z^2 + c
			}
			my_mlx_pixel_put(img, x, y, color_pixel(n));
		}
	}
}
