/*
** EPITECH PROJECT, 2018
** load_dialog
** File description:
** load dialogs
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

void	load_dialog(player_t *p, pnj_t *pnj)
{
	int	fd;
	int	i = 0;
	char	*buf = NULL;
	pnj_t	*tmp = pnj;

	while (!same_strings(tmp->name, p->speaking_with))
		tmp = tmp->next;
	fd = open(tmp->dialog_file, O_RDONLY);
	if (fd == -1)
		return;
	while (i != p->line) {
		buf = get_next_line(fd);
		i++;
	}
	close(fd);
	p->dialog = buf;
}
