/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** intro_create
*/

#include "rpg.h"

void free_objs(obj_t **obj)
{
    for (int i = 0; i < 11; i++) {
        if (obj[i] != NULL) {
            sfImage_destroy(obj[i]->image);
            sfSprite_destroy(obj[i]->sprite);
            sfTexture_destroy(obj[i]->texture);
            sfClock_destroy(obj[i]->clock);
            free(obj[i]);
        }
    }
}

/*int create_intro(obj_t **obj, rpg_t *rpg, house_t **house)
{
    free_objs(obj);
    sfVector2f *vect[] = {
        {10280, 2800},
        {10280, 2800},

    }

    obj[0] = create_object("assets/hero_hitbox.png", (sfVector2f){10280, 2800}, (sfIntRect){0, 0, 32, 16}, sfTrue);
    if (obj[0] == NULL)
        return (84);
    obj[1] = create_object("assets/hero.png", (sfVector2f){10280, 2800}, (sfIntRect){0, 0, 32, 64}, sfFalse);
    if (obj[1] == NULL)
        return (84);
    obj[5] = create_object("assets/perso_blanc.png", (sfVector2f){10194, 1676}, (sfIntRect){0, 0, 32, 64}, sfTrue);
    if (obj[5] == NULL)
        return (84);
    obj[6] = create_object("assets/perso_blanc.png", (sfVector2f){10228, 1696}, (sfIntRect){0, 0, 32, 64}, sfTrue);
    if (obj[6] == NULL)
        return (84);
    obj[7] = create_object("assets/perso_blanc.png", (sfVector2f){10162, 1696}, (sfIntRect){0, 0, 32, 64}, sfTrue);
    if (obj[7] == NULL)
        return (84);
    obj[8] = create_object("assets/stupid_nathan.png", (sfVector2f){11128, 1076}, (sfIntRect){0, 0, 32, 64}, sfTrue);
    if (obj[8] == NULL)
        return (84);
    sfSprite_setOrigin(obj[1]->sprite, (sfVector2f){16, 60});
    return (intro_game(rpg, obj, house));
}*/