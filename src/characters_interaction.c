/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** characters_interaction
*/

#include "rpg.h"

static void do_interact(obj_t **obj, rpg_t *rpg, int i, house_t **house)
{
    if (i >= 6 && i <= 9) {
        fight(obj, rpg, i - 6, house);
        for (int i = 0; i < 10; i++)
            CONTROLS.bools[i] = 0;
    }
}

static int check_interact(obj_t **obj, rpg_t *rpg, int i, house_t **house)
{
    sfFloatRect oui = sfRectangleShape_getGlobalBounds(OBJ_RECT);

    if (CONTROLS.bools[KEYINTER] == 0)
        return 0;
    oui.height += 2;
    oui.width += 2;
    oui.top--;
    oui.left--;
    if (sfFloatRect_intersects(&obj[0]->rectangle_bound,
&oui, NULL) == sfTrue) {
        do_interact(obj, rpg, i, house);
        return 1;
    }
    return 0;
}

int character_hitbox(obj_t **obj, rpg_t *rpg, house_t **house)
{
    int i;

    obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
    sfRectangleShape_setPosition(obj[0]->rectangle, obj[0]->pos);
    obj[0]->rectangle_bound =
sfRectangleShape_getGlobalBounds(obj[0]->rectangle);
    for (i = 5; i < 9; i++) {
        if (obj[i] == NULL)
            continue;
        obj[i]->rectangle_bound =
sfRectangleShape_getGlobalBounds(OBJ_RECT);
        if (sfFloatRect_intersects(&obj[0]->rectangle_bound,
&obj[i]->rectangle_bound, NULL) == sfTrue)
            return 1;
        if (check_interact(obj, rpg, i, house) == 1)
            return 1;
    }
    return 0;
}