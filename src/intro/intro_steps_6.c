/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro_steps_6
*/

#include "rpg.h"

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
        //free_obj(5 a 10);
        sfSprite_setPosition(obj[0]->sprite, V2F(9410, 1250));
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        //free_house(0);
        for (int i = 5; i < 11; i++)
            obj[i] = NULL; //a enlever
        house[0] = NULL; //a enlever
        house[0] = create_house(2, V2F(9200, 768));
        obj[2] = create_object("assets/stupid_nathan.png", (sfVector2f){obj[0]->pos.x - 50, obj[0]->pos.y}, (sfIntRect){0, 0, 32, 64}, sfFalse);
        obj[3] = create_object("assets/perso_vert.png", (sfVector2f){obj[0]->pos.x - 100, obj[0]->pos.y}, (sfIntRect){0, 0, 32, 64}, sfFalse);
        sfSprite_setOrigin(obj[2]->sprite, (sfVector2f){16, 60});
        sfSprite_setOrigin(obj[3]->sprite, (sfVector2f){16, 60});
        GAME.follower = init_list(obj[0]->pos.x - 50, obj[0]->pos.y);
        GAME.follower2 = init_list(obj[0]->pos.x - 100, obj[0]->pos.y);
    }
    if (rpg->quest_status == 25)
        MENU.menu_on = 2;
    return opt;
}

int intro_go_auberge19(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 39 && rpg->quest_status == 22) {
        if (obj[10]->pos.x > 9408) {
            new_pos.x = -1;
            sfSprite_move(obj[10]->sprite, new_pos);
        } else
            opt++;
    }
    if (opt == 40) {
        if (obj[10]->pos.y < 1026) {
            new_pos.y = 1;
            sfSprite_move(obj[10]->sprite, new_pos);
        } else {
            opt++;
            rpg->quest_status++;
        }
    }
    return intro_go_auberge20(obj, opt, rpg, house);
}