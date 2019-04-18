/*
** EPITECH PROJECT, 2019
** mg_rpg
** File description:
** item
*/

#include "inventory.h"

item_t *item_create(int id, ini_file_t *data)
{
    item_t *new = malloc(sizeof(item_t));
    ini_line_t *line = ini_file_get_from_key(data, mg_itoa(id));
    char *path = mg_strdup(ini_line_get_value_from_col(line, ASSET));

    if (new == NULL)
        return NULL;
    new->name = mg_strdup(ini_line_get_value_from_col(line, NAME));
    new->id = id;
    new->type = mg_atoi(ini_line_get_value_from_col(line, TYPE));
    new->hp = mg_atoi(ini_line_get_value_from_col(line, HP));
    new->t = sfTexture_createFromFile(path , NULL);
    new->display = dragndrop_create(new->t, new->t, new->t);
    dragndrop_set_size(new->display, 50, 50);
    if (new->t == NULL)
        return (NULL);
    new->attack = mg_atoi(ini_line_get_value_from_col(line, ATTACK));
    return (new);
}

void item_show_debug(item_t *item)
{
    mg_putstr(item->name);
    mg_putstr("\nattack: ");
    mg_putnbr(item->attack);
    mg_putstr("\nhp: ");
    mg_putnbr(item->hp);
    mg_putstr("\ntype: ");
    mg_putnbr(item->type);
    mg_putstr("\n\n");
}

void item_destroy(item_t *item)
{
    sfTexture_destroy(item->t);
    free(item->name);
    free(item);
}