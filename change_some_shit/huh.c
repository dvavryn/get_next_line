#include "get_next_line.h"

static char    *get_line(int fd, char *left_c, char *buffer);
static char    *_set_line(char *line);

char    *get_next_line(int fd)
{
    static char *left_c;
    char        *line;
    char        *buffer;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(left_c);
        free(buffer);
        return (NULL);
    }
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    line = get_line(fd, left_c, buffer);
    free(buffer);
    if (!line)
        return (NULL);
    left_c = _set_line(line);
    return (line);
}

static char *get_buffer(char *line)
{
    char    *left_c;
    ssize_t    i;
    
    i = 0;
    while (line[i] != '\n' && line[i] != '\0')
        i++;
    if (line[i] == 0 || line[1] == 0)
        return (NULL);
    left_c = ft_substr(line, i + 1, ft_strlen(line) - i);
    if (*left_c == 0)
        free(left_c);
    line[i + 1] = 0;
    return (left_c);
}

static char	*get_line(int fd, char *left_c, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}
