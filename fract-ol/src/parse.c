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

long  parse_iter(char *str)
{
	long	sgn;
	long	num;

	num = 0;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	sgn = (*str != '-') - (*str == '-');
	if (*str && (*str == '+' || *str == '-'))
		str++;
	while (*str && (*str >= '0' && *str <= '9') && (num <= LNG_MAX && num >= LNG_MIN))
		num = (num * 10) + (*str++ - '0');
	if (num > LNG_MAX || num < LNG_MIN || *str != '\0')
		exit(input_error());
	return (num * sgn);
}

void  parse_fractal(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
	{
		db()->draw_fractal = &draw_mandelbrot;
		db()->type = 'm';
	}
	else if (ft_strcmp(str, "julia") == 0)
	{
		db()->draw_fractal = &draw_julia;
		db()->type = 'j';
	}
	else
		exit(input_error());
}

void  parsing(int ac, char **av)
{
	parse_fractal(av[1]);
	if (ac == 3)
		db()->max_iter = parse_iter(av[2]);
	else if (ac == 5)
		db()->max_iter = parse_iter(av[4]);
	else
		db()->max_iter = MAX_ITER;
	if (db()->type == 'j' && ac > 3)
		db()->c = new_complex(parse_complex(av[2]), parse_complex(av[3]));
	else
		db()->c = new_complex(0.355, 0.355);
}
