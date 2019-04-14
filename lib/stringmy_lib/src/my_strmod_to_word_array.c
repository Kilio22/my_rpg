/*
** EPITECH PROJECT, 2019
** mg_str_to_word_array
** File description:
** create a str array with a str
*/

#include "mg_str.h"

int nb_space(char *src, char cutmod)
{
    int nb = 0;

    for (int i = 0; src[i] != '\0'; i++)
        nb = (src[i] == cutmod || src[i] == '\n') ? nb + 1 : nb;
    return (nb);
}

int word_size(char *src, char cutmod)
{
    int nb = 0;

    for (int i = 0; src[i] != cutmod && src[i] != '\0' && src[i] != '\n'; i++)
        nb++;
    return (nb);
}

char **mg_strmod_to_word_array(char *src, char cutmod)
{
    int nbword = nb_space(src, cutmod) + 1;
    char **dest = malloc(sizeof(char *) * (nbword + 1));
    int wordlen = 0;
    int cursor = 0;

    for (int i = 0; i < nbword; i++) {
        wordlen = word_size(&src[cursor], cutmod);
        dest[i] = mg_strndup(&src[cursor], wordlen);
        cursor += wordlen + 1;
    }
    dest[nbword] = NULL;
    return (dest);
}
