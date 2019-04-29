/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create_fight
*/

#include "my.h"
#include "rpg.h"

void positioning_life_perso(fight_t *new, rpg_t *rpg)
{
    char *str = my_strdup("ALLIES : ");
    sfVector2f v1 = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){100, 0}, WIND.view);
    sfVector2f v2 = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){900, 0}, WIND.view);

    str = my_realloc_str(str, my_int_to_char(new->life[0]));
    sfText_setCharacterSize(new->attacks[3], 30);
    sfText_setCharacterSize(new->attacks[4], 30);
    sfText_setString(new->attacks[3], str);
    str = my_strdup("ENNEMI : ");
    str = my_realloc_str(str, my_int_to_char(new->life[1]));
    sfText_setString(new->attacks[4], str);
    sfText_setPosition(new->attacks[3], v1);
    sfText_setPosition(new->attacks[4], v2);
}

static void init_fight_var(int i, sfVector2f vect, obj_t **obj, fight_t *new)
{
    new->text = create_text(menu_font, " ", 19, V2F(0, 0));
    new->nb_fight = i;
    new->old_i = i;
    new->text_index = i;
    new->win = 0;
    new->fondu = create_rect(vect, (sfVector2f){1280, 720});
    sfRectangleShape_setOutlineColor(new->fondu, sfTransparent);
    new->quest_status = 0;
    new->old_pos[0] = sfSprite_getPosition(obj[HERO_HB]->sprite);
    new->old_pos[1] = sfSprite_getPosition(obj[2]->sprite);
    new->old_pos[2] = sfSprite_getPosition(obj[3]->sprite);
    new->old_pos[3] = sfSprite_getPosition(obj[new->nb_fight + 6]->sprite);
    //new->life[0] = obj[0]->stats[HPS] + obj[2]->stats[HPS] + obj[3]->stats[HPS];
    new->life[0] = 10;
    new->life[1] = 100;
    new->turn = 0;
    new->fight_status = 0;
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
    for (int i = 0; i < 5; i++) {
        new.attacks[i] = create_text(menu_font,
attaques_names[0][i], 19, V2F(0, 0));
        update_attacks_pos(&new, rpg, i);
    }
    update_attacks_pos(&new, rpg, -1);
    positioning_life_perso(&new, rpg);
    sfText_setColor(new.attacks[0], sfBlue);
    new.high = 0;
    return new;
}