/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_game
*/

#include "rpg.h"

void init_game(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfVector2u windSize = sfRenderWindow_getSize(WIND.wind);

    sfView_destroy(WIND.view);
    WIND.view = sfView_createFromRect((sfFloatRect){0, 0,
                                (windSize.x * 0.6), (windSize.y * 0.6)});
    init_save(obj, rpg);
    for (int i = 0; i < 715; i++)
        MAP.sprite[i] = NULL;
    map_init(rpg);
    create_map(rpg);
    GAME.auberge = false;
    game_loop(rpg, obj, house);
}