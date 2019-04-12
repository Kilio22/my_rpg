/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_draw_stock
*/

#include "inventory.h"

void inventory_draw_stock(inventory_t *inv)
{
    int x;
    int y;
    sfVector2f pos;

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inv->stock[i] != NULL) {
            x = i % INVENTORY_SIZE_X;
            y = i / INVENTORY_SIZE_X;
            pos.x = 432 + (70 * x);
            pos.y = 20 + (y * 20);
            inv->stock[i]->display->pos = pos;
            sfRenderWindow_drawDragndrop(inv->window, inv->stock[i]->display);
        }
    }
}

static int is_collision_mouse(sfVector2i mouse, sfVector2f box)
{
    if (mouse.x > box.x && mouse.x < box.x + 50) {
        if (mouse.y > box.y && mouse.y < box.y + 50)
            return (1);
    }
    return (0);
}

static int compute_coords_to_stuff(sfVector2i pos)
{
    for (int i = 0; i < 6; i++) {
        if (is_collision_mouse(pos, stuff_grid[i]))
            return (i);
    }
    return (-1);
}

static void treat_pending_drag_stock(inventory_t *inv, item_t *dragged)
{
    sfVector2i pos = dragndrop_getpendingDrag(dragged->display);
    int i = compute_coords_to_stuff(pos);

    if (i != -1)
        inventory_swap_to_stuff(inv, inv->item_dragging, i);
    inv->item_dragging = NULL;
    inv->item_pos = NOTHING;
}

void inventory_event_stock(inventory_t *inv)
{
    if (inv->item_pos == STUFF)
        return;
    if (inv->item_dragging &&
        dragndrop_ispendingDrag(inv->item_dragging->display))
        treat_pending_drag_stock(inv, inv->item_dragging);
    if (inv->item_dragging != NULL) {
        dragndrop_event(inv->item_dragging->display, inv->window);
        return;
    }
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inv->stock[i] == NULL)
            continue;
        dragndrop_event(inv->stock[i]->display, inv->window);
        if (dragndrop_isUnderDragging(inv->stock[i]->display)) {
            inv->item_pos = STOCK;
            inv->item_dragging = inv->stock[i];
            return;
        }
    }
}