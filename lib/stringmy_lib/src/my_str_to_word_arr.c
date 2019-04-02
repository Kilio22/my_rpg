/*
** EPITECH PROJECT, 2019
** str to word arr
** File description:
** str to word arr
*/

#include "my_str.h"

static int my_count_words(char const *str)
{
    int i = 0;
    int counter = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
            i++;
        if (str[i] == '\0')
            break;
        counter++;
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
            i++;
    }
    return (counter);
}

static int my_word_lenght(char const *s)
{
    int i = 0;

    while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
        i++;
    return (i);
}

word_arr_t *my_str_to_word_arr(char const *str)
{
    word_arr_t *arr = malloc(sizeof(word_arr_t));
    int j = 0;

    arr->nb_word = my_count_words(str);
    arr->arr = malloc(sizeof(char *) * arr->nb_word);
    for (int i = 0; i < arr->nb_word; i++) {
        while (str[j] == ' ' || str[j] == '\t')
            j++;
        arr->arr[i] = my_strndup(str + j, my_word_lenght(str + j));
        j += my_word_lenght(str + j);
    }
    return (arr);
}

void word_arr_destroy(word_arr_t *arr)
{
    for (int i = 0; i < arr->nb_word; i++)
        free(arr->arr[i]);
    free(arr->arr);
    free(arr);
}
