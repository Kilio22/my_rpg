/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight
*/

#include "rpg.h"

static void fight_display(rpg_t *rpg, obj_t **obj,
house_t **house, fight_t *fight)
{
    if (MENU.menu_on == 2)
        return;
    print_map(MAP.sprite, obj, rpg->wind);
    house_display(rpg, house);
    for (int i = 10; i > 0; i--)
        if (obj[i] != NULL && i != 4)
            sfRenderWindow_drawSprite(WIND.wind, obj[i]->sprite, NULL);
    print_map2(MAP.sprite, obj, rpg->wind);
    if (fight->old_i == fight->nb_fight) {
        sfRenderWindow_drawSprite(WIND.wind, fight->parch, NULL);
        sfRenderWindow_drawText(WIND.wind, fight->text, NULL);
    }
    sfRenderWindow_drawRectangleShape(WIND.wind, fight->fondu, NULL);
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

static fight_t create_fight(int i, rpg_t *rpg)
{
    fight_t new;
    sfVector2f vect = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 0}, WIND.view);
    sfTexture *texture = sfTexture_createFromFile("assets/parchemin.png", NULL);

    new.parch = sfSprite_create();
    sfSprite_setTexture(new.parch, texture, sfTrue);
    sfSprite_setScale(new.parch, V2F(0.6, 0.6));
    new.text = create_text(MENU_FONT, " ", 19, V2F(0, 0));
    new.nb_fight = i;
    new.old_i = i;
    new.fondu = create_rect(vect, (sfVector2f){1280, 720});
    new.quest_status = 0;
    return new;
}

void fight(obj_t **obj, rpg_t *rpg, int i, house_t **house)
{
    fight_t fight = create_fight(i, rpg);
    int ret_val = 0;

    sfClock_restart(obj[1]->clock);
    fight_text_intro(0);
    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            ret_val += fight_event_management(rpg);
        if (ret_val > 0) {
            sfRectangleShape_destroy(fight.fondu);
            sfText_destroy(fight.text);
            sfSprite_destroy(fight.parch);
            update_fondu_rect_fight(&fight, rpg, 1);
            update_fight_text(1, &fight, 1);
            return;
        }
        fight_action(rpg, obj, house, &fight);
        fight_display(rpg, obj, house, &fight);
    }
}