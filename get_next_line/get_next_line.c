/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:19:31 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/01/18 21:18:57 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	long long	rd;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rd = 1;
	while (rd)
	{
		if (!*buffer)
			rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (free(line), NULL);
		if (rd)
			line = line_join(line, buffer);
		if (hndl_buff(buffer) || rd == 0)
			break ;
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("ola", O_RDONLY);
	line = get_next_line(fd);
	write(1, line, line_len(line) + 1);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		write(1, line, line_len(line));
		free(line);
	}
	return (0);
}
