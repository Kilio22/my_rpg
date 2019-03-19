/*
** EPITECH PROJECT, 2019
** test
** File description:
** pp_hitbox
*/

#ifndef PP_HITBOX_H_
#define PP_HITBOX_H_

#include <SFML/Graphics.h>

typedef struct pp_s {
    sfIntRect intersect;
    sfTransform inverseA;
    sfTransform inverseB;
    sfVector2u sizeA;
    sfVector2u sizeB;
    sfVector2f vecA;
    sfVector2f vecB;
    int xMax;
    int yMax;
    int idxA;
    int idxB;
} pp_t;

#endif /* !PP_HITBOX_H_ */