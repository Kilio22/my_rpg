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
        sfTexture_destroy((sfTexture *)sfSprite_getTexture(
map.sprite[i]->sprite));
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

void free_obj(obj_t *obj)
{
    if (obj == NULL)
        return;
    sfImage_destroy(obj->image);
    sfTexture_destroy(obj->texture);
    sfSprite_destroy(obj->sprite);
    sfClock_destroy(obj->clock);
    free(obj);
}

void free_objs(obj_t **obj)
{
    for (int i = 0; i < 11; i++) {
        if (obj[i] != NULL) {
            free_obj(obj[i]);
            obj[i] = NULL;
        }
    }
}

void free_house(house_t *house)
{
    if (house == NULL)
        return;
    sfImage_destroy(house->image);
    sfImage_destroy(house->door_image);
    sfTexture_destroy(house->doorTexture);
    for (int j = 0; j < 5; j++)
        sfSprite_destroy(house->tab[j]);
    sfRectangleShape_destroy(house->door_use_rectangle);
    free(house);
}

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}