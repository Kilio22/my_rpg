/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_end_game
*/

#include "rpg.h"

static void destroy_end(end_game_t *end)
{
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(end->back));
    sfSprite_destroy(end->back);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(end->parch));
    sfSprite_destroy(end->parch);
    sfFont_destroy((sfFont *)sfText_getFont(end->text));
    sfText_destroy(end->text);
    sfRectangleShape_destroy(end->rect);
}

end_game_t init_end_game(rpg_t *rpg)
{
    end_game_t end;
    const sfView *default_view = sfRenderWindow_getDefaultView(WIND.wind);
    sfTexture *texture = sfTexture_create(1280, 720);
    sfTexture *parch_l = sfTexture_createFromFile("assets/parchemin.png", NULL);

    sfTexture_updateFromRenderWindow(texture, WIND.wind, 0, 0);
    sfRenderWindow_setView(WIND.wind, default_view);
    end.back = sfSprite_create();
    sfSprite_setTexture(end.back, texture, sfTrue);
    end.text = create_text(menu_font, " ", 30, V2F(110, 580));
    end.parch = sfSprite_create();
    sfSprite_setTexture(end.parch, parch_l, sfTrue);
    sfSprite_setPosition(end.parch, V2F(90, 558));
    end.end_status = 0;
    end.language = GAME.language;
    end.rect = create_rect(V2F(0, 0), V2F(1280, 720));
    sfRectangleShape_setOutlineColor(end.rect, sfTransparent);
    return end;
}

static void display_end(end_game_t *end, rpg_t *rpg)
{
    sfRenderWindow_clear(WIND.wind, sfBlack);
    sfRenderWindow_drawSprite(WIND.wind, end->back, NULL);
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

    fight_text_intro(0);
    update_rect_end(&end, 1);
    while (sfRenderWindow_isOpen(WIND.wind)) {
        update_time(&frames);
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            n_val += end_game_event(rpg);
        if (n_val > 0 || MENU.menu_on == 0) {
            destroy_end(&end);
            return;
        }
        display_end(&end, rpg);
    }
    sfRenderWindow_setView(WIND.wind, view_backup);
}

void check_end_game(rpg_t *rpg)
{
    if (rpg->killed[0] == 1 && rpg->killed[1] == 1 && rpg->killed[2] == 1)
        avengers_end_game(rpg);
}