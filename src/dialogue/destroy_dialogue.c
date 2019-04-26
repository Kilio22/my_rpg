/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** destroy_dialogue
*/

#include "rpg.h"

void destroy_dialogue(dialogue_t *dialogue)
{
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(dialogue->parch));
    sfSprite_destroy(dialogue->parch);
    for (int i = 0; i < 4; i++) {
        sfFont_destroy((sfFont *)sfText_getFont(dialogue->text[i]));
        sfText_destroy(dialogue->text[i]);
    }
}