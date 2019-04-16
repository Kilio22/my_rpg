/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** game_init
*/

#include "rpg.h"

int check_sprite(layer_t *layers, int x, int y, rpg_t *rpg)
{
    int pos_x = x * 32;
    int pos_y = y * 32;

    for (int j = 0; MAP.sprite[j] != NULL; j++) {
        if (layers->map[y][x] == MAP.sprite[j]->id) {
            add_vector(MAP.sprite[j], (sfVector2f){pos_x, pos_y}, MAP.sprite);
            return 1;
        }
    }
    return 0;
}

int tilemaping(layer_t *layers, rpg_t *rpg, int y)
{
    int l = 0;
    sfIntRect posRect = {0, 0, 32, 32};

    for (int x = 0; x < layers->width; x++) {
        if (layers->map[y][x] == 0)
            continue;
        while (MAP.gid[l] != NULL && MAP.gid[l]->gid <= layers->map[y][x])
            l++;
        l--;
        posRect.left = RECT_LEFT;
        posRect.top = RECT_TOP;
        if (check_sprite(layers, x, y, rpg) == 0) {
            create_sprite(MAP.sprite,
MAP.gid[l]->path, layers->map[y][x], posRect);
            fill_sprite(MAP.sprite, (sfVector2f){x * 32, y * 32});
        }
        if (MAP.sprite == NULL)
            return -1;
        l = 0;
    }
    return 0;
}

void set_end_layer(int layer, sprite_t **sprite)
{
    int j;

    for (int i = 0; sprite[i] != NULL; i++) {
        for (j = 0; sprite[i]->pos[j] != NULL; j++);
        sprite[i]->end_layout[layer] = j;
    }
}

int create_map(rpg_t *rpg)
{
    int ret_val = 0;

    for (int i = 0; MAP.layers[i] != NULL; i++) {
        for (int y = 0; y < MAP.layers[i]->height; y++) {
            ret_val += tilemaping(MAP.layers[i], rpg, y);
            ret_val == -1 ? y = MAP.layers[i]->height : 0;
        }
        if (ret_val == -1)
            return -1;
        set_end_layer(i, MAP.sprite);
    }
    for (int j = 0; MAP.sprite[j] != NULL; j++)
        MAP.sprite[j]->end_layout[5] = -1;
        return 0;
}