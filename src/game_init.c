/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_game
*/

#include "rpg.h"

int init_game(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfVector2u windSize = sfRenderWindow_getSize(WIND.wind);

    sfView_destroy(WIND.view);
    WIND.view = sfView_createFromRect((sfFloatRect){0, 0,
                                (windSize.x * 0.6), (windSize.y * 0.6)});
    for (int i = 0; i < 715; i++)
        MAP.sprite[i] = NULL;
    if (map_init(rpg) == -1 || create_map(rpg) == -1) {
        sfRenderWindow_close(WIND.wind);
        return 1;
    }
    GAME.auberge = false;
    if (GAME.objectiv == 0) {
        if (intro_game(rpg, obj, house) == 0)
            return 1;
    }
    if (rpg->debug == 1)
        rpg->debug_txt = create_text("assets/arial.ttf", "yes", 20, V2F(obj[1]->pos.x - 100, obj[1]->pos.y - 100));
    game_loop(rpg, obj, house);
    return 1;
}