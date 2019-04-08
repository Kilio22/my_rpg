/*
** EPITECH PROJECT, 2019
** filemy
** File description:
** common_rights
*/

#include "my_rights.h"

int apply_right_mask(char const *path, int mask)
{
    struct stat stat_s;
    mode_t mode;

    if (stat(path, &stat_s) == -1)
        return (-1);
    mode = stat_s.st_mode;
    if ((mode & mask) == 0)
        return (FALSE);
    return (TRUE);
}

int *rights_get(char const *path)
{
    int *array = malloc(sizeof(int) * 9);

    array[UR] = right_usr_read(path);
    array[UW] = right_usr_write(path);
    array[UX] = right_usr_exec(path);
    array[GR] = right_grp_read(path);
    array[GW] = right_grp_write(path);
    array[GX] = right_grp_exec(path);
    array[OR] = right_grp_read(path);
    array[OW] = right_grp_write(path);
    array[OX] = right_grp_exec(path);
    if (array[UR] == ERR) {
        free(array);
        return (NULL);
    }
    return (array);
}

int is_directory(char const *path)
{
    struct stat stat_s;
    int type;

    if (stat(path, &stat_s) == -1)
        return (-1);
    type = stat_s.st_mode & 110000000000000;
    if (type == 16384)
        return (TRUE);
    return (FALSE);
}
