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

void init_controls(controls_t *controls)
{
    char *buff;
    char **args;
    int fd = open("./saves/config.txt", O_RDONLY); //a enlever plus tard, fd arrive en arg

    controls->keys = malloc(sizeof(int) * 6);
    buff = get_next_line(fd);
    for (int i = 0; i < 6; i++) {
        buff = get_next_line(fd);
        args = my_str_to_word_array(buff, ':');
        controls->keys[i] = my_getnbr(args[1]);
    }
}