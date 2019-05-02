/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** screenshot
*/

#ifdef _WIN32
    #define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include "rpg.h"

static char *get_name(void)
{
    FILE *stream;
    char *name;
    int i = 1;

    name = my_strncat("screenshot", my_itoa(i, ""), -1);
    name = my_strncat(name, ".png", -1);
    stream = fopen(name, "r");
    while (stream != NULL) {
        fclose(stream);
        free(name);
        i++;
        name = my_strncat("screenshot", my_itoa(i, ""), -1);
        name = my_strncat(name, ".png", -1);
        stream = fopen(name, "r");
    }
    return name;
}

void screenshot(rpg_t *rpg)
{
    sfImage *screenshot;
    sfTexture *text = sfTexture_create(1280, 720);
    char *name = get_name();

    sfTexture_updateFromRenderWindow(text, WIND.wind, 0, 0);
    screenshot = sfTexture_copyToImage(text);
    sfImage_saveToFile(screenshot, name);
    sfTexture_destroy(text);
    sfImage_destroy(screenshot);
}