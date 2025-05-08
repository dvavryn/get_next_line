/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:14:56 by dvavryn           #+#    #+#             */
/*   Updated: 2025/05/08 16:28:24 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// main
char	*get_next_line(int fd);

// side 
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(const char *s1, const char *s2);
char	*gnl_strdup(const char *s);
void	*gnl_calloc(size_t nmemb, size_t size);

#endif