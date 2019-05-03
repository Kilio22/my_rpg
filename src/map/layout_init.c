/*
** EPITECH PROJECT, 2019
** 1MAKEFILE
** File description:
** map_init
*/

#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include "windows.h"
#include "printf.h"
#include "my.h"
#include "struct.h"
#include "proto.h"
#include "macros.h"
#include "get_next_line.h"

int loop_add_layer(layer_t *layers[5], FILE *stream, char **array, int i)
{
    char *line = NULL;

    for (int a = 0; a < layers[i]->height; a++) {
        line = get_next_line(stream);
        array = my_str_to_word_array(line, ',');
        if (array == NULL)
            return -1;
        layers[i]->map[a] = malloc(sizeof(int) * (layers[i]->width));
        if (layers[i]->map[a] == NULL)
            return -1;
        for (int x = 0; x < layers[i]->width; x++)
            layers[i]->map[a][x] = my_atoi(array[x]);
        free_array(array);
        free(line);
    }
    return 0;
}

layer_t **add_layer(char *str, layer_t *layers[5], FILE *stream)
{
    char **array = my_str_to_word_array(str, '"');
    int i = 0;

    for (; layers[i] != NULL; i++);
    layers[i] = malloc(sizeof(layer_t));
    if (layers[i] == NULL || array == NULL)
        return NULL;
    layers[i]->width = my_atoi(array[2]);
    layers[i]->height = my_atoi(array[4]);
    layers[i]->map = malloc(sizeof(int *) * (layers[i]->height));
    if (layers[i]->map == NULL)
        return NULL;
    if (loop_add_layer(layers, stream, array, i) == -1)
        return NULL;
    layers[++i] = NULL;
    return (layers);
}

void add_gid(char *str, first_gid_t *gid[4])
{
    char **array = my_str_to_word_array(str, '"');
    int i = 0;

    for (; gid[i] != NULL; i++);
    gid[i] = malloc(sizeof(first_gid_t));
    if (gid[i] == NULL)
        return;
    gid[i]->gid = my_atoi(array[0]);
    gid[i]->path = my_strdup(array[2]);
    gid[i]->offset = my_atoi(array[4]);
    gid[++i] = NULL;
    free(array);
}

int map_init(rpg_t *rpg)
{
    FILE *stream = fopen("assets/map.txt", "r");
    char *line = NULL;

    if (stream == NULL) {
        my_printf("OPEN FAILED\n");
        return -1;
    }
    line = get_next_line(stream);
    MAP.gid[0] = NULL;
    MAP.layers[0] = NULL;
    while (line != NULL && my_strncmp(line, "id=", 3)) {
        add_gid(&line[my_equal_len(line) + 1], MAP.gid);
        line = get_next_line(stream);
    }
    while (line) {
        if (add_layer(&line[my_equal_len(line) + 1],
MAP.layers, stream) == NULL)
            return -1;
        line = get_next_line(stream);
    }
    return 0;
}