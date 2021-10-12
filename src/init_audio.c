/*
** EPITECH PROJECT, 2018
** init_audio
** File description:
** Initialise the audio
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <unistd.h>
#include <fcntl.h>
#include "rpg.h"

audio_s	init_audio(char *path)
{
	audio_s	audio;
	int	fd = open(path, O_RDONLY);

	if (fd == -1) {
		audio.mute = 1;
		return (audio);
	}
	close(fd);
	audio.theme = sfMusic_createFromFile(path);
	sfMusic_setLoop(audio.theme, sfTrue);
	sfMusic_play(audio.theme);
	audio.mute = 0;
	audio.volume = 100;
	return (audio);
}
