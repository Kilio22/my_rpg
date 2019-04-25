/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create_fight
*/

#include "rpg.h"

static void positioning_life_perso(fight_t *new, rpg_t *rpg)
{
    sfVector2f v1 = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 0}, WIND.view);
    sfVector2f v2 = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){1100, 0}, WIND.view);

    sfText_setCharacterSize(new->attacks[5], 25);
    sfText_setCharacterSize(new->attacks[6], 25);
    sfText_setPosition(new->attacks[5], v1);
    sfText_setPosition(new->attacks[6], v2);
    new->life[0] = 100;
    new->life[1] = 100;
}

static void init_fight_var(int i, sfVector2f vect, obj_t **obj, fight_t *new)
{
    new->text = create_text(MENU_FONT, " ", 19, V2F(0, 0));
    new->nb_fight = i;
    new->old_i = i;
    new->fondu = create_rect(vect, (sfVector2f){1280, 720});
    new->quest_status = 0;
    new->old_pos[0] = sfSprite_getPosition(obj[HERO_HB]->sprite);
    new->old_pos[1] = sfSprite_getPosition(obj[2]->sprite);
    new->old_pos[2] = sfSprite_getPosition(obj[3]->sprite);
    new->old_pos[3] = sfSprite_getPosition(obj[new->nb_fight + 6]->sprite);
}

fight_t create_fight(int i, rpg_t *rpg, obj_t **obj)
{
    fight_t new;
    sfVector2f vect = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 0}, WIND.view);
    sfTexture *texture = sfTexture_createFromFile("assets/parchemin.png", NULL);

    new.parch = sfSprite_create();
    sfSprite_setTexture(new.parch, texture, sfTrue);
    sfSprite_setScale(new.parch, V2F(0.6, 0.6));
    init_fight_var(i, vect, obj, &new);
    for (int i = 0; i < 7; i++) {
        new.attacks[i] = create_text(MENU_FONT,
attaques_names[i], 19, V2F(0, 0));
        update_attacks_pos(&new, rpg, i);
    }
    sfText_setColor(new.attacks[0], sfBlue);
    update_attacks_pos(&new, rpg, -1);
    positioning_life_perso(&new, rpg);
    new.high = 0;
    return new;
}