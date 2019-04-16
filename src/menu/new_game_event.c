/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** new_game_event
*/

#include "rpg.h"

/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** event_load_game
*/

#include "rpg.h"

void check_mbutton_press_new(rpg_t *rpg, load_game_t *load, obj_t **obj,
                                                            house_t **house)
{
    int i = check_mousepos_intersect(rpg, load->text, 3);

    if (!sfMouse_isButtonPressed(0))
        return;
    if (i == -1)
        return;
    GAME.nb_save = i;
    //add une réinitialisation du fichier de save choisi
    sfRenderWindow_drawSprite(WIND.wind, MENU.menu_sprite[LOAD], NULL);
    sfRenderWindow_display(WIND.wind);
    GAME.objectiv = 0;
    init_game(rpg, obj, house);
}

int check_button_pressed_new(rpg_t *rpg, load_game_t *load, obj_t **obj,
                                                        house_t **house)
{
    if (WIND.event.key.code == sfKeyEscape)
        return 1;
    if (WIND.event.key.code == sfKeyDown && load->high < 2)
        load->high++;
    if (WIND.event.key.code == sfKeyUp && load->high > 0)
        load->high--;
    for (int i = 0; i < 3; i++)
        sfText_setColor(load->text[i].text, sfRed);
    sfText_setColor(load->text[load->high].text, sfYellow);
    if (WIND.event.key.code == sfKeyReturn) {
        GAME.nb_save = load->high;
        //add une réinitialisation du fichier de save choisi
        sfRenderWindow_drawSprite(WIND.wind, MENU.menu_sprite[LOAD], NULL);
        sfRenderWindow_display(WIND.wind);
        GAME.objectiv = 0;
        init_game(rpg, obj, house);
        return 1;
    }
    return 0;
}

int check_new_game_events(rpg_t *rpg, load_game_t *load, obj_t **obj,
                                                        house_t **house)
{
    int ret_val = 0;

    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
    if (WIND.event.type == sfEvtMouseMoved) {
        WIND.mouse_pos.x = WIND.event.mouseMove.x;
        WIND.mouse_pos.y = WIND.event.mouseMove.y;
        check_move_load(rpg, load);
    }
    if (WIND.event.type == sfEvtKeyPressed)
        ret_val += check_button_pressed_new(rpg, load, obj, house);
    return ret_val;
}