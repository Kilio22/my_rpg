/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** text_intro
*/

#include "rpg.h"

int clock_text_intro(int i)
{
    static sfClock *clock = NULL;
    sfTime time;
    float seconds;

    if (!clock)
        clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 3 && i == 1) {
        sfClock_restart(clock);
        return 1;
    }
    if (seconds >= 0.1 && i == 0) {
        sfClock_restart(clock);
        return 1;
    }
    return 0;
}

static void update_en(rpg_t *rpg, char **to_print, int index, int *print_index)
{
    for (size_t i = 0; (i < rpg->frame || i <= 1) &&
(*print_index) < my_strlen(scrpits_en[index]); i++) {
        (*to_print)[(*print_index)] = scrpits_en[index][(*print_index)];
        (*print_index)++;
        (*to_print)[(*print_index)] = '\0';
    }
    if ((*print_index) == my_strlen(scrpits_en[index]) &&
(rpg->quest_status < 2 || (rpg->quest_status >= 6 && rpg->quest_status <= 9) ||
(rpg->quest_status >= 13 && rpg->quest_status <= 21))
&& clock_text_intro(1) == 1)
        rpg->quest_status++;
    else if ((*print_index) != my_strlen(scrpits_en[index]))
        clock_text_intro(0);
}

static void update_fr(rpg_t *rpg, char **to_print, int index, int *print_index)
{
    for (size_t i = 0; (i < rpg->frame || i <= 1) &&
(*print_index) < my_strlen(scrpits[index]); i++) {
        (*to_print)[*print_index] = scrpits[index][*print_index];
        (*print_index)++;
        (*to_print)[*print_index] = '\0';
    }
    if ((*print_index) == my_strlen(scrpits[index]) &&
(rpg->quest_status < 2 || (rpg->quest_status >= 6 && rpg->quest_status <= 9) ||
(rpg->quest_status >= 13 && rpg->quest_status <= 21))
&& clock_text_intro(1) == 1)
        rpg->quest_status++;
    else if ((*print_index) != my_strlen(scrpits[index]))
        clock_text_intro(0);
}

int intro_text_index(int *index, rpg_t *rpg, char **to_print, int *p_ind)
{
    if (*index != rpg->quest_status) {
        *index = rpg->quest_status;
        *p_ind = 0;
        free(*to_print);
        *to_print = my_strdup("");
    }
    if (my_strlen(*to_print) == 0) {
        if (GAME.language == 0)
            *to_print = malloc(sizeof(char) *
(my_strlen(scrpits[*index]) + 1));
        else
            *to_print = malloc(sizeof(char) *
(my_strlen(scrpits_en[*index]) + 1));
        if (*to_print == NULL)
            return -1;
    }
    return 0;
}

int update_intro_text(rpg_t *rpg, intro_t *intro)
{
    static int print_index = 0;
    static int index = 0;
    static char *to_print = NULL;

    if (intro_text_index(&index, rpg, &to_print, &print_index) == -1)
        return -1;
    if (GAME.language == 0)
        update_fr(rpg, &to_print, index, &print_index);
    else
        update_en(rpg, &to_print, index, &print_index);
    sfText_setString(intro->text, to_print);
    return 0;
}