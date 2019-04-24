/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro_steps_6
*/

#include "rpg.h"

void reset_char(obj_t **obj, rpg_t *rpg, house_t **house)
{
    sfSprite_setPosition(obj[0]->sprite, V2F(10050, 1570));
    obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
    free_house(house[0]);
    for (int i = 5; i < 11; i++) {
        free_obj(obj[i]);
        obj[i] = NULL;
    }
    house[0] = create_house(2, V2F(9840, 1088));
    game_create(rpg, obj, house);
}

int intro_go_auberge20(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 41) {
        new_pos.y = 1;
        sfSprite_move(obj[0]->sprite, new_pos);
        sfSprite_move(obj[8]->sprite, new_pos);
        sfSprite_move(obj[10]->sprite, new_pos);
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        opt++;
    }
    if (opt == 42 && rpg->quest_status == 24) {
        reset_char(obj, rpg, house);
        opt++;
    }
    if (rpg->quest_status == 25) {
        MENU.menu_on = 2;
        rpg->quest_status++;
    }
    return opt;
}

int intro_go_auberge19(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)house;
    if (opt == 39 && rpg->quest_status == 22) {
        if (obj[10]->pos.x > 10048) {
            new_pos.x = -1;
            sfSprite_move(obj[10]->sprite, new_pos);
        } else
            opt++;
    }
    if (opt == 40) {
        if (obj[10]->pos.y < 1346) {
            new_pos.y = 1;
            sfSprite_move(obj[10]->sprite, new_pos);
        } else {
            opt++;
            rpg->quest_status++;
        }
    }
    return opt;
}