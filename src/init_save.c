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

static int loop_ctrls(int fd, rpg_t *rpg)
{
    char *buff = NULL;
    char **args = NULL;

    buff = get_next_line(fd);
    for (int i = 0; i < 6; i++) {
        buff = get_next_line(fd);
        if (buff == NULL) {
            return -1;
        }
        args = my_str_to_word_array(buff, ':');
        if (args == NULL) {
            return -1;
        }
        CONTROLS.keys[i] = my_getnbr(args[1]);
    }
    return 0;
}

static int init_controls(rpg_t *rpg, int fd)
{
    CONTROLS.keys = malloc(sizeof(int) * 6);
    if (CONTROLS.keys == NULL) {
        return -1;
    }
    if (loop_ctrls(fd, rpg) == -1) {
        return -1;
    }
    return 0;
}

static int init_stats(obj_t *obj, int fd)
{
    char *buff;
    char **args;

    obj->stats = malloc(sizeof(char_stats_t));
    if (obj->stats == NULL)
        return -1;
    obj->stats->stats = malloc(sizeof(int) * 4);
    if (obj->stats->stats == NULL)
        return -1;
    if ((buff = get_next_line(fd)) == NULL)
        return -1;
    for (int i = 0; i < 4; i++) {
        buff = get_next_line(fd);
        if (buff == NULL)
            return -1;
        args = my_str_to_word_array(buff, ':');
        if (args == NULL)
            return -1;
        obj->stats->stats[i] = my_getnbr(args[1]);
    }
    return 0;
}

int init_save(obj_t **obj, rpg_t *rpg)
{
    int fd = open(save_path[GAME.nb_save], O_RDONLY);

    if (init_controls(rpg, fd) == -1) {
        rpg->error_code = 84;
        return -1;
    }
    if (init_stats(obj[1], fd) == -1) {
        rpg->error_code = 84;
        return -1;
    }
    while (get_next_line(fd) != NULL);
    close(fd);
    return 0;
}