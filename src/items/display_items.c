/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** display items
*/

#include "rpg.h"

int	display_items(obj_t *it, rpg_t *rp)
{
	sfFloatRect	rec = sfSprite_getGlobalBounds(rp->sprite[6].sprite);
	sfVector2f	vec;

	vec.x = rec.top;
	vec.y = rec.left;
	vec.x += 250;
	vec.y += 320;
	while (it != NULL) {
		sfSprite_setPosition(it->itms.sprite, vec);
		vec.x += 130;
		vec.y += 18;
		sfSprite_setPosition(it->name.sprite, vec);
		sfRenderWindow_drawSprite(rp->wina.win, it->itms.sprite, NULL);
		sfRenderWindow_drawSprite(rp->wina.win, it->name.sprite, NULL);
		vec.x -= 130;
		vec.y -= 18;
		vec.y += 100;
		it = it->next;
	}
}