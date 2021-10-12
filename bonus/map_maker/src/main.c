/*
** EPITECH PROJECT, 2018
** main
** File description:
** Loop of the map maker
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "proto.h"

void	draw_array(sfRenderWindow *w, fb_d *fb)
{
	sfTexture	*t = sfTexture_create(1920, 1080);
	sfSprite	*s = sfSprite_create();
	int	x = 0;
	int	y = 0;

	while (y < 1080) {
		while (x < 1920) {
			draw_square(20, fb, create_vector(x, y), sfBlack);
			x += 20;
		}
		x = 0;
		y += 20;
	}
	sfTexture_updateFromPixels(t, fb->pixel, fb->width, fb->height, 0, 0);
	sfSprite_setTexture(s, t, sfTrue);
	sfRenderWindow_drawSprite(w, s, NULL);
	sfTexture_destroy(t);
	sfSprite_destroy(s);
}

void	display_textures(sfRenderWindow *w, map_s **map)
{
	map_s	*t = *map;
	char	*mobtxt = "./texture/mob.png";
	sfSprite	*s = sfSprite_create();
	sfTexture	*mob = sfTexture_createFromFile(mobtxt, NULL);

	while (t != NULL) {
		sfSprite_setTexture(s, t->texture, sfTrue);
		sfSprite_setPosition(s, create_vector2f(t->x * 20, t->y * 20));
		sfRenderWindow_drawSprite(w, s, NULL);
		if (t->spawn == 1) {
			sfSprite_setTexture(s, mob, sfTrue);
			sfRenderWindow_drawSprite(w, s, NULL);
		}
		t = t->next;
	}
	sfSprite_destroy(s);
	sfTexture_destroy(mob);
	t = NULL;
}

void	check_select(variables *v, map_s **map)
{
	if (is_command(v->select, map))
		v->cur = NULL;
	else if (texture_exist(v->select) == 1) {
		v->cur = concat_strings("./texture/", v->select);
		v->select = NULL;
	}
}

void	loop(variables v, map_s **map)
{
	fb_d	*fb = malloc_frame_buffer(fb, 1080, 1920);

	while (sfRenderWindow_isOpen(v.window)) {
		sfRenderWindow_clear(v.window, sfBlack);
		background_stuff(v.window, &v.x_bg, &v.y_bg);
		draw_array(v.window, fb);
		if (*map != NULL)
			display_textures(v.window, map);
		print_buf(v.window, v.buf);
		events(&v, map);
		if (v.select != NULL) {
			check_select(&v, map);
		}
		sfRenderWindow_display(v.window);
	}
}

int	main(int ac, char **av)
{
	variables	var = init_var(var);
	map_s	*map = NULL;

	loop(var, &map);
	sfRenderWindow_destroy(var.window);
	while (map != NULL) {
		sfTexture_destroy(map->texture);
		map = map->next;
	}
	return (0);
}
