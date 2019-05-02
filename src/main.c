/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main
*/

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"
#include "my_dragndrop.h"
#include "inventory.h"

static int init_main(rpg_t *rpg)
{
    sfVector2u windowSize;

    rpg->wind.wind = create_window("Nuck Fathan", 10);
    windowSize = sfRenderWindow_getSize(rpg->wind.wind);
    rpg->wind.view =
sfView_createFromRect((sfFloatRect){0, 0, windowSize.x, windowSize.y});
    rpg->game.nb_save = 0;
    rpg->game.name_save = mg_strdup("antoine");
    rpg->game.language = 0;
    rpg->game.inv = inventory_create(rpg->wind.wind);
    rpg->controls.bools = malloc(sizeof(sfBool) * 10);
    if (rpg->controls.bools == NULL)
        return (84);
    for (int i = 0; i < 10; i++)
        rpg->controls.bools[i] = 0;
    rpg->error_code = 0;
    for (int i = 0; i < 3; i++)
        rpg->killed[i] = 0;
    create_music(rpg);
    return 0;
}

static void destroy_game(rpg_t *rpg, house_t **house, obj_t **obj)
{
    sfRenderWindow_destroy(WIND.wind);
    sfMusic_destroy(rpg->game.back_music);
    destroy_sounds(rpg);
    for (int i = 0; i < NB_HOUSE; i++)
        free_house(house[i]);
    free(house);
    free(obj);
    free(CONTROLS.bools);
    sfView_destroy(WIND.view);
    inventory_destroy(GAME.inv);
    free(GAME.inv);
}

static int check_password(char *pass, rpg_t *rpg)
{
    FILE *stream;
    int password = my_atoi(pass);
    int our_pass;

    stream = fopen(".mdp", "r");
    if (stream == NULL)
        return 1;
    if (fread(&our_pass, sizeof(int), 1, stream) <= 0)
        return 1;
    if (password != our_pass)
        return 1;
    rpg->debug = 1;
    return 0;
}

static int check_flags(int ac, char **av, rpg_t *rpg)
{
    if (check_files() == -1)
        return 1;
    if (ac == 1) {
        rpg->debug = 0;
        return 0;
    } else if (ac == 3) {
        if (my_strcmp(av[1], "-d") != 0)
            return 1;
        if (check_password(av[2], rpg) == 1) {
            rpg->debug = 0;
            return 0;
        }
    } else
        return 1;
    return 0;
}

int main(int ac, char **av)
{
    rpg_t rpg;
    obj_t **obj = malloc(sizeof(obj_t *) * 11);
    house_t **house = malloc(sizeof(house_t *) * (NB_HOUSE + 1));

    if (check_flags(ac, av, &rpg) == 1)
        return (84);
    if (obj == NULL || house == NULL)
        return (84);
    if (create_houses(house) == -1)
        return 84;
    rpg.house = house;
    if (init_main(&rpg) == 84)
        return 84;
    srand((unsigned long) rpg.wind.wind);
    init_menu(&rpg, obj, house);
    if (rpg.error_code == 84)
        return (84);
    destroy_game(&rpg, house, obj);
    return (0);
}