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
	t_complex mouse_before;
	t_complex mouse_after;

	dt = db();
	mouse_before = screen_to_complex(x, y);
	if (magnitude_squared(mouse_before) > 4)
		return ;
	dt->zoom *= zoom_factor;
	set_scale();
	mouse_after = screen_to_complex(x, y);
	dt->offset_x += mouse_before.re - mouse_after.re;
	dt->offset_y += mouse_before.im - mouse_after.im;
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
		zoom(1.025, x, y);
	else if (code == SCRL_DW && db()->zoom * 0.975 > 0.74)
		zoom(0.975, x, y);
	return (0);
}
