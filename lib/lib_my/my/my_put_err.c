/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_put_err
*/

#include <stdio.h>
#include "my.h"

void my_put_error(char *str)
{
    int i = my_strlen(str);

    fwrite(str, sizeof(char), i, stderr);
}