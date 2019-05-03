/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_stats
*/

#include "inventory.h"

static void draw_text(inventory_t *inv, char *text, sfVector2f pos)
{
    sfText *t = sfText_create();

    sfText_setFont(t, inv->font);
    sfText_setColor(t, sfBlack);
    sfText_setString(t, text);
    sfText_setPosition(t, pos);
    sfRenderWindow_drawText(inv->window, t, NULL);
    sfText_destroy(t);
}

static int compute_attack_stat(inventory_t *inv)
{
    int attack = 0;

    for (int i = 0; i < 6; i++) {
        if (inv->stuff[inv->state][i] == NULL)
            continue;
        attack += inv->stuff[inv->state][i]->attack;
    }
    return (attack);
}

static int compute_health_stat(inventory_t *inv)
{
    int health = 0;

    for (int i = 0; i < 6; i++) {
        if (inv->stuff[inv->state][i] == NULL)
            continue;
        health += inv->stuff[inv->state][i]->hp;
    }
    return (health);
}

void inventory_draw_stats(inventory_t *inv)
{
    char *buff = mg_strdup("hp: ");
    char *buff2 = mg_itoa(compute_health_stat(inv));

    mg_strcat(&buff, buff2);
    free(buff2);
    mg_strcat(&buff, "\nattack: ");
    buff2 = mg_itoa(compute_attack_stat(inv));
    mg_strcat(&buff, buff2);
    free(buff2);
    draw_text(inv, buff, (sfVector2f){100i, 400});
    free(buff);
}