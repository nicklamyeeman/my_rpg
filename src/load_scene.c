/*
** EPITECH PROJECT, 2018
** load_scene
** File description:
** Load the scene config file
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "rpg.h"
#include "get_next_line.h"

stage	*load_scene(stage *menu, char *file)
{
	int	fd = open(concat_str("./config/", file), O_RDONLY);
	int	loop = 1;
	char	*line = NULL;

	menu = NULL;
	if (fd == -1) {
		my_putstr("Error: No '");
		my_putstr(file);
		my_putstr("' config file found.\n");
		return (NULL);
	}
	while (loop) {
		line = get_next_line(fd);
		if (line == NULL)
			loop = 0;
		else
			add_object(&menu, line);
	}
	close(fd);
	return (menu);
}
