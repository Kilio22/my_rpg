/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight_updates
*/

#include "rpg.h"

static void check_updates(fight_t *fight, int *alpha)
{
    if ((fight->quest_status == 1 || fight->quest_status == 4)
&& clock_text_intro(0) == 1) {
        sfRectangleShape_setFillColor(fight->fondu, (sfColor){0, 0, 0, *alpha});
        if (*alpha < 255)
            *alpha += 5;
        else
            fight->quest_status++;
    }
    if ((fight->quest_status == 2 || fight->quest_status == 7)
&& clock_text_intro(0) == 1) {
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

static void check_end_pos_lose(fight_t *fight,
obj_t **obj, rpg_t *rpg)
{
    if (fight->quest_status == 6 && fight->win == 2) {
        sfSprite_move(obj[0]->sprite, V2F(2, 0));
        sfSprite_move(obj[2]->sprite, V2F(2, 0));
        sfSprite_move(obj[3]->sprite, V2F(2, 0));
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        GAME.follower = init_list(obj[0]->pos.x - 50, obj[0]->pos.y);
        GAME.follower2 = init_list(obj[0]->pos.x - 100, obj[0]->pos.y);
        fight->quest_status++;
    }
    if (fight->quest_status == 5 && fight->win == 1) {
        sfSprite_setPosition(obj[HERO_HB]->sprite, fight->old_pos[0]);
        sfSprite_setPosition(obj[2]->sprite, fight->old_pos[1]);
        sfSprite_setPosition(obj[3]->sprite, fight->old_pos[2]);
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        fight->quest_status += 2;
    }
}

void check_end_pos(fight_t *fight, obj_t **obj, house_t **house, rpg_t *rpg)
{
    if (fight->quest_status == 5 && fight->life[0] == 0 && fight->win == 2) {
        sfSprite_setPosition(obj[0]->sprite, V2F(10048, 1472));
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        sfSprite_setPosition(obj[2]->sprite, V2F(9998, 1472));
        sfSprite_setPosition(obj[3]->sprite, V2F(9948, 1472));
        house[0]->display_house = 0;
        fight->quest_status++;
        return;
    }
    check_end_pos_lose(fight, obj, rpg);
}

void update_attacks_pos(fight_t *new, rpg_t *rpg, int i)
{
    sfVector2f vect = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 558}, WIND.view);
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