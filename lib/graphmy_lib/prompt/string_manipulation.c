/*
** EPITECH PROJECT, 2019
** mygraphlib
** File description:
** string_manipulation
*/

#include "my_prompt.h"

void my_prompt_str_pop(my_prompt_t *prompt)
{
    int size;
    char *new;

    if (mg_strlen(prompt->to_display) == 0)
        return;
    size = mg_strlen(prompt->to_display) - 1;
    new = mg_strndup(prompt->to_display, size);
    free(prompt->to_display);
    prompt->to_display = new;
}

void my_prompt_str_push(my_prompt_t *prompt, char c)
{
    int size = mg_strlen(prompt->to_display) + 1;
    char *new = malloc(sizeof(char) * (size + 1));

    mg_strcpy(new, prompt->to_display);
    new[size - 1] = c;
    new[size] = '\0';
    free(prompt->to_display);
    prompt->to_display = new;
}