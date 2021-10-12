/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** display win
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <fcntl.h>
#include "rpg.h"

void	display_teamt(win_t *win, btle_t *btle, chara_t *perso)
{
	sfVector2f	p;

	sfRenderWindow_drawSprite(win->win, perso[2].perss, NULL);
	if (perso[2].hplt <= 0) {
		p = sfSprite_getPosition(perso[2].perss);
		sfSprite_setPosition(btle->rips, p);
		sfRenderWindow_drawSprite(win->win, btle->rips, NULL);
	}
	else
		draw_auras(win, perso, 2);
	sfRenderWindow_drawSprite(win->win, perso[0].perss, NULL);
	isdead_perso(win, btle, perso);
}

void	display_ennem(win_t *win, btle_t *btle, ennem_t *ennem)
{
	for (int i = 0; ennem[i].name != NULL; i ++)
		dead_ennem(win, btle, ennem, i);}

void	battle_time(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	sfRenderWindow_drawSprite(win->win, btle->bgs, NULL);
	display_teamt(win, btle, p);
	display_ennem(win, btle, ennem);
}

void	display_win2(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	(win->f == 34) ? adko_display(win, btle, p, ennem) : 0;
	(win->f == 36) ? vvme_display(win, btle, p, ennem) : 0;
	(win->f == 38) ? verx_display(win, btle, p, ennem) : 0;
	(win->f == 40) ? fepn_display(win, btle, p, ennem) : 0;
	(win->f == 42) ? vapc_display(win, btle, p, ennem) : 0;
	(win->f == 44) ? bteq_display(win, btle, p, ennem) : 0;
}

void	display_window(win_t *win, btle_t *btle, chara_t *p, ennem_t *ennem)
{
	battle_time(win, btle, p, ennem);
	(win->f == 0) ? dmva_display(win, btle, p, ennem) : 0;
	(win->f == 2) ? qdfv_display(win, btle, p, ennem) : 0;
	(win->f == 4) ? qvva_display(win, btle, p, ennem) : 0;
	(win->f == 6) ? vpae_display(win, btle, p, ennem) : 0;
	(win->f == 8) ? toch_display(win, btle, p, ennem) : 0;
	(win->f == 10) ? qsvl_display(win, btle, p, ennem) : 0;
	(win->f == 12) ? vpls_display(win, btle, p, ennem) : 0;
	(win->f == 14) ? qvvs_display(win, btle, p, ennem) : 0;
	(win->f == 16) ? heal_display(win, btle, p, ennem) : 0;
	(win->f == 18) ? vprm_display(win, btle, p, ennem) : 0;
	(win->f == 20) ? vprf_display(win, btle, p, ennem) : 0;
	(win->f == 22) ? vplf_display(win, btle, p, ennem) : 0;
	(win->f == 24) ? eavp_display(win, btle, p, ennem) : 0;
	(win->f == 26) ? ento_display(win, btle, p, ennem) : 0;
	(win->f == 28) ? crit_display(win, btle, p, ennem) : 0;
	(win->f == 30) ? ratk_display(win, btle, p, ennem) : 0;
	(win->f == 32) ? vpap_display(win, btle, p, ennem) : 0;
	(win->f >= 34) ? display_win2(win, btle, p, ennem) : 0;
}