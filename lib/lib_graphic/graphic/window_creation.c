/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** window_creation
*/

#include <SFML/Graphics.h>

sfRenderWindow *create_window(char *title, float scale)
{
    sfVideoMode mode = {128 * scale, 72 * scale, 32};
    sfRenderWindow *wind = sfRenderWindow_create(
    mode, title, 5, NULL);
    sfRenderWindow_setVerticalSyncEnabled(wind, sfTrue);
    sfRenderWindow_setFramerateLimit(wind, 60);
    sfRenderWindow_setPosition(wind, (sfVector2i){0, 0});
    sfRenderWindow_setMouseCursorGrabbed(wind, sfFalse);
    return (wind);
}