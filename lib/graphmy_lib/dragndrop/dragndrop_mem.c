/*
** EPITECH PROJECT, 2019
** mygraphlib
** File description:
** dragndrop_mem
*/

#include "my_dragndrop.h"

dragndrop_t *dragndrop_create(sfTexture *idle, sfTexture *dragged,
sfTexture *img_dragged)
{
    dragndrop_t *drag = malloc(sizeof(dragndrop_t));

    drag->state_img[0] = sfSprite_create();
    drag->state_img[1] = sfSprite_create();
    drag->drag_img = sfSprite_create();
    sfSprite_setTexture(drag->state_img[0], idle, sfTrue);
    sfSprite_setTexture(drag->state_img[1], dragged, sfTrue);
    sfSprite_setTexture(drag->drag_img, img_dragged, sfTrue);
    drag->pos = (sfVector2f){0, 0};
    drag->scale_bt = (sfVector2f){1, 1};
    drag->scale_dragged = (sfVector2f){1, 1};
    drag->state = IDLE_DRAG;
    drag->last_pos_released = (sfVector2i){-1, -1};
    return (drag);
}

void dragndrop_destroy(dragndrop_t *drag)
{
    sfSprite_destroy(drag->state_img[0]);
    sfSprite_destroy(drag->state_img[1]);
    sfSprite_destroy(drag->drag_img);
    free(drag);
}

void sfRenderWindow_drawDragndrop(sfRenderWindow *window, dragndrop_t *drag)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_f = (sfVector2f){pos.x, pos.y};

    for (int i = 0; i < 2; i++) {
        sfSprite_setScale(drag->state_img[i], drag->scale_bt);
        sfSprite_setPosition(drag->state_img[i], drag->pos);
    }
    if (drag->state == IDLE_DRAG)
        sfRenderWindow_drawSprite(window, drag->state_img[0], NULL);
    else {
        sfRenderWindow_drawSprite(window, drag->state_img[DRAGGED], NULL);
        sfSprite_setScale(drag->drag_img, drag->scale_dragged);
        sfSprite_setPosition(drag->drag_img, pos_f);
        sfRenderWindow_drawSprite(window, drag->drag_img, NULL);
    }
}