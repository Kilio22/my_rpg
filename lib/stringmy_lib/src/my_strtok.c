/*
** EPITECH PROJECT, 2019
** stringmy
** File description:
** mg_strtok
*/

#include "mg_str.h"

void remove_both_caracter(char **src, char to_remove)
{
    char *buff = mg_strdup(*src);
    int pos_start = 0;
    int pos_end = mg_strlen(buff) - 1;

    while (buff[pos_start] == to_remove && buff[pos_start] != '\0')
        pos_start++;
    if (pos_start == pos_end)
        return;
    while (buff[pos_end] == to_remove)
        pos_end--;
    free(*src);
    *src = mg_strndup(buff + pos_start, pos_end - pos_start + 1);
    free(buff);
}

static int tok_len(char *str, char *tok)
{
    int i = 0;
    int c = 0;
    int s_tok = mg_strlen(tok);

    while (str[i] != '\0') {
        if (mg_strncmp(str + i, tok, s_tok)) {
            i += mg_strlen(tok);
            c++;
        }
        while (mg_strncmp(str + i, tok, s_tok) == 1)
            i += s_tok;
        if (str[i] == '\0')
            return ((mg_strncmp(str + i - s_tok, tok, s_tok) ? c : c + 1));
        i++;
    }
    return ((mg_strncmp(str + i - s_tok, tok, s_tok)) ? c : c + 1);
}

static int tok_len_substring(char *str, char *tok)
{
    int i = 0;

    while (str[i] != '\0' && mg_strncmp(str + i, tok, mg_strlen(tok)) == 0)
        i++;
    return (i);
}

void mg_strtok_destroy(char **str_arr)
{
    int i = 0;

    while (str_arr[i]) {
        free(str_arr[i]);
        i++;
    }
    free(str_arr);
}

char **mg_strtok(char *str, char *tok)
{
    int len = tok_len(str, tok);
    char **buff = malloc(sizeof(char *) * (len + 1));
    int size;
    int j = 0;

    if (buff == NULL)
        return (NULL);
    for (int i = 0; i < len; i++) {
        size = tok_len_substring(str + j, tok);
        buff[i] = mg_strndup(str + j, size);
        if (buff[i] == NULL) {
            mg_strtok_destroy(buff);
            return (NULL);
        }
        j += size + 1;
    }
    buff[len] = NULL;
    return (buff);
}