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

void update_attacks_pos(fight_t *new, rpg_t *rpg, int i)
{
    sfVector2f vect = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 558}, WIND.view);;
    sfVector2f vect_text;
    static sfVector2f offset = {0, 0};

    if (i == -1) {
        offset = V2F(0, 0);
        return;
    }
    vect.y += 15;
    vect.x += 80;
    vect_text = vect;
    offset.y += (offset.x == 540 ? 40 : 0);
    offset.x = (offset.x == 540 ? 0 : offset.x);
    vect_text = (sfVector2f){vect_text.x + offset.x, vect_text.y + offset.y};
    sfText_setPosition(new->attacks[i], vect_text);
    offset.x += 180;
    vect.y -= 15;
    vect.x -= 20;
    sfSprite_setPosition(new->parch, vect);
}