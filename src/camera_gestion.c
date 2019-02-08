/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** camera_gestion
*/

#include "struct.h"

void zoom_gestion(wind_t *wind, controls_t *control)
{
    if (control->bools[ZOOM] == 1) {
        sfView_zoom(wind->view, 0.9);
        control->bools[ZOOM] = 0;
    }
    if (control->bools[DEZOOM] == 1) {
        sfView_zoom(wind->view, 1.1);
        control->bools[DEZOOM] = 0;
    }
}

void camera_control(wind_t *wind, controls_t *control, sfVector2f pos)
{
    zoom_gestion(wind, control);
    if (control->bools[KEYY] == 0)
        sfView_setCenter(wind->view, pos);
    else {
        if (control->bools[KEYRIGHT] == 1)
            sfView_move(wind->view, (sfVector2f){10, 0});
        if (control->bools[KEYLEFT] == 1)
            sfView_move(wind->view, (sfVector2f){-10, 0});
        if (control->bools[KEYDOWN] == 1)
            sfView_move(wind->view, (sfVector2f){0, 10});
        if (control->bools[KEYUP] == 1)
            sfView_move(wind->view, (sfVector2f){0, -10});
    }
}