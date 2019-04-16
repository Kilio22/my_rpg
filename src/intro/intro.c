/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro
*/

#include "rpg.h"

static void mouse_wheel_management(rpg_t *rpg)
{
    if (WIND.event.mouseWheel.delta == 1)
        CONTROLS.bools[ZOOM] = 1;
    else if (WIND.event.mouseWheel.delta == -1)
        CONTROLS.bools[DEZOOM] = 1;
}

static void intro_event_management(rpg_t *rpg)
{
    if (WIND.event.type == sfEvtMouseWheelMoved)
        mouse_wheel_management(rpg);
    if (WIND.event.type == sfEvtMouseMoved) {
        CONTROLS.mousePos.x = WIND.event.mouseMove.x;
        CONTROLS.mousePos.y = WIND.event.mouseMove.y;
    }
    if (WIND.event.type == sfEvtKeyPressed) {
        if (WIND.event.key.code == sfKeyF5)
            set_music(rpg);
        if (WIND.event.key.code == sfKeyEscape)
            MENU.menu_on = 0;
    }
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
}

static void intro_display(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfRenderWindow_setView(WIND.wind, WIND.view);
    print_map(MAP.sprite, obj, rpg->wind);
    house_display(rpg, house);
    for (int i = 10; i > 0; i--)
        if (obj[i] != NULL && i != 4)
            sfRenderWindow_drawSprite(WIND.wind, obj[i]->sprite, NULL);
    print_map2(MAP.sprite, obj, rpg->wind);
    for (int i = 0; house[i] != NULL; i++)
        if (house[i]->display_house == 1)
            sfRenderWindow_drawSprite(WIND.wind, house[i]->tab[ROOF], NULL);
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

void intro_control(obj_t **obj)
{
    static int opt = 0;
    sfVector2f newPos = {0, 0};

    if (opt == 0) {
        if (obj[0]->pos.y > 2076) {
            newPos.y -= 1;
            sfSprite_move(obj[0]->sprite, newPos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    if (opt == 1) {
        if (obj[0]->pos.x > 10194) {
            newPos.x -= 1;
            sfSprite_move(obj[0]->sprite, newPos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    if (opt == 2) {
        if (obj[0]->pos.y > 1900) {
            newPos.y -= 1;
            sfSprite_move(obj[0]->sprite, newPos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
            newPos.y += 2;
            sfSprite_move(obj[5]->sprite, newPos);
            sfSprite_move(obj[6]->sprite, newPos);
            sfSprite_move(obj[7]->sprite, newPos);
        } else
            opt++;
    }
    return;
}

static void intro_action(rpg_t *rpg, obj_t **obj, house_t **house)
{
    if (check_characters_clock(obj[1]->clock, 10000.0) == 0) {
        intro_control(obj);
        all_character_animation(obj);
    }
    sfSprite_setPosition(obj[1]->sprite,
    sfSprite_getPosition(obj[HERO_HB]->sprite));
    house_interaction(obj[HERO_HB], house, rpg);
    camera_control(rpg, obj[HERO_HB]->pos, obj);
    update_all_rect(obj, house);
}

int intro_game(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfVector2u windSize = sfRenderWindow_getSize(WIND.wind);

    sfClock_restart(obj[1]->clock);
    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            intro_event_management(rpg);
        if (MENU.menu_on == 0) {
            MENU.menu_on = 1;
            sfView_destroy(WIND.view);
            WIND.view =
sfView_createFromRect((sfFloatRect){0, 0, windSize.x, windSize.y});
            //free_save(obj, rpg);
            return 0;
        }
        intro_action(rpg, obj, house);
        intro_display(rpg, obj, house);
    }
    return 0;
}