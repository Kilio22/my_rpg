/*
** EPITECH PROJECT, 2018
** Task01
** File description:
** copy a string into an other
*/

void my_putchar(char c);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return (dest);
}
