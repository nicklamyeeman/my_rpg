/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** event
*/

#include "rpg.h"

int	my_listlen(obj_t *list)
{
	int	i = 0;

	while (list != NULL) {
		i += 1;
		list = list->next;
	}
	return (i);
}

int	move_cursor_inv(rpg_t *rp, sfEvent ev)
{
	sfVector2f	pos = sfSprite_getPosition(rp->sprite[3].sprite);
	int	max = my_listlen(rp->obj);

	rp->bol.obj = rp->bol.obj % max;
	if (ev.key.code == sfKeyDown) {
		if (rp->bol.obj == max - 1)
			pos.y -= 100 * max;
		rp->bol.obj += 1;
		pos.y += 100;
		sfSprite_setPosition(rp->sprite[3].sprite, pos);
	}
	if (ev.key.code == sfKeyUp) {
		if (rp->bol.obj == 0) {
			rp->bol.obj = max;
			pos.y += 100 * max;
		}
		rp->bol.obj -= 1;
		pos.y -= 100;
		sfSprite_setPosition(rp->sprite[3].sprite, pos);
	}
}

void	check_item_selected(rpg_t *rp)
{
	sfFloatRect	rec = sfSprite_getGlobalBounds(rp->sprite[3].sprite);
	sfVector2f	vec = v2f(rec.left + 370, rec.top - 30);
	sfVector2f	cpy = v2f(rec.left + 310, rec.top);

	sfSprite_setPosition(rp->sprite[7].sprite, vec);
	rp->bol.stat = 1;
}

int	event_inv(rpg_t *rp, sfEvent ev)
{
	if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyEscape) {
		rp->bol.stat = (rp->bol.stat == 1) ? 0 : rp->bol.stat;
		return (0);
	}
	if (ev.type == sfEvtKeyPressed && rp->bol.stat != 1)
		move_cursor_inv(rp, ev);
	if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyReturn)
		check_item_selected(rp);
}