/*
** EPITECH PROJECT, 2019
** filemy
** File description:
** right_checker
*/

#include "my_rights.h"

int right_read(char const *path)
{
    int result;
    int *rights = rights_get(path);

    if (rights == ERR)
        return (ERR);
    result = rights[UR] + rights[GR] + rights[OR];
    if (result > 0)
        return (TRUE);
    return (FALSE);
}

int right_write(char const *path)
{
    int result;
    int *rights = rights_get(path);

    if (rights == ERR)
        return (ERR);
    result = rights[UW] + rights[GW] + rights[OW];
    if (result > 0)
        return (TRUE);
    return (FALSE);
}

int right_exec(char const *path)
{
    int result;
    int *rights = rights_get(path);

    if (rights == ERR)
        return (ERR);
    result = rights[UX] + rights[GX] + rights[OX];
    if (result > 0)
        return (TRUE);
    return (FALSE);
}