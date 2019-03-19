/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** graphic
*/

#ifndef GRAPHIC_H_
#define GRAPHIC_H_
#include "SFML/Graphics.h"

sfIntRect f_to_i_rect(sfFloatRect f);
sfRenderWindow *create_window(char *title, float scale);
void animation(sfIntRect *rect, int start, int offset, int max_value);
sfBool pp_intersect(const sfSprite *a, const sfSprite *b,
const sfImage *imgA, const sfImage *imgB);

#endif /* !GRAPHIC_H_ */
