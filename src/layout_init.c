/*
** EPITECH PROJECT, 2019
** 1MAKEFILE
** File description:
** map_init
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "printf.h"
#include "my.h"
#include "struct.h"
#include "proto.h"
#include "macros.h"
#include "get_next_line.h"

layer_t **add_layer(char *str, layer_t *layers[5], int fd)
{
    char **array = my_str_to_word_array(str, '"');
    char *line;
    int i = 0;

    for (; layers[i] != NULL; i++);
    layers[i] = malloc(sizeof(layer_t));
    layers[i]->width = my_atoi(array[2]);
    layers[i]->height = my_atoi(array[4]);
    layers[i]->map = malloc(sizeof(int *) * (layers[i]->height));
    for (int a = 0; a < layers[i]->height; a++) {
        line = get_next_line(fd);
        array = my_str_to_word_array(line, ',');
        layers[i]->map[a] = malloc(sizeof(int) * (layers[i]->width));
        for (int x = 0; x < layers[i]->width; x++)
            layers[i]->map[a][x] = my_atoi(array[x]);
        free_array(array);
        free(line);
    }
    layers[++i] = NULL;
    return (layers);
}

void add_gid(char *str, first_gid_t *gid[4])
{
    char **array = my_str_to_word_array(str, '"');
    int i = 0;

    for (; gid[i] != NULL; i++);
    gid[i] = malloc(sizeof(first_gid_t));
    gid[i]->gid = my_atoi(array[0]);
    gid[i]->path = my_strdup(array[2]);
    gid[i]->offset = my_atoi(array[4]);
    gid[++i] = NULL;
    free(array);
}

void map_init(rpg_t *rpg)
{
    int fd = open("assets/map.txt", O_RDONLY);
    char *line = NULL;

    if (fd == -1) {
        my_printf("OPEN FAILED\n");
        return;
    }
    line = get_next_line(fd);
    MAP.gid[0] = NULL;
    MAP.layers[0] = NULL;
    while (line != NULL && my_strncmp(line, "id=", 3)) {
        add_gid(&line[my_equal_len(line) + 1], MAP.gid);
        line = get_next_line(fd);
    }
    while (line) {
        add_layer(&line[my_equal_len(line) + 1], MAP.layers, fd);
        line = get_next_line(fd);
    }
}