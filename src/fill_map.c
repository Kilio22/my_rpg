/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fill_map
*/

#include "rpg.h"

void create_sprite(sprite_t **oui, char *path, int id, sfIntRect rect)
{
    int j = 0;

    while (oui[j] != NULL)
        j++;
    oui[j] = malloc(sizeof(sprite_t));
    sfTexture *text = sfTexture_createFromFile(path, NULL);
    oui[j]->sprite = sfSprite_create();
    sfSprite_setTexture(oui[j]->sprite, text, sfTrue);
    sfSprite_setTextureRect(oui[j]->sprite, rect);
    oui[j]->id = id;
    for (int i = 0; i < 5; i++)
        oui[j]->end_layout[i] = 0;
}

void fill_sprite(sprite_t **oui, sfVector2f pos)
{
    int j = 0;

    while (oui[j] != NULL)
        j++;
    j--;
    oui[j]->pos = malloc(sizeof(sfVector2f *) * 2);
    oui[j]->pos[0] = malloc(sizeof(sfVector2f));
    oui[j]->pos[0]->x = pos.x;
    oui[j]->pos[0]->y = pos.y;
    oui[j]->pos[1] = NULL;
}

void add_vector(sprite_t *oui, sfVector2f pos)
{
    int i = my_tab_vector_len(oui->pos) + 2;
    int j = 0;
    sfVector2f **new_pos = malloc(sizeof(sfVector2f *) * i);

    for (; oui->pos[j] != NULL; j++)
        new_pos[j] = oui->pos[j];
    new_pos[j] = malloc(sizeof(sfVector2f));
    new_pos[j]->x = pos.x;
    new_pos[j]->y = pos.y;
    new_pos[++j] = NULL;
    free(oui->pos);
    oui->pos = new_pos;
}