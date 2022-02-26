/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:25:37 by bperraud          #+#    #+#             */
/*   Updated: 2022/02/22 01:33:12 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_complex {
    float real;
    float imag;
} t_complex;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);