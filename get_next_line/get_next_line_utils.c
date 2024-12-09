/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:11:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/12/07 19:08:36 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	line_len(char *line)
{
	ssize_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

void	mv_buff(char *buffer)
{
	ssize_t	i;
	ssize_t	c_pos;

	i = 0;
	c_pos = line_len(buffer);
	while (buffer)
		buffer[i++] = buffer[c_pos++];
}

char	*line_join(char *p_line, char *buffer)
{

}
