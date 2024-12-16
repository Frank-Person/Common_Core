/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:19:34 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/12/16 17:43:22 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	line_len(char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (i);
	while (line[i] && line[i] != '\n')
		i++;
	return (i + (line[i] == '\n'));
}

int	hndl_buff(char *buffer)
{
	int		ch;
	char	*t_buff;

	ch = 0;
	t_buff = buffer;
	while (*buffer)
	{
		if (ch)
			*t_buff++ = *buffer;
		else if (*buffer == '\n')
			ch = 1;
		*buffer++ = '\0';
	}
	return (ch);
}

char	*line_join(char *p_line, char *buffer)
{
	char	*n_line;
	size_t	ttl_len;
	size_t	i;
	size_t	j;

	ttl_len = line_len(p_line) + line_len(buffer);
	n_line = malloc(ttl_len + 1);
	if (!n_line)
		return (free(p_line), NULL);
	i = 0;
	j = 0;
	while (i < line_len(p_line))
		n_line[i++] = p_line[j++];
	j = 0;
	while (j < line_len(buffer))
		n_line[i++] = buffer[j++];
	n_line[i] = '\0';
	return (free(p_line), n_line);
}
