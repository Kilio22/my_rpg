/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_tab_len
*/

#include "my.h"

int my_tab_len(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return (i);
}