/*
** EPITECH PROJECT, 2018
** draw_square
** File description:
** draw a pixelated square on the screen
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "proto.h"

void	draw_square1(int x, int y, fb_d *fb, sfVector2u vec)
{
	if (x == 0 || y == 0)
		my_put_pixel(fb, vec.x + x, vec.y + y, sfBlack);
}

void	draw_square2(int x, int y, fb_d *fb, sfVector2u vec)
{
	if (x == 20 || y == 20)
		my_put_pixel(fb, vec.x + x, vec.y + y, sfBlack);
}

void	draw_square(int size, fb_d *fb, sfVector2u vec)
{
	int	y = -1;
	int	x = -1;

	while (y++ < size) {
		x = -1;
		while (x++ < size) {
			draw_square1(x, y, fb, vec);
			draw_square2(x, y, fb, vec);
		}
	}
}
