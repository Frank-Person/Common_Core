/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:23:23 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/04 19:32:10 by mrapp-he         ###   ########.fr       */
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
	if (ac > 1 && ac < 6)
	{
		db()->zoom = 1.0;
		if (ac == 3)
			db()->max_iter = parse_iter(av[2]);
		else if (ac == 5)
			db()->max_iter = parse_iter(av[4]);
		else
			db()->max_iter = MAX_ITER;
		init_fractol();
		render_fractal(db()->max_iter, db()->draw_fractal);
		mlx_put_image_to_window(db()->mlx, db()->win, db()->img, 0, 0);
		mlx_loop(db()->mlx);
	}
	else
		exit(input_error());
	return (0);
}
