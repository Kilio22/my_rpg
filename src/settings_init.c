/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_settings
*/

#include "rpg.h"

sfRectangleShape *create_rect(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setOutlineThickness(rect, 6);
    sfRectangleShape_setSize(rect, (sfVector2f){130, 87});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfBlue);
    sfRectangleShape_setPosition(rect, settings_spr_pos[3]);
    return (rect);
}

settings_t init_settings(rpg_t *rpg)
{
    settings_t settings;
    sfTexture *texture;

    settings.volume = sfMusic_getVolume(GAME.back_music);
    settings.rect = create_rect();
    for (int i = 0; i < 5; i++) {
        texture = sfTexture_createFromFile(settings_fp[i], NULL);
        settings.buttons[i].sprite = sfSprite_create();
        sfSprite_setTexture(settings.buttons[i].sprite, texture, sfTrue);
        sfSprite_setPosition(settings.buttons[i].sprite, settings_spr_pos[i]);
        settings.buttons[i].state = 0;
    }
    for (int i = 0; i < 4; i++) {
        if (i == 1)
            settings.text[i].text =
create_text(MENU_FONT, my_int_to_char(settings.volume), 80, settings_pos[i]);
        else
            settings.text[i].text =
create_text(MENU_FONT, settings_str[i], 80, settings_pos[i]);
    }
    settings.high = 0;
    return (settings);
}