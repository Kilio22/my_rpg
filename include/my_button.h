/*
** EPITECH PROJECT, 2019
** mygraphlib
** File description:
** my_button
*/

#ifndef MY_BUTTON_H_
#define MY_BUTTON_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int my_bool_t;

enum {IDLE_BT, HOVER_BT, CLICKED_BT};

struct my_button {
    sfSprite *sprites[3];
    sfVector2f pos;
    sfVector2f scale;
    my_bool_t hover_released;
    my_bool_t click_released;
};
typedef struct my_button my_button_t;

// buttons mem
my_button_t *my_button_create(sfTexture *idle, sfTexture *hover,
                            sfTexture *clicked);
void my_button_destroy(my_button_t *button);
void sfRenderWindow_drawButton(sfRenderWindow *window, my_button_t *button);

// button events
my_bool_t my_button_is_hover(my_button_t *button, sfRenderWindow *relative);
my_bool_t my_button_is_clicked(my_button_t *button, sfRenderWindow *relative);
my_bool_t my_button_is_hoverOnce(my_button_t *button, sfRenderWindow *rel);
my_bool_t my_button_is_clickedOnce(my_button_t *button, sfRenderWindow *rel);

#endif /* !MY_BUTTON_H_ */
