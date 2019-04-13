/*
** EPITECH PROJECT, 2018
** task02
** File description:
** function that concatenates two strings
*/

static int strlenghtf(char *dest)
{
    int i = 0;

    while (dest[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strcat(char *dest, char const *src)
{
    int m = strlenghtf(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[m + i] = src[i];
        i++;
    }
    dest[m + i] = '\0';
    return (dest);
}
