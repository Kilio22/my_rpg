/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_end_game
*/

#include "rpg.h"

static void destroy_end(end_game_t *end, rpg_t *rpg)
{
    if (end->end_status == 4)
        menu_credit(rpg, NULL, NULL);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(end->back));
    sfSprite_destroy(end->back);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(end->parch));
    sfSprite_destroy(end->parch);
    sfFont_destroy((sfFont *)sfText_getFont(end->text));
    sfText_destroy(end->text);
    sfRectangleShape_destroy(end->rect);
}

static void display_end(end_game_t *end, rpg_t *rpg)
{
    sfRenderWindow_clear(WIND.wind, sfBlack);
    if (end->end_status < 3)
        sfRenderWindow_drawSprite(WIND.wind, end->back, NULL);
    else
        sfRenderWindow_drawSprite(WIND.wind, end->o_back, NULL);
    if (end->end_status < 2) {
        sfRenderWindow_drawSprite(WIND.wind, end->parch, NULL);
        sfRenderWindow_drawText(WIND.wind, end->text, NULL);
    }
    sfRenderWindow_drawRectangleShape(WIND.wind, end->rect, NULL);
    sfRenderWindow_display(WIND.wind);
    update_end_text(end);
    update_rect_end(end, 0);
}

static void avengers_end_game(rpg_t *rpg)
{
    const sfView *view_backup = sfRenderWindow_getView(WIND.wind);
    end_game_t end = init_end_game(rpg);
    size_t frames = 0;
    int n_val = 0;

    while (sfRenderWindow_isOpen(WIND.wind)) {
        rpg->frame = update_time(&frames);
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            n_val += end_game_event(rpg);
        if (n_val > 0 || MENU.menu_on == 0 || end.end_status == 4) {
            destroy_end(&end, rpg);
            return;
        }
        display_end(&end, rpg);
    }
    sfRenderWindow_setView(WIND.wind, view_backup);
}

void check_end_game(rpg_t *rpg, int flag)
{
    static int i = 0;

    if (flag == 1) {
        i = 0;
        return;
    }
    if (rpg->killed[0] == 1 && rpg->killed[1] == 1
&& rpg->killed[2] == 1 && i == 0) {
        avengers_end_game(rpg);
        i++;
    }
}