/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** text_intro
*/

#include "rpg.h"

int fight_text_intro(int i)
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

int fight_text_index(int index, char **to_print, int flag, int *p_ind)
{
    if (my_strlen(*to_print) == 0) {
        *to_print = malloc(sizeof(char) *
(my_strlen(ennemi_text[index]) + 1));
        if (*to_print == NULL)
            return -1;
    }
    if (flag == 1) {
        free(*to_print);
        *to_print = NULL;
        *p_ind = 0;
        return -1;
    }
    return 0;
}

int update_fight_text(size_t frames, fight_t *fight, int flag)
{
    static int print_index = 0;
    static char *to_print = NULL;

    if (fight_text_index(fight->nb_fight, &to_print, flag, &print_index) == -1)
        return -1;
    for (size_t i = 0; (i < frames || i <= 1) &&
print_index < my_strlen(ennemi_text[fight->nb_fight]); i++) {
        to_print[print_index] = ennemi_text[fight->nb_fight][print_index];
        print_index++;
        to_print[print_index] = '\0';
    }
    sfText_setString(fight->text, to_print);
    if (my_strlen(to_print) == my_strlen(ennemi_text[fight->nb_fight])
&& fight_text_intro(1) == 1) {
        fight->old_i++;
        fight->quest_status++;
    }
    return 0;
}