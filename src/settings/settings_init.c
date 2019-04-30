/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_settings
*/

#include "rpg.h"

static void reinit_menu_texts(rpg_t *rpg)
{
    for (int i = 0; i < 6; i++) {
        MENU.buttons[i].text = create_text((const char *)menu_font,
menu_str[GAME.language][i], 60, menu_pos[i]);
        MENU.buttons[i].status = 0;
    }
    if (GAME.language == 0)
        sfRectangleShape_setSize(MENU.rect, V2F(460, 100));
    else
        sfRectangleShape_setSize(MENU.rect, V2F(355, 100));
}

void destroy_settings(settings_t *settings, rpg_t *rpg)
{
    for (int i = 0; i < 4; i++) {
        sfFont_destroy((sfFont *)sfText_getFont(settings->text[i].text));
        sfText_destroy(settings->text[i].text);
    }
    for (int i = 0; i < 5; i++) {
        sfTexture_destroy(
(sfTexture *)sfSprite_getTexture(settings->buttons[i].sprite));
        sfSprite_destroy(settings->buttons[i].sprite);
    }
    sfRectangleShape_destroy(settings->rect);
    for (int i = 0; i < 6; i++) {
        sfFont_destroy((sfFont *)sfText_getFont(MENU.buttons[i].text));
        sfText_destroy(MENU.buttons[i].text);
    }
    reinit_menu_texts(rpg);
}

static sfRectangleShape *create_rect_setting(rpg_t *rpg)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setOutlineThickness(rect, 6);
    sfRectangleShape_setSize(rect, (sfVector2f){130, 87});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfBlue);
    if (GAME.language == 0)
        sfRectangleShape_setPosition(rect, settings_spr_pos[3]);
    else
        sfRectangleShape_setPosition(rect, settings_spr_pos[4]);
    return (rect);
}

static void init_texts_settings(settings_t *settings, rpg_t *rpg)
{
    for (int i = 0; i < 4; i++) {
        if (i == 1)
            settings->text[i].text =
create_text(menu_font, my_int_to_char(settings->volume), 80, settings_pos[i]);
        else
            settings->text[i].text =
create_text(menu_font, SETT[GAME.language][i], 80, settings_pos[i]);
    }
}

settings_t init_settings(rpg_t *rpg)
{
    settings_t settings;
    sfTexture *texture;

    settings.volume = sfMusic_getVolume(GAME.back_music);
    settings.rect = create_rect_setting(rpg);
    for (int i = 0; i < 5; i++) {
        texture = sfTexture_createFromFile(settings_fp[i], NULL);
        settings.buttons[i].sprite = sfSprite_create();
        sfSprite_setTexture(settings.buttons[i].sprite, texture, sfTrue);
        sfSprite_setPosition(settings.buttons[i].sprite, settings_spr_pos[i]);
        settings.buttons[i].state = 0;
    }
    sfSprite_setScale(settings.buttons[0].sprite, V2F(0.7, 0.7));
    init_texts_settings(&settings, rpg);
    settings.high = 0;
    return (settings);
}
