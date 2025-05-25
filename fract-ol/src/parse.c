/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:40:00 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/04 12:35:09 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

static void	set_resolution(int width, int heigth)
{
	db()->win_w = width;
	db()->win_h = heigth;
}

double	parse_complex(char *str)
{
	double	sgn;
	double	num;
	double	dec;

	num = 0.0;
	dec = 10.0;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	sgn = (*str != '-') - (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	while (*str && (*str >= '0' && *str <= '9') && (num <= DBL_MAX && num >= DBL_MIN))
		num = (num * 10) + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str && (*str >= '0' && *str <= '9') && (num <= DBL_MAX && num >= DBL_MIN))
	{
		num += (*str++ - '0') / dec;
		dec *= 10.0;
	}
	if (num > DBL_MAX || num < DBL_MIN || *str != '\0')
		exit(input_error());
	return (num * sgn);
}

long  parse_input(char *str)
{
	long	num;

	num = 0;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	if (*str && *str == '+')
		str++;
	else if (*str && *str == '-')
		exit(input_error());
	while (*str && (*str >= '0' && *str <= '9') && (num <= LNG_MAX && num >= LNG_MIN))
		num = (num * 10) + (*str++ - '0');
	if (num > LNG_MAX || num < LNG_MIN || *str != '\0')
		exit(input_error());
	return (num);
}

void  parse_fractal(int ac, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0 && ac > 1 && ac < 6)
	{
		db()->draw_fractal = &draw_mandelbrot;
		db()->type = 'm';
		if (ac > 2)
			db()->max_iter = parse_input(av[2]);
		if (ac > 3)
			set_resolution(parse_input(av[3]), parse_input(av[4]));
	}
	else if (ft_strcmp(av[1], "burning") == 0 && ac > 1 && ac < 6)
	{
		db()->draw_fractal = &draw_burning;
		db()->type = 'b';
		if (ac > 2)
			db()->max_iter = parse_input(av[2]);
		if (ac > 3)
			set_resolution(parse_input(av[3]), parse_input(av[4]));
	}
	else if (ft_strcmp(av[1], "julia") == 0 && ac > 1 && ac < 8)
	{
		db()->draw_fractal = &draw_julia;
		db()->type = 'j';
		if (ac > 2)
			db()->max_iter = parse_input(av[2]);
		if (ac > 3)
			set_resolution(parse_input(av[3]), parse_input(av[4]));
		if (ac > 5)
			db()->start = new_complex(parse_complex(av[5]), parse_complex(av[6]));
	}
	else
		exit(input_error());
}

void  parsing(int ac, char **av)
{
	t_data	*dt;

	dt = db();	
	parse_fractal(ac, av);
	if (!dt->max_iter)
		dt->max_iter = MAX_ITER;
	if (!dt->win_h && !dt->win_w)
		set_resolution(WIDTH, HEIGTH);
}
