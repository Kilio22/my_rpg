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
    if (fight->quest_status > 3) {
        sfRenderWindow_drawSprite(WIND.wind, fight->parch, NULL);
        for (int i = 0; i < 5; i++)
            sfRenderWindow_drawText(WIND.wind, fight->attacks[i], NULL);
    }
    sfRenderWindow_drawRectangleShape(WIND.wind, fight->fondu, NULL);
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

static void create_attacks_pos(fight_t *new, rpg_t *rpg, int i)
{
    sfVector2f vect = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 558}, WIND.view);;
    sfVector2f vect_text;
    static int offsetx = 0;
    static int offsety = 0;

    if (i == -1) {
        offsetx = 0;
        offsety = 0;
        return;
    }
    vect.y += 15;
    vect.x += 80;
    vect_text = vect;
    offsety += (offsetx == 450 ? 20 : 0);
    offsetx = (offsetx == 450 ? 0 : offsetx);
    vect_text = (sfVector2f){vect_text.x + offsetx, vect_text.y + offsety};
    sfText_setPosition(new->attacks[i], vect_text);
    offsetx += 150;
    vect.y -= 15;
    vect.x -= 20;
    sfSprite_setPosition(new->parch, vect);
}

static fight_t create_fight(int i, rpg_t *rpg, obj_t **obj)
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
    new.old_pos = sfSprite_getPosition(obj[HERO_HB]->sprite);
    for (int i = 0; i < 5; i++) {
        new.attacks[i] = create_text(MENU_FONT, attaques_names[i], 15, V2F(0, 0));
        create_attacks_pos(&new, rpg, i);
    }
    sfText_setColor(new.attacks[0], sfYellow);
    new.high = 0;
    return new;
}

static void delete_fight(fight_t *fight, obj_t **obj, rpg_t *rpg)
{
    sfRectangleShape_destroy(fight->fondu);
    sfFont_destroy((sfFont *)sfText_getFont(fight->text));
    sfText_destroy(fight->text);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(fight->parch));
    sfSprite_destroy(fight->parch);
    update_fondu_rect_fight(fight, rpg, 1);
    update_fight_text(1, fight, 1);
    sfSprite_setPosition(obj[HERO_HB]->sprite, fight->old_pos);
    sfSprite_setPosition(obj[1]->sprite,
sfSprite_getPosition(obj[HERO_HB]->sprite));
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