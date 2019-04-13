/*
** EPITECH PROJECT, 2018
** task10
** File description:
** return 1 or 0
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;
    while (str[i] != '\0' && ((str[i] >= 'A' && str[i] <= 'Z')
|| (str[i] >= 'a' && str[i] <= 'z'))) {
        i++;
        if (str[i] == '\0')
            return 1;
    }
    return 0;
}
