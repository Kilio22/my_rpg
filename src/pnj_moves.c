/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** pnj_moves
*/

#include "rpg.h"

static sfBool all_world_hitBox_pnj(obj_t **obj, house_t **house,
obj_t *obj_solo)
{
    sfVector2f old_pos = sfRectangleShape_getPosition(obj_solo->rectangle);
    sfFloatRect rect;

    sfRectangleShape_setPosition(obj_solo->rectangle,
sfSprite_getPosition(obj_solo->sprite));
    rect = sfRectangleShape_getGlobalBounds(obj_solo->rectangle);
    if (pp_intersect(obj_solo->sprite, obj[4]->sprite,
obj_solo->image, obj[4]->image) == 1)
        return 1;
    for (int i = 0; house[i] != NULL; i++)
        if (pp_intersect(obj_solo->sprite, house[i]->tab[HITBOX],
obj_solo->image, house[i]->image) == 1)
            return 1;
    if (sfFloatRect_intersects(&obj[0]->rectangle_bound,
&rect, NULL) == sfTrue) {
        sfRectangleShape_setPosition(obj_solo->rectangle, old_pos);
        return 1;
    }
    return 0;
}

static void reset_move(obj_t **obj, int (*rand_tab)[3], int *nb_moves)
{
    int random = 0;

    for (int i = 6; i < 9; i++)
        if (obj[i]) {
            random = rand() % 4;
            (*rand_tab)[i - 6] = random;
        }
    *nb_moves = 0;
}

static void choose_pos(float *x, float *y, int (*rand)[3], int i)
{
    *x += ((*rand)[i - 6] == 0 ? 2 : 0);
    *x += ((*rand)[i - 6] == 1 ? -2 : 0);
    *y += ((*rand)[i - 6] == 2 ? 2 : 0);
    *y += ((*rand)[i - 6] == 3 ? -2 : 0);
}

static void moving_pnjs(obj_t **obj, house_t **house, int (*rand)[3])
{
    sfVector2f vect = {0, 0};

    for (int i = 6; i < 9; i++) {
        vect = V2F(0, 0);
        if (obj[i] == NULL)
            continue;
        choose_pos(&vect.x, &vect.y, rand, i);
        obj[i]->oldPos = sfSprite_getPosition(obj[i]->sprite);
        sfSprite_move(obj[i]->sprite, vect);
        if (all_world_hitBox_pnj(obj, house, obj[i]) == 1) {
            vect.x *= -1;
            vect.y *= -1;
            sfSprite_move(obj[i]->sprite, vect);
            continue;
        }
        obj[i]->pos = sfSprite_getPosition(obj[i]->sprite);
        sfRectangleShape_setPosition(OBJ_RECT, obj[i]->pos);
        obj[i]->rectangle_bound = sfRectangleShape_getGlobalBounds(OBJ_RECT);
    }
}

void move_pnjs(obj_t **obj, house_t **house)
{
    static int nb_moves = -1;
    static int oui[3] = {0, 0, 0};

    if (nb_moves >= 0) {
        moving_pnjs(obj, house, &oui);
        nb_moves++;
        if (nb_moves == 20)
            nb_moves = -1;
        return;
    }
    if (check_pnj_clock_move() == 0)
        return;
    reset_move(obj, &oui, &nb_moves);
}