/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:09:49 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/12/07 16:45:24 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0)
		return (NULL);
	
}

int	main(void)
{
	int	fd;
	int	stp;

	fd = open("test.txt", O_RDONLY);
	stp = 0;
	while (stp > -1)
		stp = printf("%s\n", get_next_line(fd));
	return (0);
}
