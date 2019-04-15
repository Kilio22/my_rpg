/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** destroy_menu
*/

#include "rpg.h"

void destroy_load(load_game_t *load)
{
    for (int i = 0; i < 3; i++) {
        sfFont_destroy((sfFont *)sfText_getFont(load->text[i].text));
        sfText_destroy(load->text[i].text);
    }
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(load->back));
    sfSprite_destroy(load->back);
    sfRectangleShape_destroy(load->rect);
}