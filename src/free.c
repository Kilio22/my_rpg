/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** free
*/

#include <stdlib.h>
#include "rpg.h"

void free_map(map_t map)
{
    for (int i = 0; map.sprite[i] != NULL; i++) {
        for (int j = 0; map.sprite[i]->pos[j] != NULL; j++)
            free(map.sprite[i]->pos[j]);
        free(map.sprite[i]->pos);
        sfTexture_destroy((sfTexture *)sfSprite_getTexture(map.sprite[i]->sprite));
        sfSprite_destroy(map.sprite[i]->sprite);
        free(map.sprite[i]);
    }
    for (int i = 0; map.layers[i] != NULL; i++) {
        for (int j = 0; j < map.layers[i]->height; j++)
            free(map.layers[i]->map[j]);
        free(map.layers[i]->map);
        free(map.layers[i]);
    }
    for (int i = 0; map.gid[i] != NULL; i++) {
        free(map.gid[i]->path);
        free(map.gid[i]);
    }
}

void free_obj(obj_t **obj)
{
    for (int i = 0; obj[i] != NULL; i++) {
        sfImage_destroy(obj[i]->image);
        sfTexture_destroy(obj[i]->texture);
        sfSprite_destroy(obj[i]->sprite);
        sfClock_destroy(obj[i]->clock);
        free(obj[i]);
    }
    free(obj);
}

void free_house(house_t **house)
{
    for (int i = 0; house[i] != NULL; i++) {
        sfImage_destroy(house[i]->image);
        sfImage_destroy(house[i]->door_image);
        sfTexture_destroy(house[i]->doorTexture);
        for (int j = 0; j < 5; j++)
            sfSprite_destroy(house[i]->tab[j]);
        free(house[i]);
    }
    free(house);
}

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}