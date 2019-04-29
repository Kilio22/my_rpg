/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** settings_menu
*/

#include "rpg.h"

int check_mousepos_butt_set(rpg_t *rpg, settings_t *settings)
{
    sfFloatRect text_pos;
    sfFloatRect mouse_pos = {WIND.mouse_pos.x, WIND.mouse_pos.y, 1, 1};

    for (int i = 1; i < 5; i++) {
        text_pos = sfSprite_getGlobalBounds(settings->buttons[i].sprite);
        if (sfFloatRect_intersects(&text_pos, &mouse_pos, NULL))
            return i;
    }
    text_pos = sfText_getGlobalBounds(settings->text[3].text);
    if (sfFloatRect_intersects(&text_pos, &mouse_pos, NULL))
        return (9);
    return 0;
}

static void manage_other_settings_events(rpg_t *rpg, settings_t *settings)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (settings->high < 3 && settings->high > 0) {
            sfSprite_setColor(settings->buttons[settings->high].sprite, sfBlue);
            settings->buttons[settings->high].state = 1;
            set_volume(rpg, settings->high, settings);
        }
    }
}

static void display_settings(rpg_t *rpg, settings_t *settings)
{
    for (int i = 0; i < 5; i++)
        sfRenderWindow_drawSprite(WIND.wind,
settings->buttons[i].sprite, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(WIND.wind, settings->text[i].text, NULL);
    sfRenderWindow_drawRectangleShape(WIND.wind, settings->rect, NULL);
        sfRenderWindow_display(WIND.wind);
        sfRenderWindow_clear(WIND.wind, sfBlack);
}

void menu_settings(rpg_t *rpg, obj_t **obj, house_t **house)
{
    settings_t settings = init_settings(rpg);
    sfEvent event;
    int ret_val = 0;
    size_t frames;

    (void) obj;
    (void) house;
    while (sfRenderWindow_isOpen(WIND.wind)) {
        rpg->frame = update_time(&frames);
        while (sfRenderWindow_pollEvent(WIND.wind, &event))
            ret_val += manage_settings_events(rpg, event, &settings);
        manage_other_settings_events(rpg, &settings);
        if (ret_val == 1)
            return;
        display_settings(rpg, &settings);
    }
    destroy_settings(&settings);
}