/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_utils
*/

#include "struct.h"
#include "my.h"

int my_equal_len(char *str)
{
    int i = 0;

    for (; str[i] != '\0' && str[i] != '='; i++);
    return i;
}

int layer_len(layer_t **layers)
{
    int i = 0;

    for (; layers[i] != NULL; i++);
    return i;
}

int gid_len(first_gid_t **gid)
{
    int i = 0;

    for (; gid[i] != NULL; i++);
    return i;
}

int my_tab_vector_len(sfVector2f **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return (i);
}