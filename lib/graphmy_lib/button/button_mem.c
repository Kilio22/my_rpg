/*
** EPITECH PROJECT, 2019
** mygraphlib
** File description:
** button
*/

#include "my_button.h"

my_button_t *my_button_create(sfTexture *idle, sfTexture *hover,
                            sfTexture *clicked)
{
    my_button_t *new = malloc(sizeof(my_button_t));

    for (int i = 0; i < 3; i++)
        new->sprites[i] = sfSprite_create();
    sfSprite_setTexture(new->sprites[IDLE_BT], idle, sfTrue);
    sfSprite_setTexture(new->sprites[HOVER_BT], hover, sfTrue);
    sfSprite_setTexture(new->sprites[CLICKED_BT], clicked, sfTrue);
    new->hover_released = FALSE;
    new->click_released = FALSE;
    new->pos = (sfVector2f){0, 0};
    new->scale = (sfVector2f){1, 1};
    for (int i = 0; i < 3; i++) {
        sfSprite_setPosition(new->sprites[i], new->pos);
        sfSprite_setScale(new->sprites[i], new->scale);
    }
    return (new);
}

void my_button_destroy(my_button_t *button)
{
    for (int i = 0; i < 3; i++)
        sfSprite_destroy(button->sprites[i]);
    free(button);
}

void window_draw_button(sfRenderWindow *window, my_button_t *button)
{
    for (int i = 0; i < 3; i++) {
        sfSprite_setPosition(button->sprites[i], button->pos);
        sfSprite_setScale(button->sprites[i], button->scale);
    }
    if (my_button_is_clicked(button, window)) {
        sfRenderWindow_drawSprite(window, button->sprites[CLICKED_BT], NULL);
    }
    else if (my_button_is_hover(button, window)) {
        button->click_released = FALSE;
        sfRenderWindow_drawSprite(window, button->sprites[HOVER_BT], NULL);
    } else {
        button->click_released = FALSE;
        button->click_released = FALSE;
        sfRenderWindow_drawSprite(window, button->sprites[IDLE_BT], NULL);
    }
}