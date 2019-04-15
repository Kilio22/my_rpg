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
            add_vector(MAP.sprite[j], (sfVector2f){pos_x, pos_y});
            return 1;
        }
    }
    return 0;
}

void tilemaping(layer_t *layers, rpg_t *rpg, int y)
{
    int l = 0;
    sfIntRect posRect = {0, 0, 32, 32};

    for (int x = 0; x < layers->width; x++) {
        if (layers->map[y][x] == 0)
            continue;
        while (MAP.gid[l] != NULL && MAP.gid[l]->gid <= layers->map[y][x])
            l++;
        l--;
        posRect.left =
32 * ((layers->map[y][x] - MAP.gid[l]->gid) % MAP.gid[l]->offset);
        posRect.top =
32 * ((layers->map[y][x] - MAP.gid[l]->gid) / MAP.gid[l]->offset);
        if (check_sprite(layers, x, y, rpg) == 0) {
            create_sprite(MAP.sprite,
MAP.gid[l]->path, layers->map[y][x], posRect);
            fill_sprite(MAP.sprite, (sfVector2f){x * 32, y * 32});
        }
        l = 0;
    }
}

void set_end_layout(int layout, sprite_t **sprite)
{
    int j;

    for (int i = 0; sprite[i] != NULL; i++) {
        for (j = 0; sprite[i]->pos[j] != NULL; j++);
        sprite[i]->end_layout[layout] = j;
    }
}

void create_map(rpg_t *rpg)
{
    for (int i = 0; MAP.layers[i] != NULL; i++) {
        for (int y = 0; y < MAP.layers[i]->height; y++) {
            tilemaping(MAP.layers[i], rpg, y);
        }
        set_end_layout(i, MAP.sprite);
    }
    for (int j = 0; MAP.sprite[j] != NULL; j++)
        MAP.sprite[j]->end_layout[4] = -1;
}