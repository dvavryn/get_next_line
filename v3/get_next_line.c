/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:19:33 by dvavryn           #+#    #+#             */
/*   Updated: 2025/05/08 22:28:58 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *out;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!out)
	{
		char *buffer;
		char *tmp;
		ssize_t bytes;
		buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		out = strdup("");
		bytes = 1;
		while (bytes)
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			tmp = strjoin(out, buffer);
			free(out);
			out = strdup(tmp);
			free(tmp);
		}
		free(buffer);
	}
}