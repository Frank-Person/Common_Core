/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys-2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:51:22 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/06 18:58:58 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

int	  zoom(int key)
{
	if (key == XK_i)
		db()->zoom += 0.075;
	else if (key == XK_o)
		db()->zoom -= 0.075;
	render_fractal(db()->max_iter, db()->draw_fractal);
	return (0);
}

int	  x_close(void)
{
	return (exit(close_window()), 0);
}

int	  close_window(void)
{
	mlx_clear_window(db()->mlx, db()->win);
	mlx_destroy_display(db()->mlx);
	free(db()->mlx);
	return (0);
}

