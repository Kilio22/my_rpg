/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** framebuffer
*/

#include "rpg.h"

static framebuffer_t *framebuffer_create(unsigned int width,
unsigned int height)
{
    framebuffer_t *frame = malloc(sizeof(framebuffer_t));

    frame->width = width;
    frame->height = height;
    frame->array = malloc(sizeof(sfUint8) * width * height * 4);
    return (frame);
}

static int clock_framebufer(void)
{
    static sfClock *clock = NULL;
    sfTime time;
    float seconds;

    if (!clock)
        clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 0.70) {
        sfClock_restart(clock);
        return 1;
    }
    return 0;
}

void display_framebuffer(rpg_t *rpg)
{
    if (clock_framebufer() == 1) {
        draw_square_fog(GAME.fog, V2U(1U, 1U), 54);
        draw_square_fire(GAME.fire, V2U(1U, 1U), 15);
    }
    sfTexture_updateFromPixels(GAME.fog->text, GAME.fog->array,
GAME.fog->width, GAME.fog->height, 0, 0);
    sfSprite_setTexture(GAME.fog->sprite, GAME.fog->text, sfFalse);
    sfSprite_setPosition(GAME.fog->sprite, (sfVector2f){10180, 1296});
    sfRenderWindow_drawSprite(WIND.wind, GAME.fog->sprite, NULL);
    sfTexture_updateFromPixels(GAME.fire->text, GAME.fire->array,
GAME.fire->width, GAME.fire->height, 0, 0);
    sfSprite_setTexture(GAME.fire->sprite, GAME.fire->text, sfFalse);
    sfSprite_setPosition(GAME.fire->sprite, (sfVector2f){10185, 1393});
    sfRenderWindow_drawSprite(WIND.wind, GAME.fire->sprite, NULL);
}

void create_framebuffer(rpg_t *rpg)
{
    sfVector2u pos;

    GAME.fog = framebuffer_create(55U, 55U);
    GAME.fire = framebuffer_create(16U, 16U);
    pos.x = 1U;
    pos.y = 1U;
    draw_square_fog(GAME.fog, pos, 54);
    draw_square_fire(GAME.fire, pos, 15);
    GAME.fog->text = sfTexture_create(GAME.fog->width, GAME.fog->height);
    GAME.fog->sprite = sfSprite_create();
    GAME.fire->text = sfTexture_create(GAME.fire->width, GAME.fire->height);
    GAME.fire->sprite = sfSprite_create();
}