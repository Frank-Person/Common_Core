/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:20:13 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/04 19:24:22 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

static int	  move(int key)
{
	if (key == XK_s)
		db()->offset_y -= 0.5;
	else if (key == XK_w)
		db()->offset_y += 0.5;
	else if (key == XK_a)
		db()->offset_x -= 0.5;
	else if (key == XK_d)
		db()->offset_x += 0.5;
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
	return (0);
}

static int	  close_window(void)
{
	mlx_clear_window(db()->mlx, db()->win);
	mlx_destroy_display(db()->mlx);
	free(db()->mlx);
	return (0);
}

int			x_close(void)
{
	return (exit(close_window()), 0);
}

int			handle_key(int key, void *param)
{
	if (key == XK_s || key == XK_w || key == XK_a || key == XK_d)
		return (render_fractal(db()->max_iter, db()->draw_fractal), move(key));
	else if (key == XK_Down || key == XK_Up || key == XK_Left || key == XK_Right)
		return (render_fractal(db()->max_iter, db()->draw_fractal), iter_julia(key));
	else if (key == XK_Escape)
		exit(close_window());
	return (0);
}
