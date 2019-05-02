/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_game
*/

#include "rpg.h"

void init_objs(obj_t **obj)
{
    sfVector2f vects[] = {{10934, 2860}, {10934, 2860}, {0, 0}, {10834, 1996},
{10868, 2016}, {10802, 2016}, {11768, 1396}, {10926, 2840}};

    for (int i = 0; i < 11; i++)
        obj[i] = NULL;
    obj[0] = create_object(obj_path[0], vects[0], RECT_BASE, sfTrue);
    obj[0]->rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(obj[0]->rectangle, V2F(32, 16));
    sfRectangleShape_setOrigin(obj[0]->rectangle, V2F(16, 8));
    obj[1] = create_object(obj_path[1], vects[1], RECT_OBJ, sfFalse);
    obj[4] = create_object(obj_path[2], vects[2],
(sfIntRect){0, 0, 14528, 3200}, sfFalse);
    obj[5] = create_object(obj_path[3], vects[3], RECT_OBJ, sfTrue);
    obj[6] = create_object(obj_path[3], vects[4], RECT_OBJ, sfTrue);
    obj[7] = create_object(obj_path[3], vects[5], RECT_OBJ, sfTrue);
    obj[8] = create_object(obj_path[4], vects[6], RECT_OBJ, sfTrue);
    obj[9] = create_object("assets/bato.png", vects[7],
(sfIntRect){0, 0, 118, 204}, sfTrue);
    sfSprite_setOrigin(obj[1]->sprite, (sfVector2f){16, 60});
    obj[0]->rectangle_bound =
sfRectangleShape_getGlobalBounds(obj[0]->rectangle);
}

int init_game(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfVector2u windSize = sfRenderWindow_getSize(WIND.wind);

    init_objs(obj);
    sfView_destroy(WIND.view);
    WIND.view = sfView_createFromRect((sfFloatRect){0, 0,
                                (windSize.x * 0.6), (windSize.y * 0.6)});
    for (int i = 0; i < 715; i++)
        MAP.sprite[i] = NULL;
    if (map_init(rpg) == -1 || create_map(rpg) == -1) {
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
    game_create(rpg, obj, house);
    return 0;
}