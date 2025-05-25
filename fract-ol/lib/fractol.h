/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:14:35 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/19 18:08:00 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGTH 800
# define MAX_ITER 1
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define LNG_MAX 9223372036854775807L
# define LNG_MIN (-9223372036854775807L - 1)
# define DBL_MAX 1.7976931348623157e+308
# define DBL_MIN -1.7976931348623157e+308
# define SCRL_UP 4
# define SCRL_DW 5

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
	int			show_controls;

	/* Colors (RGB) */
	int		  rgb[3];

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
	int			type;
	void		(*draw_fractal)(int x, int y, int max_iter);

	/* Julia info */
	t_complex	start;
	int			zoom_state;

	/* Complex numbers */
	t_complex	z;
	t_complex	c;
}	t_data;

void	  set_scale(void);
void	  init_fractol(void);
void	  put_pixel(int x, int y, int color);
void	  draw_mandelbrot(int x, int y, int max_iter);
void	  draw_julia(int x, int y, int max_iter);
void	  draw_burning(int x, int y, int max_iter);
void	  render_fractal(int max_iter, void (*draw)(int, int, int));
void	  show_controls(void *mlx, void *win, int x, int y);
void	  parse_fractal(int ac, char **av);
void	  parsing(int ac, char **av);
void	  close_window(void);
int		  x_close(void);
int		  rgb(int key);
int		  handle_mouse(int code, int x, int y, void *unused);
int		  mouse_iter(int x, int y, void *unused);
int		  reset(void);
int		  ft_strcmp(char *s1, char *s2);
int		  generate_color(int iter, int max_iter);
int		  malloc_error(void);
int		  win_malloc_error(void);
int		  img_malloc_error(void);
int		  input_error(void);
int		  handle_key(int key, void *param);
int		  iterations(t_complex z, t_complex c, int max_iter);
long	  parse_input(char *str);
t_data	  *db(void);
t_complex new_complex(double re, double im);
t_complex add_complex(t_complex z, t_complex c);
t_complex square_complex(t_complex z);
t_complex screen_to_complex(int x, int y);
double	  magnitude_squared(t_complex z);
double	  parse_complex(char *str);
double	  check_next_pos(int x, int y);

#endif
