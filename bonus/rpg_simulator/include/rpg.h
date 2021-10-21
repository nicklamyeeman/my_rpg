/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** header
*/

#ifndef RPG_H_
#define RPG_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

/* Structs */

/* Battle Simulator */

typedef	struct	s_spell
{
	char	*spell1;
	char	*spell2;
}	spell_t;

typedef struct	s_chara
{
	char	*name;
	sfFont	*pefon;
	sfText	*petex;
	int	lvl;
	int	hplt;
	int	hpmx;
	int	pmlt;
	int	pmmx;
	int	def;
	int	rm;
	int	atk;
	int	mg;
	int	vit;
	int	prec;
	int	esc;
	int	pc;
	int	exp;
	sfTexture	*perst;
	sfSprite	*perss;
	sfTexture	*aurat;
	sfSprite	*auras;
	sfIntRect	aurec;
	sfClock	*auclo;
	sfTime	autim;
	spell_t	spell;
}	chara_t;

/* 0 = Paladin; 1 = Mage; 2 = Archer; 3 = Voleur; 4 = Menestrel */

typedef struct	s_ennem
{
	char	*name;
	int	coef;
	int	hplt;
	int	hpmx;
	int	atk;
	int	mag;
	int	def;
	int	rm;
	int	vit;
	int	exp;
}	ennem_t;

typedef	struct	s_comb
{
	ennem_t	*ennem;
}	comb_t;

typedef	struct	s_fight
{
	int	vit;
	int	type;
	int	perso;
	struct	s_fight *next;
}	fight_t;

/* CSFML */
typedef	struct	s_win
{
	sfRenderWindow	*win;
	sfVideoMode	mode;
	sfEvent	evt;
}	win_t;

typedef	struct	s_turn
{
	sfTexture	*qdfvt;
	sfSprite	*qdfvs;
	sfTexture	*aseft;
	sfSprite	*asefs;
	sfTexture	*arrot;
	sfSprite	*arros;
	sfIntRect	arrec;
	sfClock	*arclo;
	sfTime	artim;
}	turn_t;

typedef	struct	s_btle
{
	sfTexture	*bgt;
	sfSprite	*bgs;
	turn_t	turn;
}	btle_t;

void	do_assassin(chara_t *);
void	do_archer(chara_t *);
void	do_troub(chara_t *);
void	do_pala(chara_t *);
void	do_majo(chara_t *);

spell_t	spell_mage();
spell_t	spell_pala();
spell_t	spell_assas();
spell_t	spell_troub();
spell_t	spell_archer();

ennem_t	init_bidoof(void);
ennem_t	init_pampa(void);
ennem_t	init_troll(void);
ennem_t	init_gob(void);

chara_t	init_mage(void);
chara_t	init_pala(void);
chara_t	init_troub(void);
chara_t	init_archer(void);
chara_t	init_assassin(void);

ennem_t	*init_easy();
ennem_t	*init_hard();
ennem_t	*init_bigxp();
ennem_t	*init_horde();
ennem_t	*init_trolz();

chara_t	*init_perso();
int	choose_hero(chara_t *);
int	get_class(chara_t *, int);
void	my_print_struct(chara_t *);
void	upgrade_hero(chara_t *, int);
int	start_fight(comb_t *, chara_t *);

int	my_strcmp(char const *, char const *);
char	*my_strdup(char const *);
int	my_printf(char *, ...);
char	*get_next_line(int);
int	my_putchar(char);
int	my_putstr(char *);
int	my_getnbr(char *);
char	*my_strcat(char *, char *);

int	print_team(chara_t *);
void	my_print_ennem(comb_t *, int, int);
comb_t	*init_ennemies();
void	print_ennemies(comb_t *, int);
int	get_ennem(chara_t *, ennem_t *, char *, int);

void	battle_orupgrade(chara_t *, comb_t *);
void	victory_nxp(comb_t *, int, chara_t *);
int	go_fight(comb_t *, int, chara_t *);
void	my_print_perso(chara_t *, int);
int	end_team(chara_t *);
int	end_ennem(comb_t *, int);
int	team_turn(comb_t *, int, chara_t *, fight_t *);
int	let_hurt_them(comb_t *, int, chara_t *, fight_t *);
int	let_spell_us(comb_t *, int, chara_t *, fight_t *);
int	team_touch(ennem_t *, int);
int	ennem_exist(char *, comb_t *, int);

int	which_pone(comb_t *, int, chara_t *, fight_t *);
int	which_ptwo(comb_t *, int, chara_t *, fight_t *);
void	pala_sone2(comb_t *, int, chara_t *, fight_t *);
void	mage_sone2(comb_t *, int, chara_t *, fight_t *);
int	pala_sone(comb_t *, int, chara_t *, fight_t *);
int	mage_sone(comb_t *, int, chara_t *, fight_t *);
int	arch_sone(comb_t *, int, chara_t *, fight_t *);
int	vole_sone(comb_t *, int, chara_t *, fight_t *);
int	mene_sone(chara_t *, fight_t *);
int	pala_stwo(chara_t *, fight_t *);
int	mage_stwo(comb_t *, int, chara_t *, fight_t *);
int	arch_stwo(comb_t *, int, chara_t *, fight_t *);
int	vole_stwo(comb_t *, int, chara_t *, fight_t *);
int	mene_stwo(chara_t *, fight_t *);
int	vole_sone2(ennem_t *, chara_t *, fight_t *);
int	mage_stwo2(ennem_t *, chara_t *, fight_t *);
int	arch_stwo2(ennem_t *, chara_t *, fight_t *);
int	vole_stwo2(ennem_t *, chara_t *, fight_t *);
int	arch_sone2(ennem_t *, chara_t *, fight_t *);
void	mene_sone2(int, chara_t *, fight_t *);
int	pala_stwo2(int, chara_t *, fight_t *);
void	mene_stwo2(int, chara_t *, fight_t *);

void	sort(fight_t **);
void	my_put_in_listc(comb_t *, int, int, fight_t **);
void	my_put_in_listp(chara_t *, int, int, fight_t **);

sfVector2f	v2f(float, float);

void	init_turn(btle_t *);
void	init_window(win_t *);
int	battle_event(win_t *, btle_t *, int);
chara_t	init_voletxt(chara_t);
chara_t	init_palatxt(chara_t);
chara_t	init_magetxt(chara_t);
chara_t	init_archtxt(chara_t);
chara_t	init_menetxt(chara_t);
void	display_window(win_t *, chara_t *);
void	draw_arrow(win_t *, btle_t *);
void	draw_auras(win_t *, chara_t *, int);

#endif /* !RPG_H_ */
