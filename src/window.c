/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:33:59 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/07 17:38:57 by bperraud         ###   ########.fr       */
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


int mouse_press_hook(int button, int x, int y, t_vars *vars)
{
	printf("%i\n", button);

	printf("%i\n", x);
	printf("%i\n", y);
	fflush(stdout);

	if (vars)
		printf("ok");

	return (0);
}

int	key_controls(int keycode, t_vars *vars)
{
	printf("%i", keycode);
	fflush(stdout);
	if (keycode == KEY_ESC)
		close_window(vars);

	return (0);
}
