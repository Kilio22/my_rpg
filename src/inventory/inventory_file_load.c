/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_file_load
*/

#include "inventory.h"

static int inventory_fill_stuff(inventory_t *inv, ini_file_t *file, int i)
{
    char s[] = {'S', 'T', 'U', 'F', 'F', '0' + i, 0};
    ini_line_t *ini = ini_file_get_from_key(file, s);
    char *buff;
    item_t *buff_item;
    ini_file_t *items = ini_file_create_from_file(mg_strdup(items_data), 13);

    if (!ini || !items || ini->values->size != 6)
        return (0);
    for (int j = 0; j < 6; j++) {
        buff = ini_line_get_value_from_col(ini, j);
        if (mg_strcmp(buff, "NULL"))
            continue;
        buff_item = item_create(mg_atoi(buff), items);
        inv->stuff[i][j] = buff_item;
    }
    return (1);
}

static int inventory_fill_stock(inventory_t *inv, ini_file_t *file)
{
    ini_line_t *line = ini_file_get_from_key(file, "STOCK");
    ini_file_t *items = ini_file_create_from_file(mg_strdup(items_data), 13);
    item_t *buff_item;
    char *buff;

    if (!line || !items)
        return (0);
    for (int i = 0; i < line->values->size; i++) {
        buff = ini_line_get_value_from_col(line, i);
        if (!mg_str_isint(buff))
            continue;
        buff_item = item_create(mg_atoi(buff), items);
        if (buff_item)
            inventory_add_item(inv, buff_item);
    }
    return (1);
}

inventory_t *inventory_create_from_file(sfRenderWindow *window, char *path)
{
    ini_file_t *ini = ini_file_create_from_file(path, 6);
    inventory_t *inv = inventory_create(window);

    if (!ini)
        return (inventory_create(window));
    for (int i = 0; i < 3; i++)
        if (inventory_fill_stuff(inv, ini, i) == 0)
            return (inventory_create(window));
    if (inventory_fill_stock(inv, ini) == 0)
        return (inventory_create(window));
    return (inv);
}