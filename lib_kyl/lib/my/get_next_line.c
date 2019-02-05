/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** get_next_line
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "my.h"

char *my_split1(int size, char **past, char **total_buffer)
{
    if (size == 0 && *past == NULL && total_buffer == NULL)
        return (NULL);
    if (total_buffer != NULL && size == 0) {
        *past = NULL;
        return (*total_buffer);
    }
    return (NULL);
}

int len_gnl(char const *str, int flag)
{
    int nbchar = 0;
    int nb;

    if (flag == 0) {
        if (str != NULL)
            while (str[nbchar] != '\0')
                nbchar++;
        return (nbchar);
    }
    nb = len_gnl(str, 0);
    if (str == NULL)
        return (0);
    for (int i = 0; i < nb; i++) {
        if (str[i] == '\n')
            return (1);
    }
    return (0);
}

char *my_realloc(char *f, char *b, int size)
{
    char *new = malloc(sizeof(char) * (len_gnl(f, 0) + len_gnl(b, 0) + 1));
    int nb = len_gnl(f, 0);
    int len = len_gnl(b, 0);
    int i = 0;

    if (new == NULL)
        return (NULL);
    if (nb == 0 && len == 0)
        return (NULL);
    if (f != NULL) {
        for (i = 0; i < nb; i++)
            new[i] = f[i];
    }
    if (size != 0) {
        for (int j = 0; j < len; j++) {
            new[i] = b[j];
            i++;
        }
    }
    new[nb + len] = '\0';
    return (new);
}

char *init_start(char *str)
{
    int nb;
    char *new;

    if (str != NULL) {
        nb = len_gnl(str, 0);
        new = malloc(sizeof(char) * nb + 1);
        if (new == NULL)
            return (NULL);
        for (int i = 0; i < nb; i++)
            new[i] = str[i];
        new[nb] = '\0';
        return (new);
    }
    else
        return (NULL);
}

char *get_next_line(int fd)
{
    static char *past = NULL;
    char buffer[READ_SIZE + 1] = {0};
    char *total_buffer = init_start(past);
    int size = 1;

    if (fd == -1)
        return (NULL);
    while (len_gnl(total_buffer, 1) == 0 && size != 0) {
        size = read(fd, buffer, READ_SIZE);
        if (size == -1)
            return (NULL);
        buffer[size] = '\0';
        total_buffer = my_realloc(total_buffer, buffer, size);
    }
    if ((size == 0 && past == NULL) || (total_buffer != NULL && size == 0))
        return (my_split1(size, &past, &total_buffer));
    for (size = 0; total_buffer[size] != '\n'; size++);
    past = my_realloc(&total_buffer[size + 1], "", 0);
    total_buffer[size] = '\0';
    return (total_buffer);
}