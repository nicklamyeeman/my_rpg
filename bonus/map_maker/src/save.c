/*
** EPITECH PROJECT, 2018
** save
** File description:
** save the map
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "proto.h"

int	count_size_int(int nb)
{
	int	i = 0;

	while (nb > 0) {
		nb /= 10;
		i++;
	}
	return (i);
}

char	*int_to_str(int nb)
{
	int	i = count_size_int(nb);
	char	*to_re;

	if (i == 0)
		return ("0");
	to_re = malloc(i + 1);
	to_re[i] = '\0';
	i--;
	while (i >= 0) {
		to_re[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (to_re);
}

void	concat_info(map_s *t, int fd, char * wall)
{
	int	size = 0;
	char	*to_re;

	if (t == NULL || same_strings(t->texture_name, wall) == 1)
		return;
	size += my_strlen(t->texture_name) + 2;
	size += my_strlen(int_to_str(t->x));
	size += my_strlen(int_to_str(t->y));
	to_re = concat_strings(t->texture_name, " ");
	to_re = concat_strings(to_re, int_to_str(t->x));
	to_re = concat_strings(to_re, " ");
	to_re = concat_strings(to_re, int_to_str(t->y));
	to_re = concat_strings(to_re, " ");
	to_re = concat_strings(to_re, int_to_str(t->wall));
	to_re = concat_strings(to_re, " ");
	to_re = concat_strings(to_re, int_to_str(t->spawn));
	write(fd, to_re, my_strlen(to_re));
	write(fd, "\n", 1);
}

void	find_max(map_s **map, int *x_max, int *y_max)
{
	map_s	*tmp = *map;

	while (tmp != NULL) {
		if (tmp->x > *x_max)
			*x_max = tmp->x;
		if (tmp->y > *y_max)
			*y_max = tmp->y;
		tmp = tmp->next;
	}
}

void	save(map_s **map, char *name)
{
	map_s	*t = *map;
	int	fd = open(name, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	char	*wall = "./texture/wall.png";
	int	x = 0;
	int	y = 0;
	int	x_max = 0;
	int	y_max = 0;

	find_max(map, &x_max, &y_max);
	while (y <= y_max) {
		while ((t != NULL && t->x != x) || (t != NULL && t->y != y))
			t = t->next;
		concat_info(t, fd, wall);
		t = *map;
		x++;
		if (x > x_max) {
			x = 0;
			y++;
		}
	}
	close(fd);
}
