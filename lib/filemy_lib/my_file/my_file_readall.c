/*
** EPITECH PROJECT, 2018
** my_file_readall
** File description:
** read an entire file and put it in an str
*/

#include <stdio.h>
#include "get_next_line.h"
#include "windows.h"
#include "my_file.h"

static int mg_strlen(char const *str)
{
    register int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

static char *mg_strcpy(char *dest, char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

static char *my_strcat(char **s1, char const *s2)
{
    int size = mg_strlen(*s1) + mg_strlen(s2) + 1;
    char *new_str = malloc(sizeof(char) * size);

    mg_strcpy(new_str, *s1);
    mg_strcpy(new_str + mg_strlen(*s1), s2);
    free(*s1);
    *s1 = new_str;
    return (new_str);
}

char *my_file_readall(char const *filepath, int nb)
{
    char *buff = malloc(sizeof(char));
    int i = 0;
    char *line = NULL;
    FILE *stream = fopen(filepath, "r");

    buff[0] = '\0';
    if (stream == NULL)
        return (NULL);
    while ((line = get_next_line(stream)) != NULL && i != nb) {
        if (i++ < nb)
            my_strcat(&line, "\n");
        my_strcat(&buff, line);
        free(line);
    }
    fclose(stream);
    free(line);
    if (i != nb)
        return NULL;
    get_next_line(NULL);
    return (buff);
}
