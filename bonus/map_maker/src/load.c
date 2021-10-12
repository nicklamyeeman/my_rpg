/*
** EPITECH PROJECT, 2018
** load
** File description:
** Load a map
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "proto.h"
#include "get_next_line.h"

char	*retrieve_name(char *info)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;
	char	*to_re;

	while (info[i] != ' ') {
		if (info[i - 1] == '/')
			j = i;
		i++;
	}
	to_re = malloc(i - j + 1);
	to_re[i - j] = '\0';
	while (j != i) {
		to_re[k] = info[j];
		k++;
		j++;
	}
	return (to_re);
}

int	retrieve_coordinates(int *i, char *info, int wall)
{
	int	nb = 0;

	while (info[*i] != ' ')
		*i += 1;
	*i += 1;
	while (info[*i] >= '0' && info[*i] <= '9') {
		nb *= 10;
		nb += info[*i] - '0';
		*i += 1;
	}
	if (wall == 1 && nb != 1)
		return (0);
	return (nb);
}

void	load_map_elem(map_s **map, char *info)
{
	map_s	*elem = malloc(sizeof(*elem));
	map_s	*tmp = *map;
	int	i = 0;
	char	*str;

	elem->texture_name = retrieve_name(info);
	str = concat_strings("./texture/", elem->texture_name);
	elem->texture = sfTexture_createFromFile(str, NULL);
	elem->x = retrieve_coordinates(&i, info, 0);
	elem->y = retrieve_coordinates(&i, info, 0);
	elem->wall = retrieve_coordinates(&i, info, 1);
	elem->spawn = retrieve_coordinates(&i, info, 1);
	elem->next = NULL;
	if (*map == NULL) {
		*map = elem;
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
}

void	load(map_s **map, char *name)
{
	int	fd;
	char	*buf;

	destroy_map(map);
	fd = open(concat_strings("./saves/", name), O_RDONLY);
	if (fd == -1)
		return;
	buf = get_next_line(fd);
	while (buf != NULL) {
		load_map_elem(map, buf);
		buf = get_next_line(fd);
	}
	close(fd);
}
