/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:33:59 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/10 16:20:51 by bperraud         ###   ########.fr       */
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
	*(int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


void	create_img(t_data *img)
{
	fractal(img);
	mlx_put_image_to_window(img->window.mlx, img->window.window , img->img, 0, 0);
}


int mouse_press_hook(int button, int x, int y, t_data *img)
{
	int		delta_x;
	int		delta_y;
	double	pixelSize;
	double	x_move;
	double	y_move;

	if (button == MOUSE_IN || button == MOUSE_OUT)
	{
		delta_x = x - (WIDTH / 2);
		delta_y = (HEIGHT / 2) - y;
		pixelSize = (float)(img->range.remax - img->range.remin) / (float) WIDTH;
		x_move = delta_x * pixelSize;
		y_move = delta_y * pixelSize;
		if (delta_x > 0)
			move_right(fabs(x_move), img);
		if (delta_x < 0)
			move_left(fabs(x_move), img);
		if (delta_y > 0)
			move_up(fabs(y_move), img);
		if (delta_y < 0)
			move_down(fabs(y_move), img);
	}

	create_img(img);

	return (0);
}

//int	key_controls(int keycode, t_vars *vars)
int	key_controls(int keycode, t_data *img)
{
	printf("%i\n", keycode);
	if (keycode == KEY_ESC)
		close_window(&img->window);
	else if (keycode == KEY_LEFT)
		move_left(MOVE, img);
	else if (keycode == KEY_RIGHT)
		move_right(MOVE, img);
	else if (keycode == KEY_UP)
		move_up(MOVE, img);
	else if (keycode == KEY_DOWN)
		move_down(MOVE, img);

	create_img(img);

	return (0);
}


