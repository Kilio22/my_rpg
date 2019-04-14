/*
** EPITECH PROJECT, 2018
** my_file_size
** File description:
** return lengh of an file
*/

#include "my_file.h"

int my_file_size(char const *filepath)
{
    struct stat stat_s;

    stat(filepath, &stat_s);
    return (stat_s.st_size);
}