/*
** EPITECH PROJECT, 2018
** mg_put_errchar
** File description:
** display an char on err output
*/

#include <stdio.h>
#include "my_display.h"

void mg_put_errchar(char c)
{
    fwrite(&c, sizeof(char), 1, stderr);
}
