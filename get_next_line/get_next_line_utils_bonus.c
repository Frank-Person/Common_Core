/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:19:34 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/12/17 16:37:58 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	size_t	pl_len;
	size_t	bf_len;
	size_t	i;
	size_t	j;

	pl_len = line_len(p_line);
	bf_len = line_len(buffer);
	n_line = malloc(pl_len + bf_len + 1);
	if (!n_line)
		return (free(p_line), NULL);
	i = 0;
	j = 0;
	while (i < pl_len)
		n_line[i++] = p_line[j++];
	j = 0;
	while (j < bf_len)
		n_line[i++] = buffer[j++];
	n_line[i] = '\0';
	return (free(p_line), n_line);
}
