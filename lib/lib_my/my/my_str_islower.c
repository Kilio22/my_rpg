/*
** EPITECH PROJECT, 2018
** task12
** File description:
** return 1 if there are only lowecase return 0 if not
*/

int my_str_islower(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;
    while (str[i] != '\0' && (str[i] >= 'a' && str[i] <= 'z')) {
        i++;
        if (str[i] == '\0')
            return 1;
    }
    return 0;

}
