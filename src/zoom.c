/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:18:40 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/10 23:48:10 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_press_hook(int button, int x, int y, t_data *img)
{
	if (button == MOUSE_IN)
		zoom(x, y, 1, img);
	else if (button == MOUSE_OUT)
		zoom(x, y, 0, img);
	create_img(img);
	return (0);
}

void	zoom(int x, int y, int in, t_data *img)
{
	double	delta_re;
	double	delta_re_prime;
	double	delta_im;
	double	delta_im_prime;

	delta_re = img->range.remax - img->range.remin;
	delta_re_prime = SCALE * (delta_re);
	delta_im = (delta_re / WIDTH) * HEIGHT;
	if (in)
	{
		delta_re_prime = (SCALE * delta_re) - delta_re;
		delta_im_prime = (SCALE * delta_im) - delta_im;
	}
	else
	{
		delta_re_prime = ((1.0 / SCALE) * delta_re) - delta_re;
		delta_im_prime = ((1.0 / SCALE) * delta_im) - delta_im;
	}
	img->range.remin -= delta_re_prime * ((float) x / WIDTH);
	img->range.remax += delta_re_prime * (1 - ((float) x / WIDTH));
	img->range.immax += delta_im_prime * ((float) y / HEIGHT);
}
