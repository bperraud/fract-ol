/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:33:59 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/10 23:49:32 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	exit(EXIT_SUCCESS);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	create_img(t_data *img)
{
	fractal(img);
	mlx_put_image_to_window(img->window.mlx, img->window.window, img->img, 0, 0);
}

int	key_controls(int keycode, t_data *img)
{
	float	move;

	move = (img->range.remax - img->range.remin) * MOVE ;
	if (keycode == KEY_ESC)
		close_window(&img->window);
	else if (keycode == KEY_LEFT)
		move_left(move, img);
	else if (keycode == KEY_RIGHT)
		move_right(move, img);
	else if (keycode == KEY_UP)
		move_up(move, img);
	else if (keycode == KEY_DOWN)
		move_down(move, img);
	create_img(img);
	return (0);
}
