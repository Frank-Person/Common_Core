/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:35:26 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/01 17:48:00 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
//#include <bsd/string.h>

void	t_strncmp()
{
	char	*s1 = "Hello";
	char	*s2 = "Hella";

	printf("\t\tft_strncmp\n\n");
	printf("MF:\n");
	printf("The difference between charachters\n");
	printf("is %d(on the ASCII table)\n\n", ft_strncmp(s1, s2, 5));
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

	printf("\t\tft_memchr\n\n");
	printf("MF:\n");
	printf("Character %c found in position %ld\n", c, (r - s));
	printf("from the string: %s\n\n", s);
	printf("OF:\n");
	printf("Character %c found in position %ld\n", c, (rt - s));
	printf("from the string: %s\n", s);
}

void	t_memcmp()
{
	const char	*s1 = "Hello";
	const char	*s2 = "Hella";

	printf("\t\tft_memcmp\n\n");
	printf("MF:\n");
	printf("The difference between values is %d\n\n", ft_memcmp(s1, s2, 5));
	printf("OF:\n");
	printf("The difference between values is %d\n", memcmp(s1, s2, 5));
}

void	t_strnstr()
{
	const char	*bg = "Hello guys, how are you doing!";
	const char	*lt = "how";
		
	printf("\t\tft_strnstr\n\n");
	printf("MF:\n");
	printf("Looking for %s in %s\n", lt, bg);
	printf("Found: %s\n\n", ft_strnstr(bg, lt, ft_strlen(bg)));
	// printf("OF:\n");
	// printf("Looking for %s in %s\n", lt, bg);
	// printf("Found: %s\n", strnstr(bg, lt, ft_strlen(bg)));
}

void	t_atoi()
{
	const char	*n = "   \t--++--4256hhh78";
	const char	*n2 = "  \t    -657487jgg8";

	printf("\t\tft_atoi\n\n");
	printf("MF:\n");
	printf("1ºCase:\n");
	printf("String: %s  || Number: %d\n", n, ft_atoi(n));
	printf("2ºCase:\n");
	printf("String: %s  || Number: %d\n\n", n2, ft_atoi(n2));
	printf("OF:\n");
	printf("1ºCase:\n");
	printf("String: %s  || Number: %d\n", n, atoi(n));
	printf("2ºCase:\n");
	printf("String: %s  || Number: %d\n", n2, atoi(n2));
}

void	t_calloc()
{
	void	*c = ft_calloc(5, 1);
	void	*c2 = calloc(5, 1);
	void	*c3 = ft_calloc(4, 0);
	void	*c4 = calloc(4, 0);

	printf("\t\tft_calloc\n\n");
	printf("MF:\n");
	printf("1ºCase:\n");
	printf("Array: %s\n", (char *)ft_memset(c, 'a', 5));
	printf("2ºCase:\n");
	printf("Array: %s\n\n", (char *)ft_memset(c3, 'a', 4));
	printf("OF:\n");
	printf("1ºCase:\n");
	printf("Array: %s\n", (char *)ft_memset(c2, 'a', 5));
	printf("2ºCase:\n");
	printf("Array: %s\n", (char *)ft_memset(c4, 'a', 4));
	free(c);
	free(c2);
	free(c3);
	free(c4);
}

int	main()
{
	t_strncmp();
	printf("\n\n");
	t_memchr();
	printf("\n\n");
	t_memcmp();
	printf("\n\n");
	t_strnstr();
	printf("\n\n");
	t_atoi();
	printf("\n\n");
	t_calloc();
	return (0);
}
