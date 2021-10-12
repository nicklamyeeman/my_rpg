/*
** EPITECH PROJECT, 2017
** common_functions
** File description:
** Function to malloc frame_buffer and put pixels
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "proto.h"

void	my_put_pixel(fb_d *f_b, unsigned int x, unsigned int y, sfColor c)
{
	unsigned int	total;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1080) {
		total = (x + y * f_b->width) * 4;
		f_b->pixel[total + 0] = c.r;
		f_b->pixel[total + 1] = c.g;
		f_b->pixel[total + 2] = c.b;
		f_b->pixel[total + 3] = c.a;
	}
}

fb_d	*malloc_frame_buffer(fb_d *fb, unsigned int h, unsigned int w)
{
	fb = malloc(sizeof(*fb));
	fb->height = h;
	fb->width = w;
	fb->pixel = malloc(sizeof(char) * h * w * 4);
	return (fb);
}
