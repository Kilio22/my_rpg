/*
** EPITECH PROJECT, 2018
** main
** File description:
** description
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

int main(void)
{
    rpg_t rpg;
    obj_t **obj = malloc(sizeof(obj_t *) * 10);
    house_t **house = malloc(sizeof(house_t *) * 2);
    sfVector2u windowSize;

    rpg.wind.wind = create_window("test window", 10);
    windowSize = sfRenderWindow_getSize(rpg.wind.wind);
    rpg.wind.view = sfView_createFromRect((sfFloatRect){0, 0, windowSize.x, windowSize.y});

    obj[0] = create_object("assets/hero_hitbox.png", (sfVector2f){10000, 1280}, (sfIntRect){0, 0, 32, 16}, sfTrue);
    obj[1] = create_object("assets/hero.png", (sfVector2f){10000, 1280}, (sfIntRect){0, 0, 32, 64}, sfFalse);
    obj[2] = create_object("assets/stupid_nathan.png", (sfVector2f){9950, 1280}, (sfIntRect){0, 0, 32, 64}, sfFalse);
    obj[3] = create_object("assets/normal_dummy.png", (sfVector2f){9900, 1280}, (sfIntRect){0, 0, 32, 64}, sfFalse);
    obj[4] = NULL;
    house[0] = create_house(1, (sfVector2f){10100, 1050});
    house[1] = NULL;

    sfSprite_setOrigin(obj[1]->sprite, (sfVector2f){16, 60});
    sfSprite_setOrigin(obj[2]->sprite, (sfVector2f){16, 60});
    sfSprite_setOrigin(obj[3]->sprite, (sfVector2f){16, 60});

    rpg.game.nb_save = 0;
    rpg.controls.bools = malloc(sizeof(sfBool) * 9);
    for (int i = 0; i < 9; i++)
        rpg.controls.bools[i] = 0;
    rpg.game.follower = init_list(9950, 1280);
    rpg.game.follower2 = init_list(9900, 1280);
    init_menu(&rpg, obj, house);
    return (0);
}