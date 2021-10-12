/*
** EPITECH PROJECT, 2018
** start_game
** File description:
** Launch the game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpg.h"

void	destroy_map(map_t **map)
{
	map_t	*tmp = *map;

	while (*map != NULL) {
		*map = tmp->next;
		free(tmp->name);
		free(tmp);
		tmp = *map;
	}
}

void	move_or_not(win_t *w, player_t *p, map_t *map, pnj_t *pnj)
{
	sfMusic	*m;
	int	is_sound = 0;

	if (p->moving == 1) {
		foot_steps(p, map, &m, &is_sound);
		move_if_needed(w, p, map, pnj);
		is_it_a_fight(w, p, map);
		p->moving = 0;
	}
	else
		display_map(w, p, map, pnj);
	if (is_sound)
		sfMusic_destroy(m);
	if (p->speaking_with != NULL)
		speak_pnj(w, p);
}

void	check_move(player_t *p, map_t *map)
{
	if (p->mvx != 0 || p->mvy != 0) {
		sfClock_restart(p->clock);
		p->moving = 1;
	}
}

void	move_event(player_t *p, map_t *map, pnj_t *pnj, rpg_t *rp)
{
	if (rp->bol.menu == GAME && p->speaking_with == NULL) {
		move_player(p, map, pnj);
		check_move(p, map);
	}
}

void	start_game(win_t *w, player_t *player, rpg_t rp)
{
	map_t	*map = NULL;
	pnj_t	*pnj = load_pnj(pnj);

	sfMusic_destroy(w->audio.theme);
	rp = init_struct(rp, w);
	w->loop = 1;
	map = load_map("./maps/.map", map);
	w->cur_scene = "play";
	w->audio = init_audio("./ressources/audio/ambiance.ogg");
	while (w->loop && sfRenderWindow_isOpen(w->win)) {
		sfRenderWindow_clear(w->win, sfBlack);
		house_movement(w, player, map);
		game_events(w, player, &rp, pnj);
		move_event(player, map, pnj, &rp);
		move_or_not(w, player, map, pnj);
		do_events(&rp, player);
		render_transition(w);
		sfRenderWindow_display(w->win);
	}
	destroy_map(&map);
}
