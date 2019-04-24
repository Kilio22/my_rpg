/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** time_gestion
*/

#include "rpg.h"

int clock_door(void)
{
    static sfClock *clock = NULL;
    sfTime time;
    float seconds;

    if (!clock)
        clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 0.15) {
        sfClock_restart(clock);
        return 1;
    }
    return 0;
}

int check_characters_clock(sfClock *clock, float limit)
{
    sfTime time;
    float micro_seconds;

    time = sfClock_getElapsedTime(clock);
    micro_seconds = time.microseconds;
    if (micro_seconds > limit) {
        sfClock_restart(clock);
        return 0;
    }
    return -1;
}