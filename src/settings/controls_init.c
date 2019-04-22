/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_controls
*/

#include "rpg.h"

int check_mousepos_intersect(rpg_t *rpg, fields_t field[], int nb)
{
    sfFloatRect text_pos;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(WIND.wind);
    sfFloatRect mouse_pos = {mouse.x, mouse.y, 1, 1};

    WIND.mouse_pos.x = mouse.x;
    WIND.mouse_pos.y = mouse.y;
    for (int i = 0; i < nb; i++) {
        text_pos = sfText_getGlobalBounds(field[i].text);
        if (sfFloatRect_intersects(&text_pos, &mouse_pos, NULL))
            return i;
    }
    return -1;
}

static void display_controls(rpg_t *rpg, int *high)
{
    int ret_val = 0;

    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            ret_val += manage_control_events(rpg, high);
        if (ret_val == 1)
            return;
        sfRenderWindow_drawSprite(WIND.wind, CONTROLS.back, NULL);
        for (int i = 0; i < NB_KEYS; i++)
            sfRenderWindow_drawText(WIND.wind, CONTROLS.text[i].text, NULL);
        sfRenderWindow_display(WIND.wind);
        sfRenderWindow_clear(WIND.wind, sfBlack);
    }
}

void init_controls_menu(rpg_t *rpg)
{
    int x = 100;
    int y = 100;
    sfTexture *texture = sfTexture_createFromFile(BACK_CTRL, NULL);
    int highlight = 0;

    for (int i = 0; i < NB_KEYS; i++) {
        CONTROLS.text[i].text = create_text("assets/arial.ttf",
key_str[CONTROLS.keys[i]], 30, (sfVector2f){x, y});
        CONTROLS.text[i].status = 0;
        y += 40;
    }
    CONTROLS.back = sfSprite_create();
    sfSprite_setTexture(CONTROLS.back, texture, sfTrue);
    CONTROLS.wait_key = -1;
    display_controls(rpg, &highlight);
    for (int i = 0; i < NB_KEYS; i++) {
        sfFont_destroy((sfFont *)sfText_getFont(CONTROLS.text[i].text));
        sfText_destroy(CONTROLS.text[i].text);
    }
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(CONTROLS.back));
    sfSprite_destroy(CONTROLS.back);
}