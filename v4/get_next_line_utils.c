/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:03:44 by dvavryn           #+#    #+#             */
/*   Updated: 2025/05/08 22:38:14 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_calloc(size_t nmemb, size_t size)
{
	void			*out;
	size_t			total;
	size_t			i;
	unsigned char	*ptr;

	total = nmemb * size;
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (total / size != nmemb)
		return (NULL);
	out = malloc(total);
	if (!out)
		return (NULL);
	i = 0;
	ptr = (unsigned char *)out;
	while (i < total)
	{
		ptr[i] = 0;
		i++;
	}
	return (out);
}

char	*gnl_strdup(const char *s)
{
	char	*out;
	size_t	i;

	if (s == 0)
		return (NULL);
	out = (char *)malloc(gnl_strlen(s) + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		out[i] = s[i];
		i++;
	}
	out[i] = 0;
	return (out);
}

char	*gnl_strjoin(char *s1, const char *s2)
{
	char	*out;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	out = (char *)malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	while (s1[i] != 0)
	{
		out[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		out[i] = s2[j];
		i++;
		j++;
	}
	out[i] = 0;
	free(s1);
	return (out);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
