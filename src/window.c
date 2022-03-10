/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:33:59 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/11 00:19:35 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_window(t_win *win)
{
	mlx_destroy_window(win->mlx, win->window);
	exit(EXIT_SUCCESS);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	create_img(t_data *img)
{
	fractal(img);
	mlx_put_image_to_window(img->win.mlx, img->win.window, img->img, 0, 0);
}

int	key_controls(int keycode, t_data *img)
{
	float	move;

	move = (img->range.remax - img->range.remin) * MOVE ;
	if (keycode == KEY_ESC)
		close_window(&img->win);
	else if (keycode == KEY_LEFT)
		move_left(move, &img->range);
	else if (keycode == KEY_RIGHT)
		move_right(move, &img->range);
	else if (keycode == KEY_UP)
		move_up(move, &img->range);
	else if (keycode == KEY_DOWN)
		move_down(move, &img->range);
	create_img(img);
	return (0);
}
