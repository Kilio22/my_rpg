/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** item
*/

#include "inventory.h"

item_t *item_create(int id, ini_file_t *data)
{
    item_t *new = malloc(sizeof(item_t));
    ini_line_t *line = ini_file_get_from_key(data, my_itoa(id));
    char *path = my_strdup(ini_line_get_value_from_col(line, ASSET));

    new->name = my_strdup(ini_line_get_value_from_col(line, NAME));
    new->id = id;
    new->type = my_atoi(ini_line_get_value_from_col(line, TYPE));
    new->hp = my_atoi(ini_line_get_value_from_col(line, HP));
    new->t = sfTexture_createFromFile(path , NULL);
    new->display = dragndrop_create(new->t, new->t, new->t);
    dragndrop_set_size(new->display, 50, 50);
    if (new->t == NULL)
        return (NULL);
    new->attack = my_atoi(ini_line_get_value_from_col(line, ATTACK));
    return (new);
}

void item_show_debug(item_t *item)
{
    my_putstr(item->name);
    my_putstr("\nattack: ");
    my_putnbr(item->attack);
    my_putstr("\nhp: ");
    my_putnbr(item->hp);
    my_putstr("\ntype: ");
    my_putnbr(item->type);
    my_putstr("\n\n");
}

void item_destroy(item_t *item)
{
    sfTexture_destroy(item->t);
    free(item->name);
    free(item);
}