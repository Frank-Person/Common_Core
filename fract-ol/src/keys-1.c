/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys-1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:20:13 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/06 18:59:13 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

static int	  move(int key)
{
	double	move_x;
	double	move_y;

	move_x = db()->view_width * 0.05;
	move_y = db()->view_heigth * 0.05;
	if (key == XK_Down && db()->offset_y > ((db()->view_heigth / 2) * -1))
		db()->offset_y -= move_y;
	else if (key == XK_Up && db()->offset_y < (db()->view_heigth / 2))
		db()->offset_y += move_y;
	else if (key == XK_Left && db()->offset_x > ((db()->view_width / 2) * -1))
		db()->offset_x -= move_x;
	else if (key == XK_Right && db()->offset_x < (db()->view_width / 2))
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

	if (!db()->start_re && !db()->start_im && db()->type == 'j')
	{
		db()->start_re = 0.355;
		db()->start_im = 0.355;
		db()->c = new_complex(db()->start_re, db()->start_im);
	}
	else if (db()->type == 'j')
		db()->c = new_complex(db()->start_re, db()->start_im);
	render_fractal(db()->max_iter,db()->draw_fractal);
	return (0);
}

int			handle_key(int key, void *unused)
{
	(void)unused;
	if (key == XK_Down || key == XK_Up || key == XK_Left || key == XK_Right)
		move(key);
	else if (key == XK_1 || key == XK_2 || key == XK_3 || key == XK_4)
		rgb(key);
	else if (key == XK_m || key == XK_j)
		change_fractal(key);
	else if (key == XK_plus || key == XK_minus)
		max_iter(key);
	else if (key == XK_r)
		reset();
	else if (key == XK_Escape)
		close_window();
	else if (key == XK_z && db()->zoom_state == 0)
		db()->zoom_state = 1;
	else if (key == XK_z && db()->zoom_state == 1)
		db()->zoom_state = 0;
	return (0);
}
