/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:30:15 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 19:24:08 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *string, char character)
{
	size_t	counter;

	counter = 0;
	while (*string)
	{
		while (*string == character)
			string++;
		if (*string && *string != character)
		{
			counter++;
			while (*string && *string != character)
				string++;
		}
	}
	return (counter);
}

static char	**recursive_split(char **matrix, char const *string, char character)
{
	char	*substring;

	while (*string && *string == character)
		string++;
	if (!*string)
		return (matrix);
	substring = (char *)string;
	while (*string && *string != character)
		string++;
	*matrix = ft_substr(substring, 0, string - substring);
	if (!*matrix)
		return (NULL);
	return (recursive_split(matrix + 1, string, character));
}

char	**ft_split(char const *string, char character)
{
	char	**matrix;
	char	**error;

	if (!string)
		return (NULL);
	matrix = ft_calloc(word_count(string, character) + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	error = matrix;
	if (!recursive_split(matrix, string, character))
	{
		while (*error)
			free(*error++);
		free(matrix);
		return (NULL);
	}
	return (matrix);
}
