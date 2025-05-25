/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys-1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:20:13 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/19 17:47:34 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

static int	  move(int key)
{
	double	move_speed;
	double	move_x;
	double	move_y;
	double	x;
	double	y;

	move_speed = 0.5 / db()->zoom;
	move_x = move_speed * (db()->max_re - db()->min_re);
	move_y = move_speed * (db()->max_im - db()->min_im);
	x = db()->offset_x;
	y = db()->offset_y;
	if (key == 'D' && check_next_pos(x, y - move_y) <= 4)
		db()->offset_y -= move_y;
	else if (key == 'U' && check_next_pos(x, y + move_y) <= 4)
		db()->offset_y += move_y;
	else if (key == 'L' && check_next_pos(x - move_x, y) <= 4)
		db()->offset_x -= move_x;
	else if (key == 'R' && check_next_pos(x + move_x, y) <= 4)
		db()->offset_x += move_x;
	set_scale();
	render_fractal(db()->max_iter, db()->draw_fractal);
	return (0);
}

static int	  max_iter(int key)
{
	if (key == XK_plus)
		db()->max_iter += 1;
	else if (key == XK_minus && db()->max_iter > 0)
		db()->max_iter -= 1;
	render_fractal(db()->max_iter, db()->draw_fractal);
	return (0);
}

static int	  change_fractal(int key)
{
	if (key == XK_m)
	{
		db()->draw_fractal = &draw_mandelbrot;
		db()->type = 'm';
	}
	else if (key == XK_j)
	{
		db()->draw_fractal = &draw_julia;
		db()->type = 'j';
	}
	else if (key == XK_b)
	{
		db()->draw_fractal = &draw_burning;
		db()->type = 'b';
	}

	if (!db()->start.re && !db()->start.im && db()->type == 'j')
	{
		db()->start = new_complex(0.355, 0.355);
		db()->c = db()->start;
	}
	else if (db()->type == 'j')
		db()->c = new_complex(db()->start.re, db()->start.im);
	render_fractal(db()->max_iter,db()->draw_fractal);
	return (0);
}

int			handle_key(int key, void *unused)
{
	(void)unused;
	if (key == XK_Down || key == XK_s)
		move('D');
	else if (key == XK_Up || key == XK_w)
		move('U');
	else if (key == XK_Left || key == XK_a)
		move('L');
	else if (key == XK_Right || key == XK_d)
		move('R');
	else if ((key >= XK_1 && key <= XK_3) || key == XK_x)
		rgb(key);
	else if (key == XK_m || key == XK_j || key == XK_b)
		change_fractal(key);
	else if (key == XK_plus || key == XK_minus)
		max_iter(key);
	else if (key == XK_r)
		reset();
	else if (key == XK_Escape)
		close_window();
	else if (key == XK_z)
		db()->zoom_state *= -1;
	else if (key == XK_i)
		db()->show_controls *= -1;
	return (0);
}
