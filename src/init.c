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
#include "rpg.h"

static void init_controls(rpg_t *rpg, int fd)
{
    char *buff;
    char **args;

    CONTROLS.keys = malloc(sizeof(int) * 6);
    buff = get_next_line(fd);
    for (int i = 0; i < 6; i++) {
        buff = get_next_line(fd);
        args = my_str_to_word_array(buff, ':');
        CONTROLS.keys[i] = my_getnbr(args[1]);
    }
}

static void init_stats(obj_t *obj, int fd)
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

void init_save(obj_t **obj, rpg_t *rpg)
{
    printf("%d\n", GAME.nb_save);
    printf("%s\n", save_path[GAME.nb_save]);
    WIND.fd = open(save_path[GAME.nb_save], O_RDONLY);
    printf("fd: %d\n", WIND.fd);
    init_controls(rpg, WIND.fd);
    init_stats(obj[2], WIND.fd);
    init_stats(obj[3], WIND.fd);
    init_stats(obj[4], WIND.fd);
    while (get_next_line(WIND.fd) != NULL);
    close(WIND.fd);
}