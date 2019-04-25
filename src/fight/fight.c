/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight
*/

#include "rpg.h"

static void text_display_fight(rpg_t *rpg, fight_t *fight)
{
    if (fight->old_i == fight->nb_fight) {
        sfRenderWindow_drawSprite(WIND.wind, fight->parch, NULL);
        sfRenderWindow_drawText(WIND.wind, fight->text, NULL);
    }
    if (fight->quest_status > 2) {
        sfRenderWindow_drawSprite(WIND.wind, fight->parch, NULL);
        for (int i = 0; i < 5; i++)
            sfRenderWindow_drawText(WIND.wind, fight->attacks[i], NULL);
    }
}

static void fight_display(rpg_t *rpg, obj_t **obj,
house_t **house, fight_t *fight)
{
    if (MENU.menu_on == 2)
        return;
    sfRenderWindow_setView(WIND.wind, WIND.view);
    print_map(MAP.sprite, obj, rpg->wind);
    house_display(rpg, house);
    check_obj_display(obj, rpg);
    print_map2(MAP.sprite, obj, rpg->wind);
    text_display_fight(rpg, fight);
    sfRenderWindow_drawRectangleShape(WIND.wind, fight->fondu, NULL);
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

void fight(obj_t **obj, rpg_t *rpg, int i, house_t **house)
{
    fight_t fight = create_fight(i, rpg, obj);
    int ret_val = 0;

    sfClock_restart(obj[1]->clock);
    fight_text_intro(0);
    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            ret_val += fight_event_management(rpg, &fight);
        if (ret_val > 0) {
            delete_fight(&fight, obj, rpg);
            return;
        }
        fight_action(rpg, obj, house, &fight);
        fight_display(rpg, obj, house, &fight);
    }
}