/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:25:37 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/07 16:41:20 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define NMAX 200

# define CREAL -0.8
# define CIMAG 0.156

# define Remin -2.5
# define Remax 1
# define Immax 1

# define HEIGHT 800
# define WIDTH 	1300

//# define KEY_ESC 53
# define KEY_ESC 65307

#include "stdio.h"
#include "math.h"
#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;


typedef struct	s_vars {
	void	*mlx;
	void	*window;
}	t_vars;


typedef struct s_complex {
    float real;
    float imag;
}	t_complex;

// complex
t_complex 	add(t_complex c1, t_complex c2);
t_complex 	mult(t_complex c1, t_complex c2);
float		module(t_complex c);


// fractol
void		mandelbrot(t_data *img);
int			color_pixel(int n);
void		julia(t_data *img);

// window
int			create_trgb(int t, int r, int g, int b);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			close(t_vars *vars);
int			key_controls(int keycode, t_vars *vars);
int			mouse_press_hook(int button, int x, int y, t_vars *vars);
