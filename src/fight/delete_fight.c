/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** delete_fight
*/

#include "inventory.h"
#include "rpg.h"

static void add_item(rpg_t *rpg, fight_t *fight, obj_t **obj)
{
    item_t *item;
    ini_file_t *ini = ini_file_create_from_file("assets_data.ini");
    int j = 0;

    if (fight->nb_fight == 1)
        item = item_create(8, ini);
    else if (fight->nb_fight == 0)
        item = item_create(11, ini);
    else
        item = item_create(12, ini);
    inventory_add_item(GAME.inv, item);
    for (int i = 0; i < 4; i++) {
        if (i == 1)
            continue;
        obj[i]->stats[HPS] += level_up[fight->nb_fight][j][0];
        obj[i]->stats[ATK] += level_up[fight->nb_fight][j][1];
        obj[i]->stats[DEF] += level_up[fight->nb_fight][j][2];
        obj[i]->stats[SPEED] += level_up[fight->nb_fight][j][3];
        j++;
    }
}

static void reinit_pos(obj_t **obj, fight_t *fight, rpg_t *rpg)
{
    if (fight->win == 2) {
        sfSprite_setPosition(obj[fight->nb_fight + 6]->sprite,
fight->old_pos[3]);
        obj[fight->nb_fight + 6]->pos =
sfSprite_getPosition(obj[fight->nb_fight + 6]->sprite);
    } else if (fight->win == 1) {
        free_obj(obj[fight->nb_fight + 6]);
        obj[fight->nb_fight + 6] = NULL;
        rpg->killed[fight->nb_fight] = 1;
        add_item(rpg, fight, obj);
        rpg->killed[fight->nb_fight] = 1;
    } else {
        sfSprite_setPosition(obj[HERO_HB]->sprite, fight->old_pos[0]);
        sfSprite_setPosition(obj[2]->sprite, fight->old_pos[1]);
        sfSprite_setPosition(obj[3]->sprite, fight->old_pos[2]);
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        sfSprite_setPosition(obj[fight->nb_fight + 6]->sprite,
fight->old_pos[3]);
        obj[fight->nb_fight + 6]->pos =
sfSprite_getPosition(obj[fight->nb_fight + 6]->sprite);
    }
}

void delete_fight(fight_t *fight, obj_t **obj, rpg_t *rpg)
{
    sfRectangleShape_destroy(fight->fondu);
    sfFont_destroy((sfFont *)sfText_getFont(fight->text));
    sfText_destroy(fight->text);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(fight->parch));
    sfSprite_destroy(fight->parch);
    update_fondu_rect_fight(fight, rpg, 1);
    update_fight_text(fight, 1, rpg);
    reinit_pos(obj, fight, rpg);
    for (int i = 0; i < 5; i++) {
        sfFont_destroy((sfFont *)sfText_getFont(fight->attacks[i]));
        sfText_destroy(fight->attacks[i]);
    }
    choose_fighter(NULL, NULL, NULL, 0);
    fight_turn(NULL, NULL, 1);
}