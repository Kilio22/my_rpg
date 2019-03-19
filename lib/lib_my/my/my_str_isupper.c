/*
** EPITECH PROJECT, 2018
** task13
** File description:
** return 1 0
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return (1);
    while (str[i] != '\0' && (str[i] >= 'A' && str[i] <= 'Z')) {
        i++;
        if (str[i] == '\0')
            return (1);
    }
    return (0);

}
