/*
** EPITECH PROJECT, 2018
** texture
** File description:
** texture
*/

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

struct animated_sprite {
	sfSprite **sprites;
	int counter;
	int nb_texture;
	sfVector2f pos;
	sfVector2f scale;
	sfClock *clock_anim;
	float timer_anim;
};
typedef struct animated_sprite animated_sprite_t;

animated_sprite_t *animated_sprite_create(sfTexture const *texture, int nb, 
								sfIntRect const *coords, float timer_anim);
void animated_sprite_next_texture(animated_sprite_t *animated);
void animated_sprite_destroy(animated_sprite_t *animated);
void animated_sprite_show(animated_sprite_t *animated, sfRenderWindow *window);
void animated_sprite_do_anim(animated_sprite_t *animated);

#endif /* !TEXTURE_H_ */
