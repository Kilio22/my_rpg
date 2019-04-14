/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_stuff
*/

#include "inventory.h"

void inventory_draw_stuff(inventory_t *inv)
{
    dragndrop_t *drag;

    for (int i = 0; i < 6; i++) {
        if (!inv->stuff[i])
            continue;
        drag = inv->stuff[i]->display;
        drag->pos = stuff_grid[i];
        sfRenderWindow_drawDragndrop(inv->window, drag);
    }
}

static int compute_coords_from_stuff(item_t *item)
{
    sfVector2f pos1 = item->display->pos;
    sfVector2f pos2;

    for (int i = 0; i < 6; i++) {
        pos2 = stuff_grid[i];
        if (pos2.x == pos1.x && pos2.y == pos1.y)
            return (i);
    }
    return (-1);
}

static void treat_pending_drag_stuff(inventory_t *inv, item_t *item)
{
    int i = compute_coords_from_stuff(inv->item_dragging);
    
    inventory_swap_to_stock(inv, i);
    inv->item_pos = NOTHING;
    inv->item_dragging = NULL;
}

void inventory_event_stuff(inventory_t *inv)
{
    if (inv->item_pos == STOCK)
        return;
    if (inv->item_dragging &&
    dragndrop_ispendingDrag(inv->item_dragging->display))
        treat_pending_drag_stuff(inv, inv->item_dragging);
    if (inv->item_dragging != NULL) {
        dragndrop_event(inv->item_dragging->display, inv->window);
        return;
    }
    for (int i = 0; i < 6; i++) {
        if (!inv->stuff[i])
            continue;
        dragndrop_event(inv->stuff[i]->display, inv->window);
        if (dragndrop_isUnderDragging(inv->stuff[i]->display)) {
            inv->item_dragging = inv->stuff[i];
            inv->item_pos = STUFF;
        }
    }
}