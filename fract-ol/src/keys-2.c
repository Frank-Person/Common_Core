/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys-2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:51:22 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/12 18:37:59 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

int	  rgb(int key)
{
	if (key == XK_1)
		db()->rgb = 150000000;
	else if (key == XK_2)
		db()->rgb = 100000000;
	else if (key == XK_3)
		db()->rgb = 50000000;
	else if (key == XK_4)
		db()->rgb = 25000000;
	else if (key == XK_5)
		db()->rgb = 12500000;
	db()->max_iter = 1;
	render_fractal(db()->max_iter, db()->draw_fractal);
	return (0);
}

int	  reset(void)
{
	t_data	*dt;

	dt = db();
	dt->zoom = 0.75;
	dt->max_iter = 1;
	dt->offset_x = 0.0;
	dt->offset_y = 0.0;
	dt->rgb = 6250000;
	dt->zoom_state = 0;
	set_scale();
	if (dt->type == 'j')
		dt->c = new_complex(dt->start.re, dt->start.im);
	render_fractal(dt->max_iter, dt->draw_fractal);
	return (0);
}

int	  x_close(void)
{
	return (close_window(), 0);
}

void  close_window(void)
{
	if (db()->img)
		mlx_destroy_image(db()->mlx, db()->img);
	if (db()->win)
		mlx_clear_window(db()->mlx, db()->win);
	if (db()->win)
		mlx_destroy_window(db()->mlx, db()->win);
	if (db()->mlx)
		mlx_destroy_display(db()->mlx);
	if (db()->mlx)
		mlx_loop_end(db()->mlx);
	free(db()->mlx);
	exit(0);
}

