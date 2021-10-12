/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init combi
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include "rpg.h"

ennem_t	*init_bigxptxt(ennem_t *ennem)
{
	sfSprite_setPosition(ennem[0].ennes, v2f(500, 210));
	sfSprite_setPosition(ennem[1].ennes, v2f(140, 280));
	sfSprite_setPosition(ennem[2].ennes, v2f(300, 490));
	sfSprite_setPosition(ennem[0].arros, v2f(580, 230));
	sfSprite_setPosition(ennem[1].arros, v2f(170, 230));
	sfSprite_setPosition(ennem[2].arros, v2f(400, 470));
	return (ennem);
}

ennem_t	*init_easytxt(ennem_t *ennem)
{
	sfSprite_setPosition(ennem[0].ennes, v2f(500, 210));
	sfSprite_setPosition(ennem[0].arros, v2f(580, 230));
	sfText_setString(ennem[1].entex, "GOBELIN  A");
	sfSprite_setPosition(ennem[1].ennes, v2f(140, 370));
	sfSprite_setPosition(ennem[1].arros, v2f(240, 350));
	sfText_setString(ennem[2].entex, "GOBELIN  B");
	sfSprite_setPosition(ennem[2].ennes, v2f(300, 490));
	sfSprite_setPosition(ennem[2].arros, v2f(400, 470));
	return (ennem);
}

ennem_t	*init_hordetxt(ennem_t *ennem)
{
	sfText_setString(ennem[0].entex, "GOBELIN  A");
	sfSprite_setPosition(ennem[0].ennes, v2f(80, 380));
	sfSprite_setPosition(ennem[0].arros, v2f(180, 360));
	sfText_setString(ennem[1].entex, "GOBELIN  B");
	sfSprite_setPosition(ennem[1].ennes, v2f(290, 310));
	sfSprite_setPosition(ennem[1].arros, v2f(390, 290));
	sfText_setString(ennem[2].entex, "GOBELIN  C");
	sfSprite_setPosition(ennem[2].ennes, v2f(610, 490));
	sfSprite_setPosition(ennem[2].arros, v2f(710, 470));
	sfText_setString(ennem[3].entex, "GOBELIN  D");
	sfSprite_setPosition(ennem[3].ennes, v2f(230, 480));
	sfSprite_setPosition(ennem[3].arros, v2f(330, 460));
	sfText_setString(ennem[4].entex, "GOBELIN  E");
	sfSprite_setPosition(ennem[4].ennes, v2f(540, 320));
	sfSprite_setPosition(ennem[4].arros, v2f(640, 300));
	sfText_setString(ennem[5].entex, "GOBELIN  F");
	sfSprite_setPosition(ennem[5].ennes, v2f(410, 420));
	sfSprite_setPosition(ennem[5].arros, v2f(510, 400));
	return (ennem);
}

ennem_t	*init_hardtxt(ennem_t *ennem)
{
	sfText_setString(ennem[0].entex, "TROLL  A");
	sfSprite_setPosition(ennem[0].ennes, v2f(100, 210));
	sfSprite_setPosition(ennem[0].arros, v2f(180, 230));
	sfText_setString(ennem[1].entex, "TROLL  B");
	sfSprite_setPosition(ennem[1].ennes, v2f(360, 140));
	sfSprite_setPosition(ennem[1].arros, v2f(440, 160));
	sfText_setString(ennem[2].entex, "TROLL  C");
	sfSprite_setPosition(ennem[2].ennes, v2f(620, 190));
	sfSprite_setPosition(ennem[2].arros, v2f(700, 190));
	sfText_setString(ennem[3].entex, "GOBELIN  A");
	sfSprite_setPosition(ennem[3].ennes, v2f(260, 500));
	sfSprite_setPosition(ennem[3].arros, v2f(360, 480));
	sfText_setString(ennem[4].entex, "GOBELIN  B");
	sfSprite_setPosition(ennem[4].ennes, v2f(500, 490));
	sfSprite_setPosition(ennem[4].arros, v2f(600, 470));
	return (ennem);
}

ennem_t	*init_trolztxt(ennem_t *ennem)
{
	sfSprite_setPosition(ennem[0].ennes, v2f(40, 290));
	sfSprite_setPosition(ennem[0].arros, v2f(80, 250));
	sfText_setString(ennem[1].entex, "BIDOOF  A");
	sfSprite_setPosition(ennem[1].ennes, v2f(290, 370));
	sfSprite_setPosition(ennem[1].arros, v2f(290, 330));
	sfText_setString(ennem[2].entex, "BIDOOF  B");
	sfSprite_setPosition(ennem[2].ennes, v2f(590, 550));
	sfSprite_setPosition(ennem[2].arros, v2f(590, 510));
	sfText_setString(ennem[3].entex, "BIDOOF  C");
	sfSprite_setPosition(ennem[3].ennes, v2f(230, 540));
	sfSprite_setPosition(ennem[3].arros, v2f(230, 500));
	sfText_setString(ennem[4].entex, "BIDOOF  D");
	sfSprite_setPosition(ennem[4].ennes, v2f(540, 380));
	sfSprite_setPosition(ennem[4].arros, v2f(540, 340));
	sfText_setString(ennem[5].entex, "BIDOOF  E");
	sfSprite_setPosition(ennem[5].ennes, v2f(410, 480));
	sfSprite_setPosition(ennem[5].arros, v2f(410, 440));
	return (ennem);
}