/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** aubergiste
*/

#include "rpg.h"

static void text_display_dial(rpg_t *rpg, dialogue_t *dialogue)
{
    sfRenderWindow_drawSprite(WIND.wind, dialogue->parch, NULL);
    if (dialogue->quest_status_d == -1) {
        for (int i = 0; i < 4; i++)
            sfRenderWindow_drawText(WIND.wind, dialogue->text[i], NULL);
    } else {
        sfRenderWindow_drawText(WIND.wind, dialogue->text[0], NULL);
    }
}

static void dial_display(rpg_t *rpg, obj_t **obj,
house_t **house, dialogue_t *dialogue)
{
    if (MENU.menu_on == 2)
        return;
    sfRenderWindow_setView(WIND.wind, WIND.view);
    print_map(MAP.sprite, obj, rpg->wind);
    house_display(rpg, house);
    if (house[1]->display_house == 1)
        display_framebuffer(rpg);
    check_obj_display(obj, rpg);
    print_map2(MAP.sprite, obj, rpg->wind);
    check_pnj_display(house, obj, rpg);
    text_display_dial(rpg, dialogue);
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

void aubergiste_dial(obj_t **obj, rpg_t *rpg, int i, house_t **house)
{
    dialogue_t dialogue = create_dialogue(rpg, i);
    int ret_val = 0;

    sfClock_restart(obj[1]->clock);
    update_dial_text(1, NULL);
    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            ret_val += dial_event_management(rpg, &dialogue);
        if (ret_val > 0) {
            return;
        }
        dial_action(rpg, obj, house, &dialogue);
        dial_display(rpg, obj, house, &dialogue);
    }
    destroy_dialogue(&dialogue);
}