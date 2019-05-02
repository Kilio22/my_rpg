/*
** EPITECH PROJECT, 2018
** task02
** File description:
** fonction that copy n characters from a string into an other
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != src[n] && i <= n) {
        dest[i] = src[i];
        i++;
        if (i == n) {
            dest[i] = '\0';
        }
    }
    return (dest);
}
