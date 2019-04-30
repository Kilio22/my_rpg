/*
** EPITECH PROJECT, 2019
** mygraphlib
** File description:
** my_drandrop
*/

#ifndef MY_DRANDROP_H_
#define MY_DRANDROP_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>

#ifndef BOOL
#define BOOL
typedef int my_bool_t;
#define TRUE 1
#define FALSE 0
#endif

enum {IDLE_DRAG, DRAGGED};

struct dragndrop {
    sfSprite *state_img[2];
    sfSprite *drag_img;

    sfVector2f pos;
    sfVector2f scale_bt;
    sfVector2f scale_dragged;
    sfVector2i last_pos_released;
    int state;
};
typedef struct dragndrop dragndrop_t;

// mem
dragndrop_t *dragndrop_create(sfTexture *idle, sfTexture *dragged,
sfTexture *img_dragged);
void dragndrop_destroy(dragndrop_t *drag);
void window_draw_dragndrop(sfRenderWindow *window, dragndrop_t *drag);

// event
my_bool_t dragndrop_is_clicked(dragndrop_t *drag, sfRenderWindow *window);
my_bool_t dragndrop_is_hover(dragndrop_t *drag, sfRenderWindow *window);
my_bool_t dragndrop_isunderdragging(dragndrop_t *drag);
void dragndrop_event(dragndrop_t *drag, sfRenderWindow *window);

// accessor
my_bool_t dragndrop_ispendingdrag(dragndrop_t *drag);
sfVector2i dragndrop_getpendingdrag(dragndrop_t *drag);
void dragndrop_set_size(dragndrop_t *drag, int x, int y);

#endif /* !MY_DRANDROP_H_ */
