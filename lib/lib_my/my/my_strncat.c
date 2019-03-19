/*
** EPITECH PROJECT, 2018
** task03
** File description:
** same as task02 but using a parameter n
*/

static int strlenghth(char *dest)
{
    int i = 0;

    while (dest[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int m = strlenghth(dest);
    int i = 0;

    while (src[i] != src[nb]) {
        dest[m + i] = src[i];
        i++;
    }
    dest[m + i] = '\0';
    return (dest);
}
