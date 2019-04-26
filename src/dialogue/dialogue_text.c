/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** dialogue_text
*/

#include "rpg.h"

static int set_string(int *print_index, char **oui,
dialogue_t *dialogue, int *ind)
{
    if (*print_index == my_strlen(answers[dialogue->nb_pnj][*ind])
&& clock_text_intro(1) == 1) {
        dialogue->quest_status_d = -1;
        *ind = -1;
        sfText_setString(dialogue->text[0], welcome[dialogue->nb_pnj]);
        return 0;
    } else {
        sfText_setString(dialogue->text[0], *oui);
        if (*print_index != my_strlen(answers[dialogue->nb_pnj][*ind]))
            clock_text_intro(0);
    }
    return 0;
}

static int dial_text_index(int *index, dialogue_t *dialogue,
char **oui, int *p_ind)
{
    if (dialogue == NULL) {
        *p_ind = 0;
        free(*oui);
        *oui = my_strdup("");
        *index = 0;
        return -1;
    }
    if (*index != dialogue->quest_status_d) {
        *index = dialogue->quest_status_d;
        *p_ind = 0;
        free(*oui);
        *oui = my_strdup("");
    }
    if (my_strlen(*oui) == 0) {
        *oui = malloc(sizeof(char) *
(my_strlen(answers[dialogue->nb_pnj][*index]) + 1));
        if (*oui == NULL)
            return -1;
    }
    return 0;
}

int update_dial_text(size_t frames, dialogue_t *dialogue)
{
    static int print_index = 0;
    static int ind = 0;
    static char *oui = NULL;

    if (dial_text_index(&ind, dialogue, &oui, &print_index) == -1)
        return -1;
    for (size_t i = 0; (i < frames || i <= 1) &&
print_index < my_strlen(answers[dialogue->nb_pnj][ind]); i++) {
        oui[print_index] = answers[dialogue->nb_pnj][ind][print_index];
        print_index++;
        oui[print_index] = '\0';
    }
    return set_string(&print_index, &oui, dialogue, &ind);
}