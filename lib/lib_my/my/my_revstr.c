/*
** EPITECH PROJECT, 2018
** task03
** File description:
** write a fonction that reverse a string
*/

void my_putchar(char c);

static int strlenght(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    i = i - 1;
    return i;
}

char *my_revstr(char *str)
{
    char stockage;
    int i = strlenght(str);
    int tempo = 0;

    while (tempo <= i / 2) {
        stockage = str[tempo];
        str[tempo] = str[i - tempo];
        str[i - tempo] = stockage;
        tempo++;
    }
    return (str);
}
