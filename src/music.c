/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** music
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include "rpg.h"

void set_music(rpg_t *rpg)
{
    sfSoundStatus status = sfMusic_getStatus(GAME.back_music);

    if (status == sfStopped)
        sfMusic_play(GAME.back_music);
    else if (status == sfPaused)
        sfMusic_play(GAME.back_music);
    else
        sfMusic_pause(GAME.back_music);
}

void create_music(rpg_t *rpg)
{
    GAME.back_music = sfMusic_createFromFile("assets/back_music.ogg");
    sfMusic_setLoop(GAME.back_music, sfTrue);
    set_music(rpg);
}