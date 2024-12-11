/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:19:31 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/12/11 19:05:34 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
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

// int	main(void)
// {
// 	int		fd;
// 	int		stp;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	stp = 1;
// 	while (stp)
// 	{
// 		line = get_next_line(fd);
// 		stp = write(1, line, ft_strlen(line));
// 		free(line);
// 	}
// 	return (0);
// }
