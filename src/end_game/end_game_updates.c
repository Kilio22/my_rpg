/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** end_game_updates
*/

#include "rpg.h"

int end_game_event(rpg_t *rpg)
{
    if (WIND.event.type == sfEvtClosed) {
        sfRenderWindow_close(WIND.wind);
        return 1;
    }
    if (WIND.event.type == sfEvtKeyPressed
&& WIND.event.key.code == sfKeyEscape)
        pause_game(rpg);
    return 0;
}

static void check_updates(end_game_t *end, int *alpha)
{
    if ((end->end_status == 2)
&& clock_text_intro(0) == 1) {
        sfRectangleShape_setFillColor(end->rect, (sfColor){0, 0, 0, *alpha});
        if (*alpha < 255)
            *alpha += 5;
        else
            end->end_status++;
    }
    if ((end->end_status == 3)
&& clock_text_intro(0) == 1) {
        sfRectangleShape_setFillColor(end->rect, (sfColor){0, 0, 0, *alpha});
        if (*alpha > 120)
            *alpha -= 5;
        else
            end->end_status++;
    }
}

void update_rect_end(end_game_t *end, int flag)
{
    static int alpha = 0;

    if (flag == 1) {
        alpha = 0;
        return;
    }
    check_updates(end, &alpha);
}