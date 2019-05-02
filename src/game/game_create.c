/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** game_create
*/

#include "rpg.h"

static int game_create_load(obj_t **obj)
{
    obj[0] = create_object(obj_path[0], V2F(10050, 1570), RECT_BASE, sfTrue);
    if (obj[0] == NULL)
        return (84);
    obj[0]->rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(obj[0]->rectangle, V2F(32, 16));
    sfRectangleShape_setOrigin(obj[0]->rectangle, V2F(16, 8));
    obj[0]->rectangle_bound =
sfRectangleShape_getGlobalBounds(obj[0]->rectangle);
    free_obj(obj[1]);
    obj[1] = create_object(obj_path[1], V2F(10050, 1570), RECT_OBJ, sfFalse);
    if (obj[1] == NULL)
        return (84);
    sfSprite_setOrigin(obj[1]->sprite, (sfVector2f){16, 60});
    for (int i = 5; i < 11; i++) {
        if (obj[i] != NULL) {
            free_obj(obj[i]);
            obj[i] = NULL;
        }
    }
    return 1;
}

static void create_followers(rpg_t *rpg, obj_t **obj)
{
    if (obj[2] == NULL) {
        obj[2] = create_object(obj_path[4],
    (sfVector2f){obj[0]->pos.x - 50, obj[0]->pos.y}, RECT_OBJ, sfFalse);
        sfSprite_setOrigin(obj[2]->sprite, (sfVector2f){16, 60});
        GAME.follower = init_list(obj[0]->pos.x - 50, obj[0]->pos.y);
    }
    if (obj[3] == NULL) {
        obj[3] = create_object(obj_path[6],
(sfVector2f){obj[0]->pos.x - 100, obj[0]->pos.y}, RECT_OBJ, sfFalse);
        sfSprite_setOrigin(obj[3]->sprite, (sfVector2f){16, 60});
        GAME.follower2 = init_list(obj[0]->pos.x - 100, obj[0]->pos.y);
    }
}

static void create_ennemis(obj_t **obj)
{
    sfVector2f vects[] = {{8368, 2610}, {10844, 2222}, {11952, 636}};
    for (int i = 6; i < 9; i++) {
        if (obj[i] == NULL) {
            obj[i] = create_object(obj_path[3], vects[i - 6],
RECT_OBJ, sfFalse);
            sfSprite_setOrigin(obj[i]->sprite, V2F(16, 60));
        }
    }
    for (int i = 6; i < 9; i++) {
        OBJ_RECT = sfRectangleShape_create();
        sfRectangleShape_setSize(OBJ_RECT, V2F(32, 16));
        sfRectangleShape_setOrigin(OBJ_RECT, V2F(16, 8));
        sfRectangleShape_setPosition(OBJ_RECT, obj[i]->pos);
        obj[i]->rectangle_bound =
sfRectangleShape_getGlobalBounds(OBJ_RECT);
        obj[i]->oldPos = sfSprite_getPosition(obj[i]->sprite);
    }
}

void destroy_sounds(rpg_t *rpg)
{
    sfSoundBuffer_destroy((sfSoundBuffer *)sfSound_getBuffer(rpg->music.aled));
    sfSoundBuffer_destroy((sfSoundBuffer *)sfSound_getBuffer(rpg->music.hurt));
    sfSound_destroy(rpg->music.aled);
    sfSound_destroy(rpg->music.hurt);
}

int game_create(rpg_t *rpg, obj_t **obj, house_t **house)
{
    if (rpg->quest_status == 1) {
        free_obj(obj[0]);
        if (game_create_load(obj) == 84)
            return 84;
    }
    create_followers(rpg, obj);
    create_ennemis(obj);
    if (rpg->quest_status == 1 || rpg->quest_status == 26) {
        create_framebuffer(rpg);
        if (init_stats(obj) == -1)
            return 84;
        game_loop(rpg, obj, house);
    }
    for (int i = 0; house[i]; i++)
        house[i]->display_house = 1;
    return 1;
}