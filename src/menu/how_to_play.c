/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** how_to_play
*/

#include "rpg.h"

static void destroy_htp(sfSprite **sprite)
{
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(*sprite));
    sfSprite_destroy(*sprite);
}

static sfSprite *create_htp(rpg_t *rpg)
{
    sfSprite *new = sfSprite_create();
    sfTexture *texture;

    if (GAME.language == 0)
        texture = sfTexture_createFromFile("assets/how_to_play_fr.png", NULL);
    else
        texture = sfTexture_createFromFile("assets/how_to_play_en.png", NULL);
    sfSprite_setTexture(new, texture, sfTrue);
    sfSprite_setScale(new, V2F(0.67, 0.67));
    return new;
}

static int manage_htp_events(rpg_t *rpg)
{
    if (WIND.event.type == sfEvtClosed) {
        sfRenderWindow_close(WIND.wind);
        return 1;
    }
    if (WIND.event.type == sfEvtKeyPressed &&
WIND.event.key.code == sfKeyEscape)
        return 1;
    return 0;
}

void menu_how_to_play(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfSprite *back = create_htp(rpg);
    int n_val = 0;

    (void)obj;
    (void)house;
    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            n_val += manage_htp_events(rpg);
        if (n_val > 0) {
            destroy_htp(&back);
            return;
        }
        sfRenderWindow_drawSprite(WIND.wind, back, NULL);
        sfRenderWindow_display(WIND.wind);
        sfRenderWindow_clear(WIND.wind, sfBlack);
    }
}