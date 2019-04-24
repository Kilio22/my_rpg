/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** put_pixel
*/

#include "rpg.h"

static void put_pixel_fog(framebuffer_t *framebuffer, unsigned int x,
unsigned int y)
{
    int pos = rand() % 8;
    sfColor color;

    if (pos == 0)
        color = (sfColor){220, 220, 220, 255};
    if (pos == 1)
        color = (sfColor){169, 169, 169, 255};
    if (pos == 2)
        color = (sfColor){105, 105, 105, 255};
    if (pos >= 3)
        color = (sfColor){0, 0, 0, 0};
    pos = (4 * y * framebuffer->width) - (4 * framebuffer->width);
    pos = pos + ((4 * x) - 4);
    framebuffer->array[pos] = color.r;
    framebuffer->array[pos + 1] = color.g;
    framebuffer->array[pos + 2] = color.b;
    framebuffer->array[pos + 3] = color.a;
}

void draw_square_fog(framebuffer_t *framebuffer, sfVector2u position,
unsigned int line)
{
    for (unsigned int i = 0; i < line; i++) {
        for (int j = fog_off[i][0]; j < fog_off[i][1]; j++) {
            put_pixel_fog(framebuffer, position.x + j, position.y + i);
        }
    }
}

static void put_pixel_fire(framebuffer_t *framebuffer, unsigned int x,
unsigned int y)
{
    int pos = rand() % 4;
    sfColor color;

    if (pos == 0)
        color = (sfColor){254, 27, 0, 255};
    if (pos == 1)
        color = (sfColor){255, 165, 0, 255};
    if (pos >= 2)
        color = (sfColor){0, 0, 0, 0};
    pos = (4 * y * framebuffer->width) - (4 * framebuffer->width);
    pos = pos + ((4 * x) - 4);
    framebuffer->array[pos] = color.r;
    framebuffer->array[pos + 1] = color.g;
    framebuffer->array[pos + 2] = color.b;
    framebuffer->array[pos + 3] = color.a;
}

void draw_square_fire(framebuffer_t *framebuffer, sfVector2u position,
unsigned int line)
{
    for (unsigned int i = 0; i < line; i++) {
        for (unsigned int j = 0; j < line; j++) {
            put_pixel_fire(framebuffer, position.x + j, position.y + i);
        }
    }
}
