/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:23:23 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/12 18:40:16 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

t_data	*db(void)
{
	static t_data	db;

	return (&db);
}

int	main(int ac, char **av)
{
	if (ac > 1 && ac < 8)
	{
		parsing(ac, av);
		init_fractol();
		render_fractal(db()->max_iter, db()->draw_fractal);
		mlx_mouse_hook(db()->win, handle_mouse, NULL);
		mlx_hook(db()->win, 02, 1L<<0,handle_key, NULL);
		mlx_hook(db()->win, 06, 1L<<6, mouse_iter, NULL);
		mlx_hook(db()->win, 17, 1L<<17, x_close, NULL);
		mlx_loop(db()->mlx);
	}
	else
		exit(input_error());
	return (0);
}
