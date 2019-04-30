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

void set_volume(rpg_t *rpg, int high, settings_t *settings)
{
    if (high == 1 && settings->volume < 100) {
        settings->volume++;
        sfText_setString(settings->text[1].text,
my_int_to_char(settings->volume));
    }
    if (high == 2 && settings->volume > 0) {
        settings->volume--;
        sfText_setString(settings->text[1].text,
my_int_to_char(settings->volume));
    }
    sfMusic_setVolume(GAME.back_music, settings->volume);
}

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
    rpg->music.aled = create_sound("assets/aled.ogg");
    rpg->music.hurt = create_sound("assets/hurt.ogg");
}