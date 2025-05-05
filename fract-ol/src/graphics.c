/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:43 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/04 19:24:07 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void	init_fractol(void)
{
	t_data	*dt;

	dt = db();
	dt->mlx = mlx_init();
	if (!dt->mlx)
		exit(malloc_error());
	dt->win = mlx_new_window(dt->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!dt->win)
		exit(win_malloc_error());
	dt->img = mlx_new_image(dt->mlx, WIDTH, HEIGHT);
	if (!dt->img)
		exit(img_malloc_error());
	dt->addr = mlx_get_data_addr(dt->img, &dt->bpp, &dt->line_len, &dt->endian);
}

void	set_scale(void)
{
	t_data	*dt;

	dt = db();
	dt->aspect_ratio = (double)WIDTH / (double)HEIGHT;
	dt->view_width = 3.0 / dt->zoom;
	dt->view_heigth = dt->view_width / dt->aspect_ratio;
	dt->min_re = dt->offset_x -	dt->view_width / 2.0;
	dt->max_re = dt->offset_x + dt->view_width / 2.0;
	dt->min_im = dt->offset_y - dt->view_heigth / 2.0;
	dt->max_im = dt->offset_y + dt->view_heigth / 2.0;
}

void	put_pixel(int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = db()->addr + (y * db()->line_len + x * (db()->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

void	draw_pixels(int max_iter, void (*draw)(int, int, int))
{
	int	  x;
	int	  y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			draw(x, y, max_iter);
	}
}

int	  generate_color(double t, int iter, int max_iter)
{
	if (iter == max_iter)
		return (BLACK);

	t = (double)iter / max_iter;
	db()->r = (int)(9 * (1 - t) * t * t * t * 255);
	db()->g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	db()->b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((int)t << 24 | db()->r << 16 | db()->g << 8 | db()->b);
}

