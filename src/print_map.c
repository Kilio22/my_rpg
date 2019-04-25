/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** print_map
*/

#include "rpg.h"

void check_sprite_position(sprite_t *sprites, obj_t **obj, wind_t wind,
int opt)
{
    int j = (opt == -1) ? 0 : sprites->end_layout[opt];

    for (; j <= sprites->end_layout[opt + 1] - 1; j++) {
        if (sprites->pos[j]->x < (obj[1]->pos.x - 512) ||
            sprites->pos[j]->x > (obj[1]->pos.x + 512) ||
            sprites->pos[j]->y < (obj[1]->pos.y - 256) ||
            sprites->pos[j]->y > (obj[1]->pos.y + 256))
            continue;
        else {
            sfSprite_setPosition(sprites->sprite,
                                            *(sprites->pos[j]));
            sfRenderWindow_drawSprite(wind.wind,
                                            sprites->sprite, NULL);
        }
    }
}

void print_map(sprite_t **sprites, obj_t **obj, wind_t wind)
{
    for (int j = -1; j < 2; j++) {
        for (int i = 0; sprites[i] != NULL; i++)
            check_sprite_position(sprites[i], obj, wind, j);
    }
}

void print_map2(sprite_t **sprites, obj_t **obj, wind_t wind)
{
    for (int j = 2; j < 4; j++) {
        for (int i = 0; sprites[i] != NULL; i++)
            check_sprite_position(sprites[i], obj, wind, j);
    }
}