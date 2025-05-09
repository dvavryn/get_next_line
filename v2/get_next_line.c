/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:03:19 by dvavryn           #+#    #+#             */
/*   Updated: 2025/05/08 22:33:32 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_getout(int fd);
static char	*gnl_getline(char *out);
static char	*gnl_getremaining(char *out);

char	*get_next_line(int fd)
{
	static char	*out[2];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!out[0] && !out[1])
	{
		out[0] = gnl_getout(fd);
		out[1] = gnl_strdup("");
	}
	line = gnl_getline(out[0]);
	out[0] = gnl_getremaining(out[0]);
	if (!out[0] && out[1])
	{
		free(out[0]);
		free(out[1]);
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
	while (bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		tmp = gnl_strjoin(out, buffer);
		free(out);
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

static char	*gnl_getremaining(char *out)
{
	char	*buffer;
	size_t	i;
	size_t	j;
	
	i = 0;
	while(out[i] != 0 && out[i] != '\n')
		i++;
	if (out[i] == 0)
	{
		free(out);
		return (NULL);
	}
	buffer = (char *)calloc(gnl_strlen(out) - i + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	i++;
	j = 0;
	while (out[i] != 0)
	{
		buffer[j] = out[i];
		j++;
		i++;
	}
	free(out);
	return (buffer);
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


/* 
{
	i = 0;
	while (out[i] == line[i] && out[i] != 0)
		i++;
	while (out[i] == '\n')
		i++;
	if (out[i] == 0)
	{
		free(out);
		return (line);
	}
	out = out + i;
} */