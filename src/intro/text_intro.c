/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** text_intro
*/

#include "rpg.h"

static int intro_text_index(int *index, rpg_t *rpg, char **to_print, int *p_ind)
{
    if (*index != MENU.highlight) {
        *index = MENU.highlight;
        *p_ind = 0;
        free(*to_print);
        *to_print = NULL;
    }
    if (*to_print == NULL) {
        *to_print = malloc(sizeof(char) * (my_strlen(menu_desc[*index]) + 1));
        if (*to_print == NULL)
            return -1;
    }
    return 0;
}

int update_intro_text(rpg_t *rpg, size_t frames)
{
    static int print_index = 0;
    static int index = 0;
    static char *to_print = NULL;

    if (update_text_inex(&index, rpg, &to_print, &print_index) == -1)
        return -1;
    for (size_t i = 0; i < frames &&
print_index < my_strlen(menu_desc[index]); i++) {
        to_print[print_index] = menu_desc[index][print_index];
        print_index++;
        to_print[print_index] = '\0';
    }
    sfText_setString(MENU.descr_text, to_print);
    return 0;
}