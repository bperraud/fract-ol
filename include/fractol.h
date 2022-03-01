/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:25:37 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/02 00:29:58 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define NMAX 1677
# define HEIGHT 500
# define WIDTH 	1000

# define Remin -2
# define Remax 1
# define Immax 1

#include "stdio.h"
#include "math.h"

typedef struct s_complex {
    float real;
    float imag;
}	t_complex;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
void		escape(t_data *img);
t_complex 	add(t_complex c1, t_complex c2);
t_complex 	mult(t_complex c1, t_complex c2);
float		module(t_complex c);
