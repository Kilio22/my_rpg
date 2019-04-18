/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu
*/

#include "rpg.h"

static void update_rectangle(rpg_t *rpg, int *move, float frame)
{
    sfVector2f pos = sfRectangleShape_getPosition(MENU.rect);
    sfVector2f text_pos = sfText_getPosition(MENU.buttons[MENU.highlight].text);

    if (pos.y == text_pos.y) {
        *move = -1;
        return;
    }
    if (*move == -1)
        return;
    for (int i = 0; i < frame; i++) {
        if (pos.y < text_pos.y)
            pos.y += 10;
        else
            pos.y -= 10;
    }
    sfRectangleShape_setPosition(MENU.rect, pos);
}

static int update_text_inex(int *index, rpg_t *rpg, char **to_print, int *p_ind)
{
    if (*index != MENU.highlight) {
        *index = MENU.highlight;
        *p_ind = 0;
        free(*to_print);
        *to_print = my_strdup("");
    }
    if (my_strlen(*to_print) == 0) {
        *to_print = malloc(sizeof(char) * (my_strlen(menu_desc[*index]) + 1));
        if (*to_print == NULL)
            return -1;
    }
    return 0;
}

static int update_text(rpg_t *rpg, size_t frames)
{
    static int print_index = 0;
    static int index = 0;
    static char *to_print = NULL;

    if (index != MENU.highlight) {
        index = MENU.highlight;
        print_index = 0;
        free(to_print);
        to_print = my_strdup("");
    }
    if (my_strlen(to_print) == 0)
        to_print = malloc(sizeof(char) * (my_strlen(menu_desc[index]) + 1));
    for (size_t i = 0; (i < frames || i <= 1) &&
print_index < my_strlen(menu_desc[index]); i++) {
        to_print[print_index] = menu_desc[index][print_index];
        print_index++;
        to_print[print_index] = '\0';
    }
    sfText_setString(MENU.descr_text, to_print);
    return 0;
}

static void display_menu(rpg_t *rpg)
{
    if (!sfRenderWindow_isOpen(WIND.wind))
        return;
    sfRenderWindow_drawSprite(WIND.wind, MENU.menu_sprite[BACK], NULL);
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawText(WIND.wind, MENU.buttons[i].text, NULL);
    sfRenderWindow_drawRectangleShape(WIND.wind, MENU.rect, NULL);
    sfRenderWindow_drawText(WIND.wind, MENU.descr_text, NULL);
    sfRenderWindow_setView(WIND.wind, WIND.view);
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

void menu_loop(rpg_t *rpg, obj_t **obj, house_t **house)
{
    int move_rect = -1;
    sfTime old_time = {0};
    sfTime current_time = {0};
    size_t frames;

    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            menu_event_management(rpg, obj, house, &move_rect);
        current_time = sfClock_getElapsedTime(MENU.clock);
        frames =
sfTime_asMicroseconds(current_time) - sfTime_asMicroseconds(old_time);
        frames /= 1000 / 60;
        frames /= 1000;
        old_time.microseconds = current_time.microseconds;
        update_rectangle(rpg, &move_rect, frames);
        if (update_text(rpg, frames) == -1) {
            sfRenderWindow_close(WIND.wind);
            rpg->error_code = 84;
        }
        display_menu(rpg);
    }
}
