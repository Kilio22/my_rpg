/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** time_gestion
*/

#include "rpg.h"

size_t update_time(size_t *frames)
{
    static sfClock *clock = NULL;
    static sfTime old_time = {0};
    sfTime current_time;
    static size_t frame = 0;

    if (!clock)
        clock = sfClock_create();
    if (frames) {
        current_time = sfClock_getElapsedTime(clock);
        *frames = current_time.microseconds - old_time.microseconds;
        *frames /= 16666;
        (old_time).microseconds += *frames * 16666;
        frame = *frames;
    }
    if (frames && *frames >= 100) {
        sfClock_restart(clock);
        frame = 1;
        old_time.microseconds = 0;
        return 1;
    }
    return frame;
}

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