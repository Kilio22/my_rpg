/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** time_gestion
*/

#include "rpg.h"

int check_characters_clock(sfClock *clock, float limit)
{
    sfTime time;
    float micro_seconds;

    time = sfClock_getElapsedTime(clock);
    micro_seconds = time.microseconds;
    if (micro_seconds > limit) {
        sfClock_restart(clock);
        return (0);
    }
    return (-1);
}