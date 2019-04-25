/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** delete_fight
*/

#include "rpg.h"

void reinit_pos(obj_t **obj, fight_t *fight)
{
    sfSprite_setPosition(obj[HERO_HB]->sprite, fight->old_pos[0]);
    sfSprite_setPosition(obj[2]->sprite, fight->old_pos[1]);
    sfSprite_setPosition(obj[3]->sprite, fight->old_pos[2]);
    sfSprite_setPosition(obj[fight->nb_fight + 6]->sprite, fight->old_pos[3]);
    obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
    obj[2]->pos = sfSprite_getPosition(obj[2]->sprite);
    obj[3]->pos = sfSprite_getPosition(obj[3]->sprite);
    obj[fight->nb_fight + 6]->pos =
sfSprite_getPosition(obj[fight->nb_fight + 6]->sprite);
    sfSprite_setPosition(obj[1]->sprite,
sfSprite_getPosition(obj[HERO_HB]->sprite));

}

void delete_fight(fight_t *fight, obj_t **obj, rpg_t *rpg)
{
    sfRectangleShape_destroy(fight->fondu);
    sfFont_destroy((sfFont *)sfText_getFont(fight->text));
    sfText_destroy(fight->text);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(fight->parch));
    sfSprite_destroy(fight->parch);
    update_fondu_rect_fight(fight, rpg, 1);
    update_fight_text(1, fight, 1);
    reinit_pos(obj, fight);
    for (int i = 0; i < 5; i++) {
        sfFont_destroy((sfFont *)sfText_getFont(fight->attacks[i]));
        sfText_destroy(fight->attacks[i]);
    }
}