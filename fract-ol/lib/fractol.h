/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:14:35 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/04 12:36:02 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITER 1250
# define BLACK 0x000000
# define LNG_MAX 9223372036854775807L
# define LNG_MIN (-9223372036854775807L - 1)
# define DBL_MAX 1.7976931348623157e+308
# define DBL_MIN -1.7976931348623157e+308

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_data
{
	/* MLX */
	void		*mlx;
	void		*win;
	int			win_w;
	int			win_h;

	/* Image */
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;

	/* Colors (TRGB) */
	double		t;
	int			r;
	int			g;
	int			b;

	/* Fractal info */
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		aspect_ratio;
	double		view_width;
	double		view_heigth;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	int			max_iter;
	void		(*draw_fractal)(int x, int y, int max_iter);

	/* Complex numbers */
	t_complex	z;
	t_complex	c;
}	t_data;

void	  set_scale(void);
void	  init_fractol(void);
void	  put_pixel(int x, int y, int color);
void	  draw_mandelbrot(int x, int y, int max_iter);
void	  draw_julia(int x, int y, int max_iter);
void	  draw_pixels(int max_iter, void (*draw)(int, int, int));
void	  parse_fractal(int ac, char *str);
int		  ft_strcmp(char *s1, char *s2);
int		  generate_color(double t, int iter, int max_iter);
int		  malloc_error(void);
int		  win_malloc_error(void);
int		  img_malloc_error(void);
int		  input_error(void);
int		  iterations(t_complex z, t_complex c, int max_iter);
long	  parse_iter(char *str);
t_data	  *db(void);
t_complex new_complex(double re, double im);
t_complex add_complex(t_complex z, t_complex c);
t_complex square_complex(t_complex z);
t_complex screen_to_complex(int x, int y, double min_re, double max_re, double min_im, double max_im);
double	  magnitude_squared(t_complex z);
double	  parse_complex(char *str);

#endif
