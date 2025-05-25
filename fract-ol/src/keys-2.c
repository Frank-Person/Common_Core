/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys-2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:51:22 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/19 18:10:16 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

int	  rgb(int key)
{
	int	  color;

	if (key == XK_1)
	{
		if (db()->rgb[0] == 255)
			db()->rgb[0] = -1;
		db()->rgb[0] += 1;
	}
	else if (key == XK_2)
	{
		if (db()->rgb[1] == 255)
			db()->rgb[1] = -1;
		db()->rgb[1] += 1;
	}
	else if (key == XK_3)
	{
		if (db()->rgb[2] == 255)
			db()->rgb[2] = -1;
		db()->rgb[2] += 1;
	}
	else if (key == XK_x)
	{
		color = (db()->rgb[0] << 16) | (db()->rgb[1] << 8) | db()->rgb[2];
		printf("Color HEX_CODE = %X\n", color);
		printf("R[%d] G[%d] B[%d]\n", db()->rgb[0], db()->rgb[1], db()->rgb[2]);
	}
	render_fractal(db()->max_iter, db()->draw_fractal);
	return (0);
}

int	  reset(void)
{
	t_data	*dt;

	dt = db();
	dt->zoom = 0.75;
	dt->rgb[0] = 255;
	dt->rgb[1] = 255;
	dt->rgb[2] = 255;
	dt->max_iter = 1;
	dt->offset_x = 0.0;
	dt->offset_y = 0.0;
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

void	show_controls(void *mlx, void *win, int x, int y)
{
    mlx_string_put(mlx, win, x, y, WHITE, "CONTROLS:");
    y += 30;
    mlx_string_put(mlx, win, x, y, WHITE, "1/2/3 - Increase RGB channels");
    y += 30;
    mlx_string_put(mlx, win, x, y, WHITE, "+/- - Increase/Decrease Max Iterations");
    y += 30;
    mlx_string_put(mlx, win, x, y, WHITE, "WASD/Arrows - Move View");
    y += 30;
    mlx_string_put(mlx, win, x, y, WHITE, "M/J/B - Change Fractal");
    y += 30;
    mlx_string_put(mlx, win, x, y, WHITE, "Mouse Scroll - Zoom In/Out");
    y += 30;
    mlx_string_put(mlx, win, x, y, WHITE, "Z - Lock/Unlock Julia Set");
    y += 30;
    mlx_string_put(mlx, win, x, y, WHITE, "R - Reset Fractal");
    y += 30;
    mlx_string_put(mlx, win, x, y, WHITE, "I - Show/Hide Controls");
}
