/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:19:31 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/12/17 17:08:16 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	long long	rd;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || fd > FOPEN_MAX)
		return (NULL);
	rd = 1;
	while (rd)
	{
		if (!*buffer[fd])
			rd = read(fd, buffer[fd], BUFFER_SIZE);
		if (rd < 0)
			return (free(line), NULL);
		if (rd)
			line = line_join(line, buffer[fd]);
		if (hndl_buff(buffer[fd]) || rd == 0)
			break ;
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	char	*line1;
// 	char	*line2;

// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	line1 = get_next_line(fd1);
// 	line2 = get_next_line(fd2);
// 	write(1, line1, line_len(line1));
// 	write(1, line2, line_len(line2));
// 	free(line1);
// 	free(line2);
// 	while (line1 || line2)
// 	{
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
// 		write(1, line1, line_len(line1));
// 		write(1, line2, line_len(line2));
// 		free(line1);
// 		free(line2);
// 	}
// 	return (0);
// }
