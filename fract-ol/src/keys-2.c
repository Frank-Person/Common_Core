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
	{
		db()->rgb[0] = 4.0;
		db()->rgb[1] = 12.0;
		db()->rgb[2] = 20.0;
	}
	else if (key == XK_2)
	{
		db()->rgb[0] = 15.0;
		db()->rgb[1] = 8.0;
		db()->rgb[2] = 3.0;
	}
	else if (key == XK_3)
	{
		db()->rgb[0] = 3.0;
		db()->rgb[1] = 9.0;
		db()->rgb[2] = 18.0;
	}
	else if (key == XK_4)
	{
		db()->rgb[0] = 12.0;
		db()->rgb[1] = 14.0;
		db()->rgb[2] = 8.0;
	}
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
	dt->rgb[0] = 9.0;
	dt->rgb[1] = 15.0;
	dt->rgb[2] = 8.5;
	dt->zoom_state = 0;
	set_scale();
	if (dt->type == 'j')
		dt->c = new_complex(dt->start_re, dt->start_im);
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

