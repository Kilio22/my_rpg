/*
** EPITECH PROJECT, 2019
** filemy
** File description:
** read_rights
*/

#include "my_rights.h"

int right_usr_read(char const *path)
{
    return (apply_right_mask(path, S_IRUSR));
}

int right_grp_read(char const *path)
{
    return (apply_right_mask(path, S_IRGRP));
}

int right_otr_read(char const *path)
{
    return (apply_right_mask(path, S_IROTH));
}