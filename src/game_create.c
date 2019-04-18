/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** game_create
*/

#include "rpg.h"

int game_create_load(obj_t **obj)
{
    free(obj[0]);
    obj[0] = create_object("assets/hero_hitbox.png", (sfVector2f){9410, 1250}, (sfIntRect){0, 0, 32, 16}, sfTrue);
    if (obj[0] == NULL)
        return (84);
    free(obj[1]);
    obj[1] = create_object("assets/hero.png", (sfVector2f){9410, 1250}, (sfIntRect){0, 0, 32, 64}, sfFalse);
    if (obj[1] == NULL)
        return (84);
    sfSprite_setOrigin(obj[1]->sprite, (sfVector2f){16, 60});
    return 1;
}

int game_create(rpg_t *rpg, obj_t **obj, house_t **house)
{
    if (rpg->quest_status == 1) {
        if (game_create_load(obj) == 84)
            return 84;
    }
    if (obj[2] == NULL) {
        obj[2] = create_object("assets/stupid_nathan.png", (sfVector2f){obj[0]->pos.x - 50, obj[0]->pos.y}, (sfIntRect){0, 0, 32, 64}, sfFalse);
        sfSprite_setOrigin(obj[2]->sprite, (sfVector2f){16, 60});
        GAME.follower = init_list(obj[0]->pos.x - 50, obj[0]->pos.y);
    }
    if (obj[3] == NULL) {
        obj[3] = create_object("assets/perso_vert.png", (sfVector2f){obj[0]->pos.x - 100, obj[0]->pos.y}, (sfIntRect){0, 0, 32, 64}, sfFalse);
        sfSprite_setOrigin(obj[3]->sprite, (sfVector2f){16, 60});
        GAME.follower2 = init_list(obj[0]->pos.x - 100, obj[0]->pos.y);
    }
    if (rpg->quest_status == 1)
        game_loop(rpg, obj, house);
    return 1;
}