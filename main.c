/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:35:26 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/01 02:09:53 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

void	t_strncmp()
{
	char	*s1 = "Hello";
	char	*s2 = "Hella";

	printf("MF:\n");
	printf("The difference between charachters\n");
	printf("is %d(on the ASCII table)\n", ft_strncmp(s1, s2, 5));
	printf("OF:\n");
	printf("The difference between charachters\n");
	printf("is %d(on the ASCII table)\n", strncmp(s1, s2, 5));
}

void	t_memchr()
{
	const char	*s = "Sup Cuz, How we doin'!";
	const char	c = 'S';
	char		*r = ft_memchr(s, c, ft_strlen(s));
	char		*rt = memchr(s, c, ft_strlen(s));

	printf("MF:\n");
	printf("Character %c found in position %ld\n", c, (r - s));
	printf("from the string: %s\n", s);
	printf("OF:\n");
	printf("Character %c found in position %ld\n", c, (rt - s));
	printf("from the string: %s\n", s);
}

void	t_memcmp()
{
	const char	*s1 = "Hello";
	const char	*s2 = "Hella";

	printf("MF:\n");
	printf("The difference between values is %d\n", ft_memcmp(s1, s2, 5));
	printf("OF:\n");
	printf("The difference between values is %d\n", memcmp(s1, s2, 5));
}

void	t_strnstr()
{
	const char	*bg = "Hello guys, how are you doing!";
	const char	*lt = "how";
		
	printf("MF:\n");
	printf("Looking for %s in %s\n", lt, bg);
	printf("Found: %s\n", ft_strnstr(bg, lt, ft_strlen(bg)));
	printf("OF:\n");
	printf("Looking for %s in %s\n", lt, bg);
	printf("Found: %s\n", strnstr(bg, lt, ft_strlen(bg)));
}

void	t_atoi()
{
	const char	*n = "   \t  \t--++--4256hhh78";
	const char	*n2 = "\r\n\t    -657487jgjg8";

	printf("MF:\n");
	printf("1ºCase:\n");
	printf("String: %s  || Number: %d\n", ft_atoi(n));
	printf("2ºCase:\n");
	printf("String: %s  || Number: %d\n", ft_atoi(n2));
	printf("OF:\n");
	printf("1ºCase:\n");
	printf("String: %s  || Number: %d\n", atoi(n));
	printf("2ºCase:\n");
	printf("String: %s  || Number: %d\n", atoi(n2));
}

void	t_calloc()
{
	char	*c = ft_calloc(5, 1);
	char	*c2 = calloc(5, 1);
	char	*c3 = ft_calloc(4, 0);
	char	*c4 = calloc(4, 0);
	int	*n = ft_calloc(3, 4);
	int	*n2 = calloc(3, 4);
	int	*n3 = ft_calloc(0, 1);
	int	*n4 = calloc(0, 1);

	printf("MF:\n");
	printf("1ºCase:\n");
	printf("Array: %s\n", c);
	printf("2ºCase:\n");
	printf("Array: %s\n", n);
	printf("3ºCase:\n");
	printf("Array: %s\n", c3);
	printf("4ºCase:\n");
	printf("Array: %s\n", n3);
	printf("OF:\n");
	printf("1ºCase:\n");
	printf("Array: %s\n", c2);
	printf("2ºCase:\n");
	printf("Array: %s\n", n2);
	printf("3ºCase:\n");
	printf("Array: %s\n", c4);
	printf("4ºCase:\n");
	printf("Array: %s\n", n4);

	free(c);
	free(c2);
	free(c3);
	free(c4);
	free(n);
	free(n2);
	free(n3);
	free(n4);
}

int	main()
{
	t_strncmp();
	printf("\n");
	t_memchr();
	printf("\n");
	t_memcmp();
	printf("\n");
	t_strnstr();
	printf("\n");
	t_atoi();
	printf("\n");
	t_calloc();
	return (0);
}
