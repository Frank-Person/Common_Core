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
	if (key == XK_s)
		db()->offset_y -= (0.25 * db()->zoom);
	else if (key == XK_w)
		db()->offset_y += (0.25 * db()->zoom);
	else if (key == XK_a)
		db()->offset_x -= (0.25 * db()->zoom);
	else if (key == XK_d)
		db()->offset_x += (0.25 * db()->zoom);
	render_fractal(db()->max_iter, db()->draw_fractal);
	return (0);
}

static int	  iter_julia(int key)
{
	if (key == XK_Down)
		db()->c.im -= 0.01;
	else if (key == XK_Up)
		db()->c.im += 0.01;
	else if (key == XK_Left)
		db()->c.re -= 0.01;
	else if (key == XK_Right)
		db()->c.re += 0.01;
	render_fractal(db()->max_iter, db()->draw_fractal);
	return (0);
}

static int	  max_iter(int key)
{
	if (key == XK_m)
		db()->max_iter += 25;
	else if (key == XK_l)
		db()->max_iter -= 25;
	render_fractal(db()->max_iter, db()->draw_fractal);
	return (0);
}

int	  close_window(void)
{
	mlx_clear_window(db()->mlx, db()->win);
	mlx_destroy_display(db()->mlx);
	free(db()->mlx);
	return (0);
}

int			handle_key(int key, void *param)
{
	if (key == XK_s || key == XK_w || key == XK_a || key == XK_d)
		return (move(key));
	else if (key == XK_Down || key == XK_Up || key == XK_Left || key == XK_Right)
		return (iter_julia(key));
	else if (key == XK_m || key == XK_l)
		return  (max_iter(key));
	else if (key == XK_i || key == XK_o)
		return  (zoom(key));
	else if (key == XK_Escape)
		exit(close_window());
	return (0);
}
