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
	dt->win = mlx_new_window(dt->mlx, dt->win_w, dt->win_h, "fract-ol");
	if (!dt->win)
		exit(win_malloc_error());
	dt->img = mlx_new_image(dt->mlx, dt->win_w, dt->win_h);
	if (!dt->img)
		exit(img_malloc_error());
	dt->addr = mlx_get_data_addr(dt->img, &dt->bpp, &dt->line_len, &dt->endian);
	if (!dt->start.re && !dt->start.im && dt->type == 'j')
		dt->start = new_complex(0.355, 0.355);
	dt->c = dt->start;
	dt->zoom = 0.75;
	dt->rgb = 6250000;
	set_scale();
}

void	set_scale(void)
{
	t_data	*dt;

	dt = db();
	dt->aspect_ratio = (double)db()->win_w / (double)db()->win_h;
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
	if (pos[0] >= 0 && pos[0] < db()->win_w && pos[1] >= 0 && pos[1] < db()->win_h)
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
	db()->img = mlx_new_image(db()->mlx, db()->win_w, db()->win_h);
	if (!db()->img)
		exit(img_malloc_error());
	pos[0] = -1;
	while (++pos[0] < db()->win_h)
	{
		pos[1] = -1;
		while (++pos[1] < db()->win_w)
			draw(pos[1], pos[0], max_iter);
	}
	mlx_put_image_to_window(db()->mlx, db()->win, db()->img, 0, 0);

}

int	  generate_color(int iter, int max_iter)
{
	// double	*rgb;
	// double	t;
	// int		r;
	// int		g;
	// int		b;
	// int		color;
	//
	// rgb = db()->rgb;
	if (iter == max_iter)
		return (BLACK);
	// t = (double)iter / max_iter;
	// r = (int)(rgb[0] * (1 - t) * t * t * t * 255);
	// g = (int)(rgb[1] * (1 - t) * (1 - t) * t * t * 255);
	// b = (int)(rgb[2] * (1 - t) * (1 - t) * (1 - t) * t * 255);
	// color = (r << 16) | (g << 8) | b;
	return (db()->rgb * iter / max_iter);
}
