/*
** EPITECH PROJECT, 2018
** task04
** File description:
** reproduce the behavior of the strstr function
*/

static int verif(char *str, char const *to_find, int p)
{
    int i = 0;

    while ((str[i] && to_find[i]) != '\0' && i != p) {
        if (str[i] != to_find[i]) {
            return (str[i] - to_find[i]);
        }
        i++;
    }
    return (0);
}

static int strlenghtg(char const *to_find)
{
    int i = 0;

    while (to_find[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int p = strlenghtg(to_find);

    while (str[i] != '\0') {
        if (str[i] == to_find[0] && (verif(&str[i], to_find, p)) == 0)
            return (&str[i]);
        i++;
    }
    return (0);
}
