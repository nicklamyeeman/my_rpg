/*
** EPITECH PROJECT, 2018
** add_to_map
** File description:
** add a tile to the map
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "rpg.h"

char	*retrieve_name(char *buf)
{
	int	i = 0;
	char	*to_re = NULL;

	if (buf == NULL)
		return (NULL);
	while (buf[i] != '\0' && buf[i] != ' ')
		i++;
	if (buf[i] == '\0')
		return (NULL);
	to_re = malloc(i + 1);
	if (to_re == NULL)
		return (NULL);
	to_re[i] = '\0';
	i--;
	while (i >= 0) {
		to_re[i] = buf[i];
		i--;
	}
	return (to_re);
}

int	is_wall(char *buf)
{
	int	i = 0;

	while (buf[i] != ' ')
		i++;
	i++;
	while (buf[i] != ' ')
		i++;
	i++;
	while (buf[i] != ' ')
		i++;
	i++;
	return (buf[i] - '0');
}

int	is_spawn(char *buf)
{
	int	i = 0;

	while (buf[i] != ' ')
		i++;
	i++;
	while (buf[i] != ' ')
		i++;
	i++;
	while (buf[i] != ' ')
		i++;
	i++;
	while (buf[i] != ' ')
		i++;
	i++;
	return (buf[i] - '0');
}

int	recup_coord(char *buf, int *i)
{
	while (buf[*i] != ' ')
		*i += 1;
	*i += 1;
	return (my_getnbr(buf + *i));
}

void	add_to_map(map_t **map, char *buf)
{
	map_t	*tmp = *map;
	map_t	*elem = malloc(sizeof(*elem));
	int	i = 0;

	elem->x = recup_coord(buf, &i);
	elem->y = recup_coord(buf, &i);
	elem->name = retrieve_name(buf);
	elem->wall = is_wall(buf);
	elem->spawn = is_spawn(buf);
	elem->next = NULL;
	if (*map == NULL) {
		*map = elem;
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
}
