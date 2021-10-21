/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** bonus map editor
*/

#ifndef PROTO_H_
#define PROTO_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>

typedef struct	map_s
{
	int	x;
	int	y;
	int	wall;
	int	spawn;
	char	*texture_name;
	sfTexture	*texture;
	struct map_s	*next;
}	map_s;

typedef struct	fb_d
{
	unsigned int	height;
	unsigned int	width;
	unsigned char	*pixel;
}	fb_d;

typedef struct	variables
{
	sfRenderWindow	*window;
	char	*select;
	char	*buf;
	char	*cur;
	int	x_bg;
	int	y_bg;
	int	x_mouse;
	int	y_mouse;
}	variables;

int	my_strlen(char *);
char	*get_next_line(int);
sfVector2u	create_vector(int, int);
sfVector2f	create_vector2f(int, int);
fb_d	*malloc_frame_buffer(unsigned int, unsigned int);
void	my_put_pixel(fb_d *, unsigned int, unsigned int, sfColor);
void	destroy_map(map_s **);
void	draw_square(int, fb_d *, sfVector2u);
char	*concat_strings(char *, char *);
int	same_strings(char *, char *);
void	background_stuff(sfRenderWindow *, int *, int *);
int	texture_exist(char *);
void	add_texture(map_s **, char *, int, int);
void	print_buf(sfRenderWindow *, char *);
void	delete_from_map(map_s **, int, int);
void	set_spawn(map_s **, int, int);
void	events(variables *, map_s **);
void	load(map_s **, char *);
void	save(map_s **, char *);
int	is_command(char *, map_s **);
variables	init_var();

#endif	/* !PROTO_H_ */
