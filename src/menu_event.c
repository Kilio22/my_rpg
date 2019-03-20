/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu_event
*/

#include "rpg.h"

void menu_event_management(rpg_t *rpg, obj_t **obj, house_t **house)
{
    if (WIND.event.type == sfEvtKeyPressed) {
        if (WIND.event.key.code == sfKeyEscape)
            sfRenderWindow_close(WIND.wind);
        if (WIND.event.key.code == sfKeyF1)
            GAME.nb_save = 0;
        if (WIND.event.key.code == sfKeyF2)
            GAME.nb_save = 1;
        if (WIND.event.key.code == sfKeyF3)
            init_game(rpg, obj, house);
        // if (WIND.event.key.code == sfKeyF5)
        //     set_music(game);
    }
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
    if (WIND.event.type == sfEvtMouseMoved) {
        WIND.mouse_pos.x = WIND.event.mouseMove.x;
        WIND.mouse_pos.y = WIND.event.mouseMove.y;
    }
    // if (WIND.event.type == sfEvtMouseButtonPressed)
    //     if (WIND.event.mouseButton.button == sfMouseLeft)
    //         WIND.click = 1;
}