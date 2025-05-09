/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:03:19 by dvavryn           #+#    #+#             */
/*   Updated: 2025/05/08 22:48:01 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_getout(int fd);
static char	*gnl_getline(char *out);

char	*get_next_line(int fd)
{
	static char	*out;
	char		*line;
	char		*tmp;
	size_t		i;

	tmp = NULL;
	if (!out)
		out = gnl_getout(fd);
	if (!out)
		return (NULL);
	line = gnl_getline(out);
	if (!line)
	{
		free(out);
		out = NULL;
		return (NULL);
	}
	i = 0;
	while (out[i] == line[i] && out[i] != 0)
		i++;
	while (out[i] == '\n')
		i++;
	if (out[i] == 0)
	{
		free(out);
		out = NULL;
	}
	else
	{
		tmp = gnl_strdup(out + i);
		free(out);
		out = tmp;
	}
	return (line);
}

static char	*gnl_getout(int fd)
{
	char	*out;
	char	*buffer;
	char	*tmp;
	ssize_t	bytes;

	bytes = 1;
	buffer = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	out = gnl_strdup("");
	if (!buffer || !out)
	{
		free(buffer);
		free(out);
		return (NULL);
	}
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			break ;
		tmp = gnl_strjoin(out, buffer);
		out = gnl_strdup(tmp);
		free(tmp);
	}
	free(buffer);
	return (out);
}

static char	*gnl_getline(char *out)
{
	char	*line;
	size_t	i;

	i = 0;
	while (out[i] != 0 && out[i] != '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (out[i] != 0 && out[i] != '\n')
	{
		line[i] = out[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main (void)
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	char *s;
	s = get_next_line(fd);
	printf(">>%s<<\n", s);
	free(s);
	s = get_next_line(fd);
	printf(">>%s<<\n", s);
	free(s);
	s = get_next_line(fd);
	printf(">>%s<<\n", s);
	free(s);
	close(fd);
}