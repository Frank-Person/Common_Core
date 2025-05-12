/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:34:52 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/12 18:39:32 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

static void	zoom(double zoom_factor, int x, int y)
{
	t_data	*dt;
	double	re_offset;
	double	im_offset;
	double	new_width;
	double	new_heigth;

	dt = db();
	re_offset = dt->offset_x + (x / (double)WIDTH) * (dt->max_re - dt->min_re); 
	im_offset = dt->offset_y + (y / (double)HEIGHT) * (dt->max_im - dt->min_im);
	new_width = (dt->max_re - dt->min_re) * zoom_factor;
	new_heigth = (dt->max_im - dt->min_im) * zoom_factor;
	dt->max_re = re_offset + (new_width / 2);
	dt->min_re = re_offset - (new_width / 2);
	dt->max_im = im_offset + (new_heigth / 2);
	dt->min_im = im_offset - (new_heigth / 2);
	render_fractal(db()->max_iter, db()->draw_fractal);
}

int			handle_mouse(int code, int x, int y, void *unused)
{
	(void)unused;
	if (code == SCRL_UP)
		zoom(0.8, x, y);
	else if (code == SCRL_DW)
		zoom(1.2, x, y);
	return (0);
}
