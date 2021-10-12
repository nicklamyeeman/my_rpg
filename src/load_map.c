/*
** EPITECH PROJECT, 2018
** load_map
** File description:
** Load a map in an array
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "rpg.h"
#include "get_next_line.h"

map_t	*load_map(char *map_name, map_t *map)
{
	int	fd = open(map_name, O_RDONLY);
	char	*buf = get_next_line(fd);

	while (buf != NULL) {
		add_to_map(&map, buf);
		buf = get_next_line(fd);
	}
	close(fd);
	return (map);
}
