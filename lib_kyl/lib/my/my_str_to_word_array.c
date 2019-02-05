/*
** EPITECH PROJECT, 2018
** task04
** File description:
** transform a string into words
*/

#include <stdlib.h>

int char_valid(char m)
{
    if (m != ' ' && m != '\t')
        return (1);
    else
        return (0);
}

int nb_char_par_mots(char const *str, int mot_voulut)
{
    int i = 0;
    int space_before = 1;
    int nb_words = 0;
    int nb_lettres = 0;

    while (str[i] != '\0') {
        if (char_valid(str[i]) == 0)
            space_before = 1;
        if (space_before == 1 && char_valid(str[i]) == 1) {
                space_before = 0;
                nb_words++;
        }
        if (char_valid(str[i]) == 1 && mot_voulut == nb_words) {
            nb_lettres++;
    }
        i++;
    }
    return (nb_lettres);
}

char put_char(char const *str, int mot_voulut, int char_voulut)
{
    int i = 0;
    int space = 1;
    int nb_words = 0;
    int nb_lettres = 0;

    while (str[i] != '\0') {
        if (char_valid(str[i]) == 0)
            space = 1;
        if (space == 1 && char_valid(str[i]) == 1) {
            space = 0;
            nb_words++;
        }
        if (char_valid(str[i]) == 1 && mot_voulut == nb_words) {
            nb_lettres++;
        }
        if (nb_lettres == char_voulut)
            return (str[i]);
        i++;
    }
    return ('\0');
}

int nb_mots(char const *str)
{
    int i = 0;
    int space_before = 1;
    int nb_words = 0;

    while (str[i] != '\0') {
        if (char_valid(str[i]) == 0)
            space_before = 1;
        if (space_before == 1 && char_valid(str[i]) == 1) {
            space_before = 0;
            nb_words++;
        }
        i++;
    }
    return (nb_words);
}

char **my_str_to_word_array(char const *str)
{
    int i = 1;
    int g = 1;
    char **my_array = malloc(sizeof(char *) * (nb_mots(str) + 1));

    while (g - 1 < nb_mots(str)) {
        my_array[g - 1] = malloc(sizeof(char) *
(nb_char_par_mots(str, g) + 1));
        while (i - 1 < nb_char_par_mots(str, g)) {
            my_array[g - 1][i - 1] = put_char(str, g, i);
            i++;
        }
        my_array[g - 1][i - 1] = '\0';
        i = 1;
        g++;
    }
    my_array[g - 1] = 0;
    return (my_array);
}
