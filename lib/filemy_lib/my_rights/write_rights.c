/*
** EPITECH PROJECT, 2019
** filemy
** File description:
** write_rights
*/

#include "my_rights.h"

int right_usr_write(char const *path)
{
    return (apply_right_mask(path, S_IWUSR));
}

int right_grp_write(char const *path)
{
    return (apply_right_mask(path, S_IWGRP));
}

int right_otr_write(char const *path)
{
    return (apply_right_mask(path, S_IWOTH));
}