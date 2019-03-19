/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** animation
*/

#include <SFML/Graphics.h>

void animation(sfIntRect *rect, int start, int offset, int max_value)
{
    if (rect->left >= (max_value - offset))
        rect->left = start;
    else
        rect->left += offset;
}