/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:43 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/12 18:41:20 by mrapp-he         ###   ########.fr       */
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
	dt->zoom = 0.75;
	dt->rgb[0] = 9.0;
	dt->rgb[1] = 15.0;
	dt->rgb[2] = 8.5;
	set_scale();
}

void	set_scale(void)
{
	t_data	*dt;

	dt = db();
	dt->aspect_ratio = (double)WIDTH / (double)HEIGHT;
	dt->view_width = 3.0 / dt->zoom;
	dt->view_heigth = dt->view_width / dt->aspect_ratio;
	dt->min_re = dt->offset_x -	(dt->view_width / 2.0);
	dt->max_re = dt->offset_x + (dt->view_width / 2.0);
	dt->min_im = dt->offset_y - (dt->view_heigth / 2.0);
	dt->max_im = dt->offset_y + (dt->view_heigth / 2.0);
}

void	put_pixel(int x, int y, int color)
{
	char	*pixel;
	int		pos[2];

	pos[0] = x;
	pos[1] = y;
	if (pos[0] >= 0 && pos[0] < WIDTH && pos[1] >= 0 && pos[1] < HEIGHT)
	{
		pixel = db()->addr + (pos[1] * db()->line_len + pos[0] * (db()->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

void	render_fractal(int max_iter, void (*draw)(int, int, int))
{
	int	  pos[2]; //pos[0] = y; pos[1] = x

	if (db()->img)
		mlx_destroy_image(db()->mlx, db()->img);
	db()->img = mlx_new_image(db()->mlx, WIDTH, HEIGHT);
	if (!db()->img)
		exit(img_malloc_error());
	pos[0] = -1;
	while (++pos[0] < HEIGHT)
	{
		pos[1] = -1;
		while (++pos[1] < WIDTH)
			draw(pos[1], pos[0], max_iter);
	}
	mlx_put_image_to_window(db()->mlx, db()->win, db()->img, 0, 0);

}

int	  generate_color(int iter, int max_iter)
{
	double	*rgb;
	double	t;
	int		r;
	int		g;
	int		b;
	int		color;

	rgb = db()->rgb;
	if (iter == max_iter)
		return (BLACK);
	t = (double)iter / max_iter;
	r = (int)(rgb[0] * (1 - t) * t * t * t * 255);
	g = (int)(rgb[1] * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(rgb[2] * (1 - t) * (1 - t) * (1 - t) * t * 255);
	color = (r << 16) | (g << 8) | b;
	return (color);
}
