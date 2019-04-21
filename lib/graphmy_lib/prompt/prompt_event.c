/*
** EPITECH PROJECT, 2019
** mygraphlib
** File description:
** prompt_event
*/

#include "my_prompt.h"

static my_bool_t my_prompt_is_hover(my_prompt_t *prompt, sfRenderWindow *rel)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(rel);
    sfFloatRect rect = sfSprite_getGlobalBounds(prompt->background);

    if (pos.x > rect.left && pos.x < rect.left + rect.width) {
        if (pos.y > rect.top && pos.y < rect.top + rect.height)
            return (TRUE);
    }
    return (FALSE);
}

void my_prompt_check_focus(my_prompt_t *prompt, sfRenderWindow *window)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (my_prompt_is_hover(prompt, window))
            prompt->focused = 1;
        else
            prompt->focused = 0;
    }
    if (!my_prompt_enter_pressed(prompt))
        prompt->return_released = 1;
}

void my_prompt_check_input(my_prompt_t *prompt, sfEvent event)
{
    char c;

    if (prompt->focused == 1 && event.type == sfEvtTextEntered) {
        c = (char)event.text.unicode;
        if (c >= 32 && c <= 126)
            my_prompt_str_push(prompt, c);
        if (sfKeyboard_isKeyPressed(sfKeyBack)) {
            my_prompt_str_pop(prompt);
        }
    }
}

my_bool_t my_prompt_enter_pressed(my_prompt_t *prompt)
{
    if (prompt->focused == 1 && sfKeyboard_isKeyPressed(sfKeyReturn))
        return (TRUE);
    return (FALSE);
}

my_bool_t my_prompt_enter_pressedOnce(my_prompt_t *prompt)
{
    if (my_prompt_enter_pressed(prompt) && prompt->return_released == 1) {
        prompt->return_released = 0;
        return (TRUE);
    }
    return (FALSE);
}