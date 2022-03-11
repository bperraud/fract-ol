/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:49:40 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/11 18:23:19 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	move_up(float move, t_range *range)
{
	range->immax += move;
}

void	move_down(float move, t_range *range)
{
	range->immax -= move;
}

void	move_left(float move, t_data *img)
{
	int	diff;
	int	x;
	int	y;

	diff = MOVE*img->dim.width;
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
	img->dim.width = MOVE*img->dim.width;
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

	printf("%f", move);
	//mlx_put_image_to_window(img->win.mlx, img->win.window, img->img, 0, 0);


	img->range.remin += move;
	img->range.remax += move;
	img->dim.start_x = img->dim.width - MOVE*img->dim.width;

}


void	move_up2(float move, t_data *img)
{
	img->range.immax += move;
	img->dim.start_y = MOVE*img->dim.height;
}

void	move_down2(float move, t_data *img)
{
	img->range.immax -= move;
	img->dim.height = MOVE*img->dim.height;
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
		move_up(move, &img->range);
	else if (keycode == KEY_DOWN)
		move_down(move, &img->range);


	create_img(img);

	img->dim.height = HEIGHT;
	img->dim.width = WIDTH;
	img->dim.start_x = 0;
	img->dim.start_y = 0;

	return (0);
}

/*
void	reuse_pixel()
{
	while ()


}
*/
