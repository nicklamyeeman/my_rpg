/*
** EPITECH PROJECT, 2018
** change_gandoulf_dialog
** File description:
** Change gandoulf dialog
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	change_gandoulf_dialog(pnj_t *pnj)
{
	pnj_t	*t = pnj;

	while (t != NULL) {
		if (same_strings(t->name, "Gandoulf"))
			t->dialog_file = concat_str(t->dialog_file, "2");
		t = t->next;
	}
}
