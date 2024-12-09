/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:11:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/12/09 21:52:37 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	line_len(char *line)
{
	ssize_t	i;

	i = 0;
	if (!line)
		return (i);
	while (line[i])
	{
		if (line[i++] == '\n')
			return (i);
	}
	return (i);
}

void	mv_buff(char *buffer)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	c_pos;

	i = 0;
	j = 0;
	c_pos = line_len(buffer);
	while (buffer[i])
	{
		if (i >= c_pos)
			buffer[j++] = buffer[i];
		buffer[i++] = '\0';
	}
}

char	*line_join(char *p_line, char *buffer)
{
	char	*n_line;
	ssize_t	ttl_len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	ttl_len = line_len(p_line) + line_len(buffer) + 1;
	n_line = malloc(ttl_len * sizeof(char));
	if (!n_line)
		return (NULL);
	while (ttl_len--)
	{
		if (i < line_len(p_line))
			n_line[i] = p_line[i];
		else
			n_line[i] = buffer[j++];
		i++;
	}
	return (n_line);
}
