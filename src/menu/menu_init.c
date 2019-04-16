/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu_init
*/

#include "rpg.h"

static void destroy_menu(rpg_t *rpg)
{
    for (int i = 0; i < 2; i++) {
        sfTexture_destroy(
(sfTexture *)sfSprite_getTexture(MENU.menu_sprite[i]));
        sfSprite_destroy(MENU.menu_sprite[i]);
    }
    for (int i = 0; i < 6; i++) {
        sfFont_destroy((sfFont *)sfText_getFont(MENU.buttons[i].text));
        sfText_destroy(MENU.buttons[i].text);
    }
    sfFont_destroy((sfFont *)sfText_getFont(MENU.descr_text));
    sfText_destroy(MENU.descr_text);
    sfRectangleShape_destroy(MENU.rect);
    sfClock_destroy(MENU.clock);
}

static void create_rect_menu(rpg_t *rpg)
{
    sfVector2f pos_rect = {90, 60};

    MENU.rect = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(MENU.rect, 6);
    sfRectangleShape_setSize(MENU.rect, (sfVector2f){450, 100});
    sfRectangleShape_setFillColor(MENU.rect, sfTransparent);
    sfRectangleShape_setOutlineColor(MENU.rect, sfRed);
    sfRectangleShape_setPosition(MENU.rect, pos_rect);
}

static void create_ground(rpg_t *rpg)
{
    sfTexture *texture;

    for (int i = 0; i < 2; i++) {
        texture = sfTexture_createFromFile(menu_path[i], NULL);
        MENU.menu_sprite[i] = sfSprite_create();
        sfSprite_setTexture(MENU.menu_sprite[i], texture, sfTrue);
    }
    for (int i = 0; i < 6; i++) {
        MENU.buttons[i].text = create_text((const char *)MENU_FONT,
menu_str[i], 80, menu_pos[i]);
        MENU.buttons[i].status = 0;
    }
    sfText_setColor(MENU.buttons[0].text, sfYellow);
    MENU.highlight = 0;
}

void init_menu(rpg_t *rpg, obj_t **obj, house_t **house)
{
    create_ground(rpg);
    create_rect_menu(rpg);
    MENU.clock = sfClock_create();
    rpg->menu.menu_on = 1;
    MENU.descr_text = create_text(MENU_FONT, menu_desc[0], 30,
(sfVector2f){580, 570});
    if (init_save(obj, rpg) == -1) {
        rpg->error_code = 84;
        return;
    }
    menu_loop(rpg, obj, house);
    destroy_menu(rpg);
}
