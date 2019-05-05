/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** music
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "rpg.h"

void set_sound_volume(rpg_t *rpg)
{
    float volume = sfMusic_getVolume(GAME.back_music);

    sfSound_setVolume(rpg->music.aled, volume);
    sfSound_setVolume(rpg->music.hurt, volume);
    sfMusic_setVolume(rpg->music.fight_music, volume);
}

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

void set_music(sfMusic *music)
{
    sfSoundStatus status = sfMusic_getStatus(music);

    if (status == sfStopped)
        sfMusic_play(music);
    else if (status == sfPaused)
        sfMusic_play(music);
    else
        sfMusic_pause(music);
}

void create_music(rpg_t *rpg)
{
    GAME.back_music = sfMusic_createFromFile("assets/back_music.ogg");
    rpg->music.fight_music = sfMusic_createFromFile("assets/fight.ogg");
    sfMusic_setLoop(GAME.back_music, sfTrue);
    sfMusic_setLoop(rpg->music.fight_music, sfTrue);
    set_music(GAME.back_music);
    rpg->music.aled = create_sound("assets/aled.ogg");
    rpg->music.hurt = create_sound("assets/hurt.ogg");
}