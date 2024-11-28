/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:50 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/28 03:54:47 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define HEX_U "0123456789ABCDEF"
# define HEX_L "0123456789abcdef"
# define DEX "0123456789"

typedef int	(*t_ftp)();

int		ft_printf(const char *str, ...);
int		flag_c(va_list args);
int		flag_s(va_list args);
int		flag_p(va_list args);
int		flag_diu(va_list args);
int		flag_pc(void);
int		flag_xl(va_list args);
int		flag_xu(va_list args);
char	*ft_itoa_base(long long nbr, int bsize, char *base);
size_t	ft_strlen(char	*str);

#endif
