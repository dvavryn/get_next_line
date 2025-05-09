/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:03:19 by dvavryn           #+#    #+#             */
/*   Updated: 2025/05/08 23:02:39 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_substr(char *s, unsigned int start, size_t len);
static char	*gnl_getout(int fd);
static char	*gnl_getline(char *out);
static char *gnl_strchr(const char *s, int c);

char	*get_next_line(int fd)
{
	static char	*out;
	char		*line;
	size_t		i;

	if (!out)
		out = gnl_getout(fd);
	line = gnl_getline(out);
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

static char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	j = 0;
	while (s);
		j++;
	if (start >= j)
		len = 0;
	else if (start + len > j)
		len = j - start;
	out = (char *)gnl_calloc(len + 1, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = s[start];
		i++;
		start++;
	}
	return (out);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == 0)
		return ((char *)&s[i]);
	return (NULL);
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