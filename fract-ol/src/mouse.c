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
	t_data	  *dt;
	t_complex mouse;

	dt = db();
	mouse = screen_to_complex(x, y);
	dt->zoom *= zoom_factor;
	dt->offset_x = mouse.re;
	dt->offset_y = mouse.im;
	set_scale();
	render_fractal(db()->max_iter, db()->draw_fractal);
}

int			mouse_iter(int x, int y, void *unused)
{
	(void)unused;
	if (db()->type == 'j' && db()->zoom_state == 1)
	{
		db()->c = screen_to_complex(x, y);
		set_scale();
		render_fractal(db()->max_iter, db()->draw_fractal);
	}
	return (0);
}

int			handle_mouse(int code, int x, int y, void *unused)
{
	(void)unused;
	if (code == SCRL_UP)
		zoom(1.05, x, y);
	else if (code == SCRL_DW && db()->zoom > 0.5)
		zoom(0.95, x, y);
	return (0);
}
