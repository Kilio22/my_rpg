/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_file_write
*/

#ifdef _WIN32
    #define _CRT_SECURE_NO_WARNINGS
#endif
#include "my_ini.h"

static int file_str_size(ini_file_t *file)
{
    int size = 0;
    double_chained_t *current = file->lines->start;
    ini_line_t *current_content;
    char *buff;

    while (current) {
        current_content = (ini_line_t *)current->content;
        buff = ini_line_to_str(current_content);
        size += mg_strlen(buff) + 1;
        free(buff);
        current = current->next;
    }
    return (size);
}

char *ini_file_to_str(ini_file_t *file)
{
    char *buff = malloc(sizeof(char) * (file_str_size(file)));
    char *to_insert;
    double_chained_t *current = file->lines->start;
    ini_line_t *current_content;
    int offset = 0;

    while (current) {
        current_content = (ini_line_t *)current->content;
        to_insert = ini_line_to_str(current_content);
        mg_strcpy(buff + offset, to_insert);
        offset += mg_strlen(to_insert) + 1;
        buff[offset - 1] = '\n';
        current = current->next;
    }
    buff[offset - 1] = '\0';
    return (buff);
}

void ini_file_write(ini_file_t *file)
{
    char *buff = ini_file_to_str(file);
    FILE *stream = fopen(file->path, "w+");

    fwrite(buff, sizeof(char), mg_strlen(buff), stream);
    free(buff);
    fclose(stream);
}

void ini_file_write_path(ini_file_t *file, char *path)
{
    char *buff = ini_file_to_str(file);
    FILE *stream = fopen(path, "w+");

    fwrite(buff, sizeof(char), mg_strlen(buff), stream);
    free(buff);
    fclose(stream);
}