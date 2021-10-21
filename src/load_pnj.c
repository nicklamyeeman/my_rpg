/*
** EPITECH PROJECT, 2018
** load_pnj
** File description:
** Load the pnjs from a config file
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

void	add_pnj(pnj_t **pnj, char *line)
{
	int	i = 0;
	pnj_t	*elem = malloc(sizeof(*elem));
	pnj_t	*tmp = *pnj;

	elem->name = cut_text(&i, line);
	elem->x = cut_param(&i, line);
	elem->y = cut_param(&i, line);
	elem->dialog_file = cut_text(&i, line);
	elem->texture = cut_text(&i, line);
	elem->direction = cut_param(&i, line);
	elem->next = NULL;
	if (*pnj == NULL) {
		*pnj = elem;
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
}

pnj_t	*load_pnj()
{
	pnj_t *pnj = NULL;
	int	fd = open("./config/.pnj", O_RDONLY);
	int	loop = 1;
	char	*line;

	if (fd == -1) {
		my_putstr("Error: The pnj file is missing/\n");
		return (NULL);
	}
	while (loop) {
		line = get_next_line(fd);
		if (line == NULL)
			loop = 0;
		else
			add_pnj(&pnj, line);
	}
	close(fd);
	return (pnj);
}
