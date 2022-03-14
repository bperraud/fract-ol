/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:49:40 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/14 17:37:40 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	move_up(float move, t_data *img)
{
	int	diff;
	int	x;
	int	y;

	diff = MOVE * img->dim.height;
	x = img->dim.width;
	while (x--)
	{
		y = img->dim.height;
		while (y--)
		{
			if (y > diff)
				my_mlx_pixel_put(img, x, y, get_mlx_pixel(img, x, y - diff));
		}
	}
	img->range.immax += move * ( (float) img->dim.height / (float) img->dim.width);
	img->dim.height *= MOVE;
}

void	move_down(float move, t_data *img)
{
	int	diff;
	int	x;
	int	y;

	diff = MOVE*img->dim.height;
	x = -1;
	while (x++ < img->dim.width)
	{
		y = -1;
		while (y++ < img->dim.height)
		{
			if (y + diff < HEIGHT)
				my_mlx_pixel_put(img, x, y, get_mlx_pixel(img, x, y + diff));
		}
	}
	img->range.immax -= move * ((float) img->dim.height / (float) img->dim.width);
	img->dim.start_y = img->dim.height - diff;
}

void	move_left(float move, t_data *img)
{
	int	diff;
	int	x;
	int	y;

	diff = MOVE * img->dim.width;
	y = img->dim.height;
	while (y--)
	{
		x = img->dim.width;
		while (x--)
		{
			if (x > diff)
				my_mlx_pixel_put(img, x, y, get_mlx_pixel(img, x - diff, y));
		}
	}
	img->range.remin -= move;
	img->range.remax -= move;
	img->dim.width = MOVE * img->dim.width;
}

void	move_right(float move, t_data *img)
{
	int	diff;
	int	x;
	int	y;

	diff = MOVE*img->dim.width;
	y = -1;
	while (y++ < img->dim.height)
	{
		x = -1;
		while (x++ < img->dim.width)
		{
			if (x + diff < WIDTH)
				my_mlx_pixel_put(img, x, y, get_mlx_pixel(img, x + diff, y));
		}
	}
	img->range.remin += move;
	img->range.remax += move;
	img->dim.start_x = img->dim.width - MOVE*img->dim.width;
}

int	key_controls(int keycode, t_data *img)
{
	float	move;

	move = (img->range.remax - img->range.remin) * MOVE;
	if (keycode == KEY_ESC)
		close_window(&img->win);
	else if (keycode == KEY_LEFT)
		move_left(move, img);
	else if (keycode == KEY_RIGHT)
		move_right(move, img);
	else if (keycode == KEY_UP)
		move_up(move, img);
	else if (keycode == KEY_DOWN)
		move_down(move, img);
	create_img(img);
	img->dim.height = HEIGHT;
	img->dim.width = WIDTH;
	img->dim.start_x = 0;
	img->dim.start_y = 0;
	return (0);
}
