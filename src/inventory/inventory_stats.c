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
    sfText_setCharacterSize(t, 52);
    sfRenderWindow_drawText(inv->window, t, NULL);
    sfText_destroy(t);
}

static char *get_name(int state)
{
    if (state == 0)
        return mg_strdup(" Jean");
    else if (state == 1)
        return mg_strdup("Nathan");
    else
        return mg_strdup("Jacques");
    return NULL;
}

static void inventory_draw_stats_speed(inventory_t *inv, char **buff)
{
    char *buff2 = mg_itoa(inv->stats[inv->state][2]);

    buff2 = mg_itoa(inv->stats[inv->state][2]);
    mg_strcat(buff, buff2);
    free(buff2);
    mg_strcat(buff, "\n    ");
    buff2 = mg_itoa(inv->stats[inv->state][3]);
    mg_strcat(buff, buff2);
    free(buff2);
    draw_text(inv, (*buff), (sfVector2f){80, 345});
    free((*buff));
}

void inventory_draw_stats(inventory_t *inv)
{
    char *buff = get_name(inv->state);
    char *buff2 = mg_itoa(inv->stats[inv->state][0] +
compute_health_stat(inv, inv->state));

    mg_strcat(&buff, "\n    ");
    mg_strcat(&buff, buff2);
    free(buff2);
    mg_strcat(&buff, "\n    ");
    buff2 = mg_itoa(inv->stats[inv->state][1] +
compute_attack_stat(inv, inv->state));
    mg_strcat(&buff, buff2);
    free(buff2);
    mg_strcat(&buff, "\n    ");
    inventory_draw_stats_speed(inv, &buff);
}