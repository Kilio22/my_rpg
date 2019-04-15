/*
** EPITECH PROJECT, 2018
** task02
** File description:
** function that concatenates two strings
*/

#include <stdlib.h>

char *my_strncat(char *dest, char *str, int n)
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