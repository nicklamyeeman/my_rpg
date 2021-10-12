/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** Return a readed line from a file descriptor
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*my_memset(int size)
{
	int	i = 0;
	char	*to_re = malloc(sizeof(char) * size);

	if (to_re == NULL)
		return (NULL);
	to_re[size - 1] = '\0';
	while (i != size - 1) {
		to_re[i] = 0;
		i++;
	}
	return (to_re);
}

char	*my_concat(char *str, char c, int size)
{
	char	*to_re;
	int	i = 0;

	to_re = malloc(sizeof(char) * size + 1);
	if (to_re == NULL)
		return (NULL);
	to_re = my_memset(size + 2);
	to_re[size + 1] = '\0';
	while (i != size) {
		to_re[i] = str[i];
		i++;
	}
	to_re[i] = c;
	return (to_re);
}

int	add_buf(char *buf, int *i, char **to_return, int *size)
{
	while (*i != READ_SIZE) {
		if (*i == READ_SIZE && buf[*i] == '\n') {
			*i = 0;
			return (1);
		}
		if (buf[*i] == '\n') {
			*i += 1;
			return (1);
		}
		to_return[0] = my_concat(to_return[0], buf[*i], *size);
		*size += 1;
		*i += 1;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	static int	i = 0;
	char	*to_return = "\0";
	int	size = 0;

	if (i > 0)
		if (add_buf(buf, &i, &to_return, &size) == 1)
			return (to_return);
	i = 0;
	buf = my_memset(READ_SIZE + 1);
	while (read(fd, buf, READ_SIZE) != 0) {
		if (add_buf(buf, &i, &to_return, &size) == 1)
			return (to_return);
		i = 0;
		buf = my_memset(READ_SIZE + 1);
	}
	if (to_return[0] == '\0')
		return (NULL);
	return (to_return);
}
