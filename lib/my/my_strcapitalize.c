/*
** EPITECH PROJECT, 2018
** task09
** File description:
** capitalize each first letters of words in a string
*/

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[0] >= 'a' && str[0] <= 'z') {
            str[0] = str[0] - 32;
        }
        if (str[i] <= ' ' || str[i] == '-' || str[i] == '+') {
            i++;
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 32;
            }
        }
        i++;
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return (str);
}
