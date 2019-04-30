/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** follower
*/

#include "rpg.h"

static void manage_follower2(obj_t **obj, rpg_t *rpg, sfVector2f pos,
sfVector2f oldpos)
{
    sfVector2f newPos = oldpos;
    int mul_x = 1;
    int mul_y = 1;

    if (pos.x < oldpos.x)
        mul_x = -1;
    if (pos.y < oldpos.y)
        mul_y = -1;
    for (size_t i = 0; i < rpg->frame; i++) {
        newPos.x = (newPos.x == pos.x) ? newPos.x + (2 * mul_x) : newPos.x;
        newPos.y = (newPos.y == pos.y) ? newPos.y + (2 * mul_y) : newPos.y;
        sfSprite_setPosition(obj[3]->sprite,
*(sfVector2f *)GAME.follower2->start->content);
        modif_list(GAME.follower2, newPos);
    }
}

static void manage_follower(obj_t **obj, rpg_t *rpg, sfVector2f pos,
sfVector2f oldpos)
{
    sfVector2f oldPos1 = sfSprite_getPosition(obj[2]->sprite);
    sfVector2f newPos = oldpos;
    int mul_x = 1;
    int mul_y = 1;

    if (pos.x < oldpos.x)
        mul_x = -1;
    if (pos.y < oldpos.y)
        mul_y = -1;
    for (size_t i = 0; i < rpg->frame; i++) {
        newPos.x = (newPos.x == pos.x) ? newPos.x + (2 * mul_x) : newPos.x;
        newPos.y = (newPos.y == pos.y) ? newPos.y + (2 * mul_y) : newPos.y;
        sfSprite_setPosition(obj[2]->sprite,
*(sfVector2f *)GAME.follower->start->content);
        modif_list(GAME.follower, newPos);
    }
    manage_follower2(obj, rpg, sfSprite_getPosition(obj[2]->sprite), oldPos1);
}

void follower(obj_t **obj, rpg_t *rpg)
{
    static sfVector2f oldpos = {0, 0};
    sfVector2f pos = sfSprite_getPosition(obj[0]->sprite);

    if (pos.x > oldpos.x || pos.x < oldpos.x || pos.y > oldpos.y ||
pos.y < oldpos.y) {
        if (obj[2] != NULL && obj[3] != NULL)
            manage_follower(obj, rpg, pos, oldpos);
    }
    oldpos = sfSprite_getPosition(obj[0]->sprite);
}