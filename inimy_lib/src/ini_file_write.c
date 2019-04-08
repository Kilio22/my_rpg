/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_file_write
*/

#include "my_ini.h"

void ini_file_write_from_path(ini_file_t *ini, char const *path)
{
    fd_t fd = open(path, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    double_chained_t *current = ini->lines->start;
    ini_line_t *current_content = (ini_line_t *)current->content;
    char *to_write;

    if (fd == -1)
        return;
    while (current != 0) {
        current_content = current->content;
        to_write = ini_line_to_str(current_content);
        write(fd, to_write, my_strlen(to_write));
        write(fd, "\n", 1);
        free(to_write);
        current = current->next;
    }
    close(fd);
}

void ini_file_write(ini_file_t *ini)
{
    ini_file_write_from_path(ini, ini->path);
}