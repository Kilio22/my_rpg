/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** controls
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"
#include "pp_hitbox.h"
#include "proto.h"
#include "struct.h"
#include "get_next_line.h"

void init_controls(controls_t *controls, int fd)
{
    char *buff;
    char **args;

    controls->keys = malloc(sizeof(int) * 6);
    buff = get_next_line(fd);
    for (int i = 0; i < 6; i++) {
        buff = get_next_line(fd);
        args = my_str_to_word_array(buff, ':');
        controls->keys[i] = my_getnbr(args[1]);
    }
}

void init_stats(obj_t *obj, int fd)
{
    char *buff;
    char **args;

    obj->stats = malloc(sizeof(char_stats_t));
    obj->stats->stats = malloc(sizeof(int) * 4);
    buff = get_next_line(fd);
    for (int i = 0; i < 4; i++) {
        buff = get_next_line(fd);
        args = my_str_to_word_array(buff, ':');
        obj->stats->stats[i] = my_getnbr(args[1]);
    }
}

void init_save(controls_t *controls, wind_t *wind, obj_t **obj)
{
    wind->fd = open("./saves/save1.txt", O_RDONLY);
    init_controls(controls, wind->fd);
    init_stats(obj[2], wind->fd);
    init_stats(obj[3], wind->fd);
    init_stats(obj[4], wind->fd);
}