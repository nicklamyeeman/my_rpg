/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** mdr
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include "rpg.h"

void	split(fight_t *source, fight_t **front, fight_t **back)
{
	fight_t *fast;
	fight_t *slow;

	if (source == NULL || source->next == NULL) {
		*front = source;
		*back = NULL;
		return;
	}
	slow = source;
	fast = source->next;
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = source;
	*back = slow->next;
	slow->next = NULL;
}

fight_t	*sorted_merge_file(fight_t *a, fight_t *b)
{
	fight_t	*result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->vit >= b->vit) {
		result = a;
		result->next = sorted_merge_file(a->next, b);
	}
	else {
		result = b;
		result->next = sorted_merge_file(a, b->next);
	}
	return (result);
}

void	sort(fight_t **order)
{
	fight_t *head = *order;
	fight_t *a;
	fight_t *b;

	if (!head || !(head->next))
		return;
	split(head, &a, &b);
	sort(&a);
	sort(&b);
	*order = sorted_merge_file(a, b);
}

void	my_put_in_listp(chara_t *perso, int i, int type, fight_t **order)
{
	fight_t *tmp = *order;
	fight_t	*elem;

	elem = malloc(sizeof(*elem));
	elem->type = type;
	elem->perso = i;
	elem->vit = perso[i].vit;
	if (tmp == NULL) {
		*order = elem;
		(*order)->next = NULL;
		return;
	}
	elem->next = tmp;
	*order = elem;
}

void	my_put_in_listc(ennem_t *ennem, int k, fight_t **order)
{
	fight_t *tmp = *order;
	fight_t	*elem;

	elem = malloc(sizeof(*elem));
	elem->type = ennem[k].comb;
	elem->perso = k;
	elem->vit = ennem[k].vit;
	if (tmp == NULL) {
		*order = elem;
		(*order)->next = NULL;
		return;
	}
	elem->next = tmp;
	*order = elem;
}
