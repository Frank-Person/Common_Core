/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:35:26 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/10/31 00:06:37 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	printf("Found: %s\n", ft_strnstr(bg, lt, ft_strlen(lt)));
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
	return (0);
}
