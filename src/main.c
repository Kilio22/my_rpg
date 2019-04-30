/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"
#include "my_dragndrop.h"
#include "inventory.h"

int init_main(rpg_t *rpg)
{
    sfVector2u windowSize;

    rpg->wind.wind = create_window("Nuck Fathan", 10);
    windowSize = sfRenderWindow_getSize(rpg->wind.wind);
    rpg->wind.view =
sfView_createFromRect((sfFloatRect){0, 0, windowSize.x, windowSize.y});
    rpg->game.nb_save = 0;
    rpg->game.language = 0;
    //rpg->game.inv = inventory_create(rpg->wind.wind);
    rpg->game.inv = inventory_create_from_file(rpg->wind.wind, "inv.ini");
    rpg->controls.bools = malloc(sizeof(sfBool) * 10);
    if (rpg->controls.bools == NULL)
        return (84);
    for (int i = 0; i < 10; i++)
        rpg->controls.bools[i] = 0;
    rpg->error_code = 0;
    create_music(rpg);
    return 0;
}

int main(void)
{
    rpg_t rpg;
    obj_t **obj = malloc(sizeof(obj_t *) * 11);
    house_t **house = malloc(sizeof(house_t *) * (NB_HOUSE + 1));

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
    sfMusic_destroy(rpg.game.back_music);
    for (int i = 0; i < NB_HOUSE; i++)
        free_house(house[i]);
    return (0);
}