/*
** EPITECH PROJECT, 2018
** my_file_readall
** File description:
** read an entire file and put it in an str
*/

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

char *my_file_readall(char const *filepath)
{
    char *buff = malloc(sizeof(char));
    int size = 0;
    char c;
    int fd = open(filepath, O_RDONLY);

    buff[0] = '\0';
    if (fd == -1)
        return (NULL);
    do {
        size = read(fd, &c, 1);
        if (size)
            my_strcat(&buff, (char[]){c, '\0'});
    } while (size);
    return (buff);
}
