/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight_updates
*/

#include "rpg.h"

static void check_updates(fight_t *fight, int *alpha)
{
    if (fight->quest_status == 1 && clock_text_intro(0) == 1) {
        sfRectangleShape_setFillColor(fight->fondu, (sfColor){0, 0, 0, *alpha});
        if (*alpha < 255)
            *alpha += 5;
        else
            fight->quest_status++;
    }
    if (fight->quest_status == 2 && clock_text_intro(0) == 1) {
        sfRectangleShape_setFillColor(fight->fondu, (sfColor){0, 0, 0, *alpha});
        if (*alpha > 0)
            *alpha -= 5;
        else
            fight->quest_status++;
    }
}

void update_fondu_rect_fight(fight_t *fight, rpg_t *rpg, int flag)
{
    static int alpha = 0;
    sfVector2f vect = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 0}, WIND.view);

    if (flag == 1) {
        alpha = 0;
        return;
    }
    sfRectangleShape_setPosition(fight->fondu, vect);
    check_updates(fight, &alpha);
    sfRenderWindow_drawRectangleShape(WIND.wind, fight->fondu, NULL);
}