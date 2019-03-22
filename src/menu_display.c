/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu
*/

#include "rpg.h"

sfText *create_text(char *font_fp, char *str, unsigned int size, sfVector2f pos)
{
    sfText *new_text = sfText_create();
    sfFont *font = sfFont_createFromFile(font_fp);

    sfText_setFont(new_text, font);
    sfText_setCharacterSize(new_text, size);
    sfText_setPosition(new_text, pos);
    sfText_setColor(new_text, sfRed);
    sfText_setString(new_text, str);
    sfFont_destroy(font);
    return (new_text);
}

static void display_menu(rpg_t *rpg, obj_t **obj)
{
    sfText *text = sfText_create();
    sfText *text2 = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/arial.ttf");

    sfText_setFont(text, font);
    sfText_setFont(text2, font);
    sfText_setCharacterSize(text, (unsigned int){50});
    sfText_setCharacterSize(text2, (unsigned int){50});
    sfText_setPosition(text, V2F(80, 200));
    sfText_setPosition(text2, V2F(80, 400));
    sfText_setColor(text, sfRed);
    sfText_setColor(text2, sfRed);
    sfText_setString(text, "F1 SAVE 1, F2 SAVE 2");
    sfText_setString(text2, "F3 START GAME");
    sfView_setCenter(WIND.view, V2F(320, 320));
    sfRenderWindow_setView(WIND.wind, WIND.view);
    sfRenderWindow_drawSprite(WIND.wind, obj[0]->sprite, NULL);
    sfRenderWindow_drawText(WIND.wind, text, NULL);
    sfRenderWindow_drawText(WIND.wind, text2, NULL);
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

void init_menu_loop(rpg_t *rpg, obj_t **obj, house_t **house)
{
    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            menu_event_management(rpg, obj, house);
        display_menu(rpg, obj);
    }
}