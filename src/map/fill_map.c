/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fill_map
*/

#include "rpg.h"

int create_sprite(sprite_t **sprites, char *path, int id, sfIntRect rect)
{
    int j = 0;

    if (sprites == NULL)
        return -1;
    while (sprites[j] != NULL)
        j++;
    sprites[j] = malloc(sizeof(sprite_t));
    if (sprites[j] == NULL) {
        sprites = NULL;
        return -1;
    }
    sfTexture *text = sfTexture_createFromFile(path, NULL);
    sprites[j]->sprite = sfSprite_create();
    sfSprite_setTexture(sprites[j]->sprite, text, sfTrue);
    sfSprite_setTextureRect(sprites[j]->sprite, rect);
    sprites[j]->id = id;
    for (int i = 0; i < 5; i++)
        sprites[j]->end_layout[i] = 0;
    return 0;
}

void fill_sprite(sprite_t **sprites, sfVector2f pos)
{
    int j = 0;

    if (sprites == NULL)
        return;
    while (sprites[j] != NULL)
        j++;
    j--;
    sprites[j]->pos = malloc(sizeof(sfVector2f *) * 2);
    if (sprites[j]->pos == NULL) {
        sprites = NULL;
        return;
    }
    sprites[j]->pos[0] = malloc(sizeof(sfVector2f));
    if (sprites[j]->pos[0] == NULL) {
        sprites = NULL;
        return;
    }
    sprites[j]->pos[0]->x = pos.x;
    sprites[j]->pos[0]->y = pos.y;
    sprites[j]->pos[1] = NULL;
}

void add_vector(sprite_t *sprites, sfVector2f pos)
{
    int i = my_tab_vector_len(sprites->pos) + 2;
    int j = 0;
    sfVector2f **new_pos = malloc(sizeof(sfVector2f *) * i);

    if (new_pos == NULL)
        return;
    for (; sprites->pos[j] != NULL; j++)
        new_pos[j] = sprites->pos[j];
    new_pos[j] = malloc(sizeof(sfVector2f));
    if (new_pos[j] == NULL)
        return;
    new_pos[j]->x = pos.x;
    new_pos[j]->y = pos.y;
    new_pos[++j] = NULL;
    free(sprites->pos);
    sprites->pos = new_pos;
}