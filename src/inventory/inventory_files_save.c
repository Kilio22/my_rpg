/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_files
*/

#include "inventory.h"

static ini_line_t *get_line_stock(inventory_t *inv)
{
    ini_line_t *line = ini_line_create("STOCK");

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (!inv->stock[i])
            continue;
        double_vector_push_back(line->values, mg_itoa(inv->stock[i]->id));
    }
    return (line);
}

static ini_line_t *get_line_stuff(inventory_t *inv, int i)
{
    char s[] = {'S', 'T', 'U', 'F', 'F', '0' + i, 0};
    ini_line_t *l = ini_line_create(s);

    for (int j = 0; j < 6; j++) {
        if (!inv->stuff[i][j])
            double_vector_push_back(l->values, mg_strdup("NULL"));
        else
            double_vector_push_back(l->values, mg_itoa(inv->stuff[i][j]->id));
    }
    return (l);
}

void inventory_save(inventory_t *inv, char *path)
{
    ini_file_t *ini = ini_file_create();

    double_vector_push_back(ini->lines, get_line_stock(inv));
    for (int i = 0; i < 3; i++)
        double_vector_push_back(ini->lines, get_line_stuff(inv, i));
    ini_file_write_path(ini, path);
}