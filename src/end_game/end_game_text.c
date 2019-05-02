/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** end_game_text
*/

#include "rpg.h"

static int end_text_index(char **to_print, int *p_ind,
int *index, end_game_t *end)
{
    if (*index != end->end_status) {
        *index = end->end_status;
        *p_ind = 0;
        free(*to_print);
        *to_print = my_strdup("");
    }
    if (my_strlen(*to_print) == 0) {
        *to_print = malloc(sizeof(char) *
(my_strlen(end_text[end->language][end->end_status]) + 1));
        if (*to_print == NULL)
            return -1;
    }
    if (end == NULL) {
        free(*to_print);
        *to_print = NULL;
        *p_ind = 0;
        return -1;
    }
    return 0;
}

int update_end_text(end_game_t *end)
{
    static int print_index = 0;
    static int index = 0;
    static char *print = NULL;

    if (end->end_status > 1)
        return 0;
    if (end_text_index(&print, &print_index, &index, end) == -1)
        return -1;
    for (size_t i = 0; (i < update_time(NULL) || i <= 1)
&& print_index < my_strlen(ENDTXT); i++) {
        print[print_index] = ENDTXT[print_index];
        print_index++;
        print[print_index] = '\0';
    }
    sfText_setString(end->text, print);
    if (fight_text_intro(1) == 1 && my_strlen(print) == my_strlen(ENDTXT2))
        end->end_status++;
    if (my_strlen(print) != my_strlen(ENDTXT))
        fight_text_intro(0);
    return 0;
}