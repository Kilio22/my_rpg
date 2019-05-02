/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** credits_event
*/

#include "rpg.h"

int check_credit_events(rpg_t *rpg)
{
    int ret_val = 0;

    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
    if (WIND.event.type == sfEvtKeyPressed) {
        if (WIND.event.key.code == sfKeyF5)
            set_music(rpg);
        if (WIND.event.key.code == sfKeyEscape)
            return 1;
    }
    return ret_val;
}

void credit_display(rpg_t *rpg, credit_t *credit)
{
    sfRenderWindow_clear(WIND.wind, sfBlack);
    sfRenderWindow_setView(WIND.wind, WIND.view);
    sfRenderWindow_drawSprite(WIND.wind, credit->back, NULL);
    sfRenderWindow_drawRectangleShape(WIND.wind, credit->rect, NULL);
    sfRenderWindow_drawSprite(WIND.wind, credit->cred, NULL);
    sfRenderWindow_display(WIND.wind);
}