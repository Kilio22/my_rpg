/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_is_alpha_num
*/

int my_is_alpha_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' && str[i] > '9') || (str[i] > 'Z' && str[i] < 'a') ||
str[i] > 'z' || str[i] < '0')
            return (0);
    }
    return (1);
}