/*
** EPITECH PROJECT, 2018
** alloc_animated
** File description:
** alloc animated
*/

#include "my_animated_sprite.h"

animated_sprite_t *animated_sprite_create(sfTexture const *texture, int nb,
                                sfIntRect const *coords, float timer_anim)
{
    animated_sprite_t *animated = malloc(sizeof(animated_sprite_t));

    animated->sprites = malloc(sizeof(sfSprite*) * nb);
    for (int i = 0; i < nb; i++){
        animated->sprites[i] = sfSprite_create();
        sfSprite_setTexture(animated->sprites[i], texture, sfFalse);
        sfSprite_setTextureRect(animated->sprites[i], coords[i]);
    }
    animated->nb_texture = nb;
    animated->counter = 0;
    animated->pos = (sfVector2f){0, 0};
    animated->scale = (sfVector2f){1, 1};
    animated->timer_anim = timer_anim;
    animated->clock_anim = sfClock_create();
    return (animated);
}

void animated_sprite_destroy(animated_sprite_t *animated)
{
    for (int i = 0; i < animated->nb_texture; i++){
        free(animated->sprites[i]);
    }
    sfClock_destroy(animated->clock_anim);
    free(animated);
}

void animated_sprite_next_texture(animated_sprite_t *animated)
{
    animated->counter++;
    if (animated->counter == animated->nb_texture)
        animated->counter = 0;
}

void animated_sprite_show(animated_sprite_t *animated, sfRenderWindow *window)
{
    int counter = animated->counter;

    sfSprite_setPosition(animated->sprites[counter], animated->pos);
    sfSprite_setScale(animated->sprites[counter], animated->scale);
    sfRenderWindow_drawSprite(window, animated->sprites[counter], NULL);
}

void animated_sprite_do_anim(animated_sprite_t *animated)
{
    sfTime time = sfClock_getElapsedTime(animated->clock_anim);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > animated->timer_anim) {
        animated_sprite_next_texture(animated);
        sfClock_restart(animated->clock_anim);
    }
}