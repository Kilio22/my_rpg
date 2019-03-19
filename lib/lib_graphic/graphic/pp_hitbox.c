/*
** EPITECH PROJECT, 2019
** test
** File description:
** pp_hitbox
*/

#include <SFML/Graphics.h>
#include "pp_hitbox.h"

sfIntRect f_to_i_rect(sfFloatRect f)
{
    sfIntRect i = {f.left, f.top, f.width, f.height};
    return (i);
}

sfBool pp_check(pp_t pp_hitbox, const sfUint8* pixA, const sfUint8* pixB)
{
    for (int x = pp_hitbox.intersect.left; x < pp_hitbox.xMax; x++)
    	for (int y = pp_hitbox.intersect.top; y < pp_hitbox.yMax; y++) {
            pp_hitbox.vecA = sfTransform_transformPoint(
                &pp_hitbox.inverseA, (sfVector2f){x, y});
            pp_hitbox.vecB = sfTransform_transformPoint(
                &pp_hitbox.inverseB, (sfVector2f){x, y});
            pp_hitbox.idxA = (pp_hitbox.vecA.x +
            pp_hitbox.vecA.y * pp_hitbox.sizeA.x) * 4 + 3;
            pp_hitbox.idxB = (pp_hitbox.vecB.x +
            pp_hitbox.vecB.y * pp_hitbox.sizeB.x) * 4 + 3;
            if (pp_hitbox.vecA.x >= 0 && pp_hitbox.vecA.y >= 0 &&
pp_hitbox.vecB.x >= 0 && pp_hitbox.vecB.y >= 0 &&
pp_hitbox.vecA.x < pp_hitbox.sizeA.x && pp_hitbox.vecA.y < pp_hitbox.sizeA.y &&
pp_hitbox.vecB.x < pp_hitbox.sizeB.x && pp_hitbox.vecB.y < pp_hitbox.sizeB.y &&
pixA[pp_hitbox.idxA] > 0 && pixB[pp_hitbox.idxB] > 0)
                return (sfTrue);
        }
    return (sfFalse);
}

sfBool pp_intersect(const sfSprite *a, const sfSprite *b,
const sfImage *imgA, const sfImage *imgB)
{
    pp_t pp_hitbox;
    sfIntRect rectA = f_to_i_rect(sfSprite_getGlobalBounds(a));
    sfIntRect rectB = f_to_i_rect(sfSprite_getGlobalBounds(b));
    const sfUint8* pixA = sfImage_getPixelsPtr(imgA);
    const sfUint8* pixB = sfImage_getPixelsPtr(imgB);

    if (sfIntRect_intersects(&rectA, &rectB, &pp_hitbox.intersect) == 0)
        return (sfFalse);
    pp_hitbox.inverseA = sfSprite_getInverseTransform(a);
    pp_hitbox.inverseB = sfSprite_getInverseTransform(b);
    pp_hitbox.sizeA = sfImage_getSize(imgA);
    pp_hitbox.sizeB = sfImage_getSize(imgB);
    pp_hitbox.xMax = pp_hitbox.intersect.left + pp_hitbox.intersect.width;
    pp_hitbox.yMax = pp_hitbox.intersect.top + pp_hitbox.intersect.height;
    if (pp_check(pp_hitbox, pixA, pixB) == 1)
        return (sfTrue);
    else
        return (sfFalse);
}