/*
** EPITECH PROJECT, 2019
** mg_strcut_to_word_array
** File description:
** turn a char * into a char **
*/

#include "mg_str.h"

int nb_space2(char *src, char *cutmod)
{
    int nb = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        for (int j = 0; cutmod[j] != '\0'; j++) {
            nb = (src[i] == cutmod[j] || src[i] == '\n') ? nb + 1 : nb;
        }
    }
    return (nb);
}

int word_size2(char *src, char *cutmod)
{
    int nb = 0;

    for (int i = 0; src[i] != '\0' && src[i] != '\n'; i++) {
        for (int j = 0; cutmod[j]; j++)
            if (src[i] == cutmod[j])
                return (nb);
        nb++;
    }
    return (nb);
}

char **mg_strcut_to_word_array(char *src, char *cutmod)
{
    int nbword = nb_space2(src, cutmod) + 1;
    char **dest = malloc(sizeof(char *) * (nbword + 1));
    int wordlen = 0;
    int cursor = 0;

    for (int i = 0; i < nbword; i++) {
        wordlen = word_size2(&src[cursor], cutmod);
        dest[i] = mg_strndup(&src[cursor], wordlen);
        cursor += wordlen + 1;
    }
    dest[nbword] = NULL;
    return (dest);
}
