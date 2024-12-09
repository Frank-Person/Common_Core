/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:19:31 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/12/09 23:20:24 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ch_newline(char *buffer)
{
	while (*buffer)
	{
		if (*buffer++ == '\n')
			return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	long long	rd;

	line = NULL;
	rd = 1;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	while (rd)
	{
		if (!buffer[0])
			rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
		 	return (free(line), NULL);
		line = line_join(line, buffer);
		if (ch_newline(buffer) || rd == 0)
			break ;
		mv_buff(buffer);
	}
	mv_buff(buffer);
	return (line);
}

int	main(void)
{
	int	fd;
	
	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return 0;
}
