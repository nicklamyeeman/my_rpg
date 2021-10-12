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

typedef struct	s_pnj
{
	char	*name;
	float	x;
	float	y;
	char	*dialog_file;
	char	*texture;
	int	direction;
	struct s_pnj	*next;
}	pnj_t;

typedef struct	stage
{
	sfTexture	*texture;
	sfIntRect	box;
	char	*type;
	char	*class;
	float	x;
	float	y;
	float	scale;
	char	*scene;
	struct stage	*next;
}	stage;

typedef struct	audio_s
{
	int	mute;
	int	volume;
	sfMusic	*theme;
}	audio_s;

typedef struct	map_t
{
	float	x;
	float	y;
	char	*name;
	int	spawn;
	int	wall;
	struct map_t	*next;
}	map_t;

typedef struct	s_window
{
	sfRenderWindow	*win;
	sfVideoMode	mode;
	float	width;
	float	height;
	int	ratio;
	int	fullscreen;
	sfEvent	evt;
	char	*cur_scene;
	char	*select;
	char	*class_select;
	int	alpha;
	int	x_mouse;
	int	y_mouse;
	stage	*scene;
	int	loop;
	int	f;
	struct audio_s	audio;
	int	boss;
}	win_t;

/* Battle Simulator */
typedef	struct	s_spell
{
	char	*spell1;
	sfFont	*s1fon;
	sfText	*s1tex;
	sfTexture	*spe1t;
	sfSprite	*spe1s;
	sfIntRect	s1rec;
	sfClock	*s1clo;
	sfTime	s1tim;
	char	*spell2;
	sfFont	*s2fon;
	sfText	*s2tex;
	sfTexture	*spe2t;
	sfSprite	*spe2s;
	sfIntRect	s2rec;
	sfClock	*s2clo;
	sfTime	s2tim;
}	spell_t;

typedef struct	s_chara
{
	char	*name;
	int	num;
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
	sfSprite	*cares;
	sfTexture	*caret;
	sfTexture	*arrot;
	sfSprite	*arros;
	sfIntRect	arrec;
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
	int	num;
	char	*name;
	sfFont	*enfon;
	sfText	*entex;
	int	hplt;
	int	hpmx;
	int	atk;
	int	mag;
	int	def;
	int	rm;
	int	vit;
	int	exp;
	int	comb;
	sfTexture	*ennet;
	sfSprite	*ennes;
	sfTexture	*arrot;
	sfSprite	*arros;
	sfIntRect	arrec;
	int	coef;
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
typedef	struct	s_turn
{
	sfTexture	*qdfvt;
	sfSprite	*qdfvs;
	sfTexture	*bteqt;
	sfSprite	*bteqs;
	sfTexture	*vvmet;
	sfSprite	*vvmes;
	sfTexture	*verxt;
	sfSprite	*verxs;
	sfTexture	*fepnt;
	sfSprite	*fepns;
	sfTexture	*vapct;
	sfSprite	*vapcs;
	sfTexture	*adkot;
	sfSprite	*adkos;
	sfTexture	*vpapt;
	sfSprite	*vpaps;
	sfTexture	*ratkt;
	sfSprite	*ratks;
	sfTexture	*critt;
	sfSprite	*crits;
	sfTexture	*vpppt;
	sfSprite	*vppps;
	sfTexture	*vpkot;
	sfSprite	*vpkos;
	sfTexture	*eavpt;
	sfSprite	*eavps;
	sfTexture	*vprpt;
	sfSprite	*vprps;
	sfTexture	*vprmt;
	sfSprite	*vprms;
	sfTexture	*qvvst;
	sfSprite	*qvvss;
	sfTexture	*vprft;
	sfSprite	*vprfs;
	sfTexture	*vplft;
	sfSprite	*vplfs;
	sfTexture	*qsvlt;
	sfSprite	*qsvls;
	sfTexture	*aekot;
	sfSprite	*aekos;
	sfTexture	*vpaet;
	sfSprite	*vpaes;
	sfTexture	*qvvat;
	sfSprite	*qvvas;
	sfTexture	*dmvat;
	sfSprite	*dmvas;
	sfTexture	*aseft;
	sfSprite	*asefs;
	sfTexture	*tocht;
	sfSprite	*tochs;
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
	sfTexture	*nextt;
	sfSprite	*nexts;
	sfIntRect	nerec;
	sfClock	*neclo;
	sfTime	netim;
	sfTexture	*ript;
	sfSprite	*rips;
	int	hp;
	int	xp;
	int	xpmax;
	sfFont	*hpfon;
	sfText	*hptex;
	fight_t *order;
	fight_t *tmp;
	turn_t	turn;
}	btle_t;

typedef struct	player_t
{
	float	x;
	float	y;
	float	mvx;
	float	mvy;
	sfClock	*clock;
	sfIntRect	rect;
	chara_t	*perso;
	int	moving;
	char	*speaking_with;
	char	*dialog;
	int	line;
}	player_t;

enum	repere
{
	GAME = 0,
	MENU = 1,
	STAT = 2,
	INV = 3,
	QUIT = 4
};

enum	menu
{
	OBJ = 0,
	EQUIPE = 1,
	OPT = 2,
	SAVE = 3
};

enum	persos
{
	PALA = 0,
	MAGE = 1,
	ARC = 2,
	VOL = 3,
	MENESTR = 4,
};

enum	item
{
	POTI = 0,
	EPEE = 1,
	ANNE = 2,
	BOUC = 3,
};

typedef struct	s_linked
{
	void	*perso;
	struct s_linked	*next;
}	link_t;

/* Liste chainée pour je sais plus quoi */

typedef struct s_view
{
	sfView	*view;
	int	x;
	int	y;
}	view_t;

/* Structure de la caméra pour la move et la créer */

typedef struct	s_sprites
{
	sfSprite	*sprite;
	sfTexture	*text;
	sfIntRect	rect;
	int	x;
	int	y;
	int	i;
}	sprites_t;

/* Structure pour faire des sprites a l'infini avec la fonction init_sprite */
/* 0 = map, 1 = perso, 2 = menu, 3 = flèche blanche, 4 = status, 
5 = carré du perso dans stat, 6 = inventaire, 7 = option items, 
8 = a qui ont veux donner l'item	*/

typedef struct	s_boo
{
	int	menu;
	int	stat;
	int	per;
	int	in;
	int	obj;
}	boo_t;

/* Structure pour les bools */

typedef struct	s_stat
{
	sfFont	*pok;
	sfText	*name;
	sfText	*lvl;
	sfText	*hp;
	sfText	*hpm;
	sfText	*pm;
	sfText	*pmm;
	sfText	*atk;
	sfText	*def;
	sfText	*mag;
	sfText	*rm;
	sfText	*vit;
	sfText	*prec;
	sfText	*esq;
	sfText	*expe;
}	stat_t;

/* structure de textes pour les diff stats */

typedef struct	s_objs
{
	sprites_t	name;
	sprites_t	itms;
	sprites_t	aqca;
	int	conso;
	struct s_objs	*next;
}	obj_t;

/*	liste chainée pour les items	*/

typedef struct	s_rpg
{
	sfRenderWindow	*win;
	win_t	wina;
	sprites_t	sprite[9];
	view_t	cam;
	view_t	camp;
	sfClock	*c;
	sfFloatRect	zone;
	boo_t	bol;
	stat_t	stat;
	int	i;
	obj_t	*obj;
}	rpg_t;

/* Grosse structure regroupant tout ce dont on a besoin pour le game */

int	my_strcmp(char const *, char const *);
char	*my_strdup(char const *);
int	my_printf(char *, ...);
char	*get_next_line(int);
int	my_putchar(char);
int	my_putstr(char *);
int	my_getnbr(char *);
char	*my_strcat(char *, char *);
int	display_items(obj_t *, rpg_t *);
int	init_items(obj_t **);
int	event_inv(rpg_t *, sfEvent);
int	do_events(rpg_t *, player_t *);
void	my_item_to_list(obj_t **, char *, char *, int);

rpg_t	init_struct(rpg_t, win_t *);
sfRenderWindow	*init_win(void);
sprites_t	init_sprite(char *, float, float);
int	load_sprites(rpg_t *);
stat_t	init_stats(void);

/* fonctions pour init les sprites/windows/etc... */

int	menu_event(rpg_t *, sfEvent);
int	setstruct_totext(rpg_t *, chara_t);
void	do_pause(void);
int	do_game(rpg_t *, chara_t *, comb_t *, btle_t);
int	game_event(rpg_t *, chara_t *, comb_t *, btle_t);
int	my_rpg(rpg_t);
int	get_in_combat(rpg_t *);

/* Fonctions pour les scènes / events */

sfVector2f	vec2f(float, float);

/* fonctions de lib SFML */

int	is_control(sfEvent);
void	move_camnchar(rpg_t *);
void	end_frame(rpg_t *);

/* Fonctions de mouvement */

void	free_spaces(rpg_t);

/* Fonctions de free */

int	display_menu(rpg_t *);
int	display_stats(rpg_t *, chara_t *);
int	event_stat(rpg_t *, sfEvent);

/* display */

sfVector2f	v2f(float, float);

void	move_cursor_ev(rpg_t *, sfEvent);
void	replace_menu(rpg_t *);
void	check_enter(rpg_t *, sfEvent);
int	in_battle(rpg_t *, chara_t *, comb_t *, btle_t);

void	do_assassin(chara_t *);
void	do_archer(chara_t *);
void	do_troub(chara_t *);
void	do_pala(chara_t *);
void	do_majo(chara_t *);

spell_t	spell_mage(spell_t);
spell_t	spell_pala(spell_t);
spell_t	spell_assas(spell_t);
spell_t	spell_troub(spell_t);
spell_t	spell_archer(spell_t);

ennem_t	init_bidoof(void);
ennem_t	init_pampa(void);
ennem_t	init_troll(void);
ennem_t	init_gob(void);

chara_t	init_mage(void);
chara_t	init_pala(void);
chara_t	init_troub(void);
chara_t	init_archer(void);
chara_t	init_assassin(void);

ennem_t	*init_easy(ennem_t *);
ennem_t	*init_hard(ennem_t *);
ennem_t	*init_bigxp(ennem_t *);
ennem_t	*init_horde(ennem_t *);
ennem_t	*init_trolz(ennem_t *);

chara_t	*init_perso(chara_t *);
int	choose_hero(chara_t *);
int	get_class(chara_t *, int);
void	my_print_struct(chara_t *);
void	upgrade_hero(chara_t *, int);
void	start_fight(win_t *, comb_t *, chara_t *);

int	my_strcmp(char const *, char const *);
char	*my_strdup(char const *);
int	my_printf(char *, ...);
char	*my_strcat(char *, char *);

int	print_team(chara_t *);
void	my_print_ennem(comb_t *, int, int);
comb_t	*init_ennemies(comb_t *);
void	print_ennemies(ennem_t *);
int	get_ennem(chara_t *, ennem_t *, char *, int);
char	*int_to_char(int);

void	battle_orupgrade(chara_t *, comb_t *);
void	victory_nxp(win_t *, btle_t *, ennem_t *, chara_t *);
int	go_fight(win_t *, btle_t *, ennem_t *, chara_t *);
void	my_print_perso(chara_t *, int);
int	end_team(chara_t *);
int	end_ennem(ennem_t *);
int	team_turn(win_t *, btle_t *, ennem_t *, chara_t *);
int	let_hurt_them(win_t *, btle_t *, ennem_t *, chara_t *);
int	let_spell_us(win_t *, btle_t *, ennem_t *, chara_t *);
int	team_touch(win_t *, chara_t *, btle_t *, ennem_t *);
int	ennem_exist(win_t *, btle_t *, chara_t *, ennem_t *);
void	crit_fct(win_t *, btle_t *, ennem_t *, chara_t *);
void	ratk_fct(win_t *, btle_t *, ennem_t *, chara_t *);
void	vpap_fct(win_t *, btle_t *, ennem_t *, chara_t *);
void	adko_fct(win_t *, btle_t *, ennem_t *, chara_t *);
void	vvme_fct(win_t *, btle_t *, ennem_t *, chara_t *);
void	verx_fct(win_t *, btle_t *, ennem_t *, chara_t *);
void	fepn_fct(win_t *, btle_t *, ennem_t *, chara_t *);
void	vapc_fct(win_t *, btle_t *, ennem_t *, chara_t *);
void	bteq_fct(win_t *, btle_t *, ennem_t *, chara_t *);

int	which_pone(win_t *, btle_t *, ennem_t *, chara_t *);
int	which_ptwo(win_t *, btle_t *, ennem_t *, chara_t *);
void	pala_sone2(win_t *, btle_t *, ennem_t *, chara_t *);
void	mage_sone2(win_t *, btle_t *, ennem_t *, chara_t *);
int	pala_sone(win_t *, btle_t *, ennem_t *, chara_t *);
int	mage_sone(win_t *, btle_t *, ennem_t *, chara_t *);
int	arch_sone(win_t *, btle_t *, ennem_t *, chara_t *);
void	arch_sone_oth(win_t *, btle_t *, ennem_t *, chara_t *);
int	vole_sone(win_t *, btle_t *, ennem_t *, chara_t *);
int	mene_sone(win_t *, btle_t *, ennem_t *, chara_t *);
int	pala_stwo(win_t *, btle_t *, ennem_t *, chara_t *);
int	mage_stwo(win_t *, btle_t *, ennem_t *, chara_t *);
int	arch_stwo(win_t *, btle_t *, ennem_t *, chara_t *);
int	vole_stwo(win_t *, btle_t *, ennem_t *, chara_t *);
int	mene_stwo(win_t *, btle_t *, ennem_t *, chara_t *);
int	vole_sone2(win_t *, ennem_t *, chara_t *, btle_t *);
int	mage_stwo2(win_t *, ennem_t *, chara_t *, btle_t *);
int	arch_stwo2(win_t *, ennem_t *, chara_t *, btle_t *);
int	vole_stwo2(win_t *, ennem_t *, chara_t *, btle_t *);
int	arch_sone2(win_t *, ennem_t *, chara_t *, btle_t *);
void	mene_sone2(win_t *, ennem_t *, chara_t *, btle_t *);
int	pala_stwo2(win_t *, ennem_t *, chara_t *, btle_t *);
void	mene_stwo2(win_t *, ennem_t *, chara_t *, btle_t *);

void	sort(fight_t **);
void	my_put_in_listc(ennem_t *, int, fight_t **);
void	my_put_in_listp(chara_t *, int, int, fight_t **);

sfVector2f	v2f(float, float);

void	init_turn(btle_t *);
void	init_qsvl(btle_t *);
void	init_battle(btle_t *);
void	init_eavp(btle_t *);
void	init_adko(btle_t *);
void	init_bteq(btle_t *);

chara_t	init_voletxt(chara_t);
chara_t	init_palatxt(chara_t);
chara_t	init_magetxt(chara_t);
chara_t	init_archtxt(chara_t);
chara_t	init_menetxt(chara_t);
chara_t	init_voletxt2(chara_t);
chara_t	init_palatxt2(chara_t);
chara_t	init_magetxt2(chara_t);
chara_t	init_archtxt2(chara_t);
chara_t	init_menetxt2(chara_t);
ennem_t	init_troltxt(ennem_t);
ennem_t	init_bidotxt(ennem_t);
ennem_t	init_gobetxt(ennem_t);
ennem_t	init_pamptxt(ennem_t);
ennem_t	*init_bigxptxt(ennem_t *);
ennem_t	*init_easytxt(ennem_t *);
ennem_t	*init_hardtxt(ennem_t *);
ennem_t	*init_hordetxt(ennem_t *);
ennem_t	*init_trolztxt(ennem_t *);

void	qdfv_event(win_t *, btle_t *);
void	dmva_event(win_t *, btle_t *);
void	qvva_event(win_t *, btle_t *, chara_t *, ennem_t *);
void	battle_event(win_t *, btle_t *, chara_t *, ennem_t *);
void	vpae_event(win_t *, btle_t *, ennem_t *);
void	toch_event(win_t *, btle_t *);
void	qsvl_event(win_t *, btle_t *);
void	vpls_event(win_t *, btle_t *);
void	vprm_event(win_t *, btle_t *);
void	eavp_event(win_t *, btle_t *);
void	ento_event(win_t *, btle_t *);
void	crit_event(win_t *, btle_t *);
void	ratk_event(win_t *, btle_t *);
void	vpap_event(win_t *, btle_t *);
void	adko_event(win_t *, btle_t *);
void	heal_event(win_t *, btle_t *);
void	vvme_event(win_t *, btle_t *);
void	verx_event(win_t *, btle_t *);
void	fepn_event(win_t *, btle_t *);
void	vapc_event(win_t *, btle_t *);
void	bteq_event(win_t *, btle_t *);

void	display_window(win_t *, btle_t *, chara_t *, ennem_t *);
void	display_ennem(win_t *, btle_t *, ennem_t *);
void	display_teamt(win_t *, btle_t *, chara_t *);
void	qdfv_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	qvva_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	dmva_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	toch_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	vpae_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	qsvl_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	vpls_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	vplf_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	vprf_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	qvvs_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	heal_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	vprm_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	eavp_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	ento_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	crit_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	ratk_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	vpap_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	adko_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	vvme_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	verx_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	fepn_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	vapc_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	bteq_display(win_t *, btle_t *, chara_t *, ennem_t *);
void	draw_auras(win_t *, chara_t *, int);

char	*get_next_line(int);
int	my_strlen(char const *);
int	is_in_it(char *, char *);
int	same_strings(char *, char *);
char	*concat_str(char *, char *);
sfVector2f	create_vector(float, float);
sfColor	fade_in(win_t *);
sfColor	fade_out(win_t *);
char	*cut_text(int *, char *);
float	cut_frac(int *, char *);
float	cut_param(int *, char *);
sfIntRect	create_box(int, int, int, int);
sfIntRect	set_box(int *, char *);
void	add_object(stage **, char *);
void	suppr_object(stage *);
void	suppr_stage(stage *);
audio_s	init_audio(char *);
win_t	init_window(win_t);
stage	*load_scene(stage *, char *);
void	render_mouse(win_t *);
void	render_stage(win_t *);
void	destroy_everything(win_t *);
void	switch_fullscreen(win_t *);
void	check_select(win_t *);
void	check_button_pressed(win_t *);
void	reset_buttons(win_t *);
void	menu_events(win_t *);
void	settings(win_t *);
void	roll_intro(win_t);
void	add_to_map(map_t **, char *);
map_t	*load_map(char *, map_t *);
void	house_movement(win_t *, player_t *, map_t *);
void	foot_steps(player_t *, map_t *, sfMusic **, int *);
void	move_if_needed(win_t *, player_t *, map_t *, pnj_t *);
void	move_player(player_t *, map_t *, pnj_t *);
void	speak_pnj(win_t *, player_t *);
void	load_dialog(player_t *, pnj_t *);
void	game_events(win_t *, player_t *, rpg_t *, pnj_t *);
void	render_transition(win_t *);
void	display_pnj(win_t *, pnj_t *, player_t *);
void	display_player(win_t *, player_t *);
void	display_map(win_t *, player_t *, map_t *, pnj_t *);
void	init_fight(win_t *, player_t *);
void	is_it_a_fight(win_t *, player_t *, map_t *);
pnj_t	*load_pnj(pnj_t *);
void	start_game(win_t *, player_t *, rpg_t);
void	new_game(win_t *);
void	launch_menu(void);
int	print_usage(void);

spell_t	spell_txtmage(spell_t);
spell_t	spell_txtpala(spell_t);
spell_t	spell_txtmene(spell_t);
spell_t	spell_txtarch(spell_t);
spell_t	spell_txtvole(spell_t);
void	speone_mage(win_t *, btle_t *, chara_t *, ennem_t *);
void	speone_pala(win_t *, btle_t *, chara_t *, ennem_t *);
void	speone_mene(win_t *, btle_t *, chara_t *, ennem_t *);
void	speone_arch(win_t *, btle_t *, chara_t *, ennem_t *);
void	speone_vole(win_t *, btle_t *, chara_t *, ennem_t *);
void	spetwo_pala(win_t *, btle_t *, chara_t *, ennem_t *);
void	spetwo_mage(win_t *, btle_t *, chara_t *, ennem_t *);
void	spetwo_mene(win_t *, btle_t *, chara_t *, ennem_t *);
void	spetwo_vole(win_t *, btle_t *, chara_t *, ennem_t *);
void	spetwo_arch(win_t *, btle_t *, chara_t *, ennem_t *);
void	cast_pone(win_t *, btle_t *, chara_t *, ennem_t *);
void	cast_ptwo(win_t *, btle_t *, chara_t *, ennem_t *);
void	update_spell(win_t *, chara_t *, int, int);
void	update_spell2(win_t *, chara_t *, int, int);
void	clock_ponearc(chara_t *, int *, int *);
void	isdead_perso(win_t *, btle_t *, chara_t *);
void	dead_ennem(win_t *, btle_t *, ennem_t *, int);
void	my_item_to_list(obj_t **, char *, char *, int);

void	delete_boss(pnj_t *);
void	change_gandoulf_dialog(pnj_t *);
void	special_event(win_t *, player_t *, pnj_t *);
ennem_t	*init_boss(ennem_t *);

#endif /* !RPG_H_ */
