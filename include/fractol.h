/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:25:37 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/10 02:59:50 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define NMAX 110

// reglage 1 pour julia
# define CREAL -0.8
# define CIMAG 0.156

# define HEIGHT 800
# define WIDTH 	1300

//# define KEY_ESC 53
# define KEY_ESC 65307

#include "stdio.h"
#include "math.h"
#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"


typedef struct	s_range {
	float remin;
	float remax;
	float immax;
}	t_range;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		color;
	int		place;
	char*	fractal;
	t_range range;
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
t_complex	absolute(t_complex c);

// fractol
void		mandelbrot(t_data *img, int n, int x, int y, double pixelSize);
void		julia(t_data *img, int n, int x, int y, double pixelSize);
void		burningship(t_data *img, int n, int x, int y, double pixelSize);
void		fractal(t_data *img);
int			color_pixel(int color, int n);

// window
int			create_trgb(int t, int r, int g, int b);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			close_window(t_vars *vars);
int			key_controls(int keycode, t_vars *vars);
int			mouse_press_hook(int button, int x, int y, t_vars *vars);


//main
void		arg_error();
void		setup_place1(t_data *img);
void		setup_place2(t_data *img);
int			valid_arg(char **argv);
