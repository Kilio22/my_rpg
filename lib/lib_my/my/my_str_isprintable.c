/*
** EPITECH PROJECT, 2018
** task14
** File description:
** return 1 and return 0 if not
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return (1);
    while (str[i] != '\0' && (str[i] >= ' ' || str[i] <= '~')) {
        i++;
        if (str[i] == '\0')
            return (1);
    }
    return (0);
}
