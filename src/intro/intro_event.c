/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro_event
*/

#include "rpg.h"

static void check_updates(rpg_t *rpg, intro_t *intro, int *alpha)
{
    if ((rpg->quest_status == 2 || rpg->quest_status == 12
|| rpg->quest_status == 23) && clock_text_intro(0) == 1) {
        sfRectangleShape_setFillColor(intro->fondu, (sfColor){0, 0, 0, *alpha});
        if (*alpha < 255)
            *alpha += 5;
        else
            rpg->quest_status++;
    }
    if ((rpg->quest_status == 3 || rpg->quest_status == 13
|| rpg->quest_status == 24) && clock_text_intro(0) == 1) {
        sfRectangleShape_setFillColor(intro->fondu, (sfColor){0, 0, 0, *alpha});
        if (*alpha > 0)
            *alpha -= 5;
        else
            rpg->quest_status++;
    }
}

void update_fondu_rect(intro_t *intro, rpg_t *rpg)
{
    static int alpha = 0;
    sfVector2f oui = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 0}, WIND.view);

    sfRectangleShape_setPosition(intro->fondu, oui);
    check_updates(rpg, intro, &alpha);
    sfRenderWindow_drawRectangleShape(WIND.wind, intro->fondu, NULL);
}

void intro_event_management(rpg_t *rpg, obj_t **obj, house_t **house)
{
    if (WIND.event.type == sfEvtMouseMoved) {
        CONTROLS.mousePos.x = WIND.event.mouseMove.x;
        CONTROLS.mousePos.y = WIND.event.mouseMove.y;
    }
    if (WIND.event.type == sfEvtKeyPressed) {
        if (WIND.event.key.code == sfKeyF12)
            screenshot(rpg);
        if (WIND.event.key.code == sfKeyF5)
            set_music(GAME.back_music);
        if (WIND.event.key.code == sfKeyEscape)
            pause_game(rpg);
        if (WIND.event.key.code == sfKeyF6) {
            reset_char(obj, rpg, house);
            rpg->quest_status = 26;
            MENU.menu_on = 2;
        }
    }
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
}