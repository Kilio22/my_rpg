/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** pause
*/

#include "rpg.h"

static int manage_mouse_ppress(rpg_t *rpg, pause_t *pause)
{
    int i = check_mousepos_intersect(rpg, pause->field, 3);

    if (i == -1)
        return 0;
    if (i == 0)
        return 1;
    if (i == 1) {
        MENU.menu_on = 0;
        return 1;
    }
    if (i == 2) {
        sfRenderWindow_close(WIND.wind);
        return 1;
    }
    return 0;
}

static void manage_mouse_pause(rpg_t *rpg, pause_t *pause)
{
    int i = check_mousepos_intersect(rpg, pause->field, 3);

    if (i == -1) {
        sfText_setColor(pause->field[pause->high].text, sfRed);
        return;
    }
    sfText_setColor(pause->field[pause->high].text, sfRed);
    pause->high = i;
    sfText_setColor(pause->field[pause->high].text, sfBlue);
}

static int pause_events(rpg_t *rpg, pause_t *pause)
{
    if (WIND.event.type == sfEvtKeyPressed &&
WIND.event.key.code == sfKeyEscape)
        return 1;
    if (WIND.event.type == sfEvtClosed) {
        sfRenderWindow_close(WIND.wind);
        return 1;
    }
    if (WIND.event.type == sfEvtMouseMoved) {
        WIND.mouse_pos.x = WIND.event.mouseMove.x;
        WIND.mouse_pos.y = WIND.event.mouseMove.y;
        manage_mouse_pause(rpg, pause);
    }
    if (WIND.event.type == sfEvtMouseButtonPressed)
        return manage_mouse_ppress(rpg, pause);
    return 0;
}

static pause_t create_pause(rpg_t *rpg)
{
    pause_t new;
    const sfView *default_view;
    sfTexture *t = sfTexture_create(1280, 720);

    sfTexture_updateFromRenderWindow(t, WIND.wind, 0, 0);
    default_view = sfRenderWindow_getDefaultView(WIND.wind);
    sfRenderWindow_setView(WIND.wind, default_view);
    new.back = sfSprite_create();
    sfSprite_setTexture(new.back, t, sfTrue);
    new.rect = create_rect(V2F(0, 0), V2F(1280, 720));
    sfRectangleShape_setOutlineColor(new.rect, sfTransparent);
    sfRectangleShape_setFillColor(new.rect, (sfColor){0, 0, 0, 100});
    new.high = 0;
    for (int i = 0; i < 3; i++) {
        new.field[i].text = create_text(menu_font,
pause_str[GAME.language][i], 60, vect_pause[GAME.language][i]);
        new.field[i].status = 0;
    }
    return new;
}

void pause_game(rpg_t *rpg)
{
    const sfView *view_backup = sfRenderWindow_getView(WIND.wind);
    int n_val = 0;
    pause_t pause = create_pause(rpg);
    size_t frames;

    while (sfRenderWindow_isOpen(WIND.wind)) {
        update_time(&frames);
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            n_val += pause_events(rpg, &pause);
        if (n_val == 1)
            return;
        sfRenderWindow_drawSprite(WIND.wind, pause.back, NULL);
        sfRenderWindow_drawRectangleShape(WIND.wind, pause.rect, NULL);
        for (int i = 0; i < 3; i++)
            sfRenderWindow_drawText(WIND.wind, pause.field[i].text, NULL);
        sfRenderWindow_display(WIND.wind);
        sfRenderWindow_clear(WIND.wind, sfBlack);
    }
    sfRenderWindow_setView(WIND.wind, view_backup);
}