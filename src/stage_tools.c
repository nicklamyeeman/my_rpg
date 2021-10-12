/*
** EPITECH PROJECT, 2018
** stage_tools
** File description:
** Tools to work with the stage linked list
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "rpg.h"

void	add_object(stage **list, char *line)
{
	int	i = 0;
	stage	*elem = malloc(sizeof(*elem));
	stage	*tmp = *list;

	elem->type = cut_text(&i, line);
	elem->x = cut_param(&i, line);
	elem->y = cut_param(&i, line);
	elem->texture = sfTexture_createFromFile(cut_text(&i, line), NULL);
	elem->scale = cut_param(&i, line);
	elem->box = set_box(&i, line);
	elem->class = cut_text(&i, line);
	elem->scene = cut_text(&i, line);
	elem->next = NULL;
	if (*list == NULL) {
		*list = elem;
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
}

void	suppr_object(stage *list)
{
	sfTexture_destroy(list->texture);
	list = list->next;
}

void	suppr_stage(stage *list)
{
	while (list != NULL) {
		sfTexture_destroy(list->texture);
		list = list->next;
	}
}
