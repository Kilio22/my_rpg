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
    if (map_init(rpg) == -1 ||
create_map(rpg) == -1) {
        sfRenderWindow_close(WIND.wind);
        rpg->error_code = 84;
        return 1;
    }
    GAME.auberge = false;
    if (rpg->quest_status == 0) {
        if (intro_game(rpg, obj, house) == 0)
            return 1;
    }
    MENU.menu_on = 1;
    return game_create(rpg, obj, house);
}