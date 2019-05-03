/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2018
** File description:
** get_next_line
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

static char *my_strndup(char *str, int n)
{
    char *new_str;
    int len = 0;
    int i = 0;

    while (str[len] != '\0' && (n == -1 || (n != -1 && len < n)))
        len++;
    new_str = malloc(sizeof(char) * (len + 1));
    if (new_str == NULL)
        return (NULL);
    for (; i < len; i++)
        new_str[i] = str[i];
    new_str[len] = '\0';
    return (new_str);
}

static char *my_strncat(char *dest, char *str, int n)
{
    char *new_str;
    int str_len = 0;
    int dest_len = 0;
    int i = 0;

    while (dest[dest_len] != '\0')
        dest_len++;
    while (str[str_len] != '\0' && (n == -1 || (n != -1 && str_len < n)))
        str_len++;
    new_str = malloc(sizeof(char) * (dest_len + str_len + 1));
    if (new_str == NULL)
        return (NULL);
    for (i = 0; i < dest_len; i++)
        new_str[i] = dest[i];
    for (int j = 0; j < str_len; i++) {
        new_str[i] = str[j];
        j++;
    }
    new_str[i] = '\0';
    return (new_str);
}

static char *read_file(FILE *stream, char *str, char **readed)
{
    char buf[READ_SIZE + 1] = {0};
    int read_value;

    read_value = fread(buf, sizeof(char), READ_SIZE, stream);
    if (read_value == -1 || str == NULL)
        return (NULL);
    buf[read_value] = '\0';
    for (int i = 0; i < READ_SIZE || buf[i] != '\0'; i++) {
        if (buf[i] == '\n') {
            *readed = my_strndup(&buf[i + 1], -1);
            str = my_strncat(str, buf, i);
            return (str);
        }
    }
    if (*readed == NULL && read_value == 0 && str[0] == '\0')
        return (NULL);
    if (read_value != READ_SIZE)
        return (my_strncat(str, buf, read_value));
    return (read_file(stream, my_strncat(str, buf, -1), readed));
}

static char *check_init(char **str, char **readed, FILE *stream)
{
    if (stream == NULL) {
        (*readed) = NULL;
        return NULL;
    }
    if ((*readed) != NULL) {
        (*str) = my_strncat((*readed), "", -1);
        free((*readed));
    }
    else
        (*str) = my_strncat("", "", -1);
    return (*str);
}

char *get_next_line(FILE *stream)
{
    static char *readed = NULL;
    char *str;

    if (check_init(&str, &readed, stream) == NULL)
        return NULL;
    readed = NULL;
    if (str == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            readed = my_strncat(&str[i + 1], "", -1);
            str = my_strndup(str, i);
            return (str);
        }
    }
    return (read_file(stream, str, &readed));
}