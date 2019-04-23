/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight
*/

#include "rpg.h"

static void fight_display(rpg_t *rpg, obj_t **obj, house_t **house, fight_t *fight)
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
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

static fight_t create_fight(int i)
{
    fight_t new;
    sfTexture *texture = sfTexture_createFromFile("assets/parchemin.png", NULL);

    new.parch = sfSprite_create();
    sfSprite_setTexture(new.parch, texture, sfTrue);
    sfSprite_setScale(new.parch, V2F(0.6, 0.6));
    new.text = create_text(MENU_FONT, " ", 19, V2F(0, 0));
    new.nb_fight = i;
    new.old_i = i;
    return new;
}

void fight(obj_t **obj, rpg_t *rpg, int i, house_t **house)
{
    fight_t fight = create_fight(i);

    sfClock_restart(obj[1]->clock);
    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            fight_event_management(rpg);
        if (MENU.menu_on == 0 || MENU.menu_on == 2)
            return;
        fight_action(rpg, obj, house, &fight);
        fight_display(rpg, obj, house, &fight);
    }
}