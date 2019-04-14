/*
** EPITECH PROJECT, 2019
** mygraphlib
** File description:
** button_event
*/

#include "my_button.h"

my_bool_t my_button_is_hover(my_button_t *button, sfRenderWindow *relative)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(relative);
    sfFloatRect rect = sfSprite_getGlobalBounds(button->sprites[IDLE_BT]);

    if (pos.x > rect.left && pos.x < rect.left + rect.width) {
        if (pos.y > rect.top && pos.y < rect.top + rect.height)
            return (TRUE);
    }
    return (FALSE);
}

my_bool_t my_button_is_clicked(my_button_t *button, sfRenderWindow *relative)
{
    if (my_button_is_hover(button, relative)) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            return (TRUE);
    }
    return (FALSE);
}

my_bool_t my_button_is_hoverOnce(my_button_t *button, sfRenderWindow *rel)
{
    if (my_button_is_hover(button, rel) && !button->hover_released) {
        button->hover_released = TRUE;
        return (TRUE);
    }
    return (FALSE);
}

my_bool_t my_button_is_clickedOnce(my_button_t *button, sfRenderWindow *rel)
{
    if (my_button_is_clicked(button, rel) && !button->click_released) {
        button->click_released = TRUE;
        return (TRUE);
    }
    return (FALSE);
}