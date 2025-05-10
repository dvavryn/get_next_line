/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:41:19 by dvavryn           #+#    #+#             */
/*   Updated: 2025/05/11 00:51:19 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	l;

	if (!s)
		return (NULL);
	l = 0;
	while (s[l] != '\0')
		l++;
	if (start >= l)
		len = 0;
	else if (start + len > l)
		len = l - start;
	out = (char *)ft_calloc(len + 1, sizeof(char));
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*out;
	size_t	total;
	size_t	i;
	unsigned char *ptr;
	
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	out = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		out[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		out[i] = s2[j];
		i++;
		j++;
	}
	return (out);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*out;
	size_t	i;

	out = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		out[i] = s[i];
		i++;
	}
	return (out);
}