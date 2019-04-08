/*
** EPITECH PROJECT, 2019
** filemy
** File description:
** exec_rights
*/

#include "my_rights.h"

int right_usr_exec(char const *path)
{
    return (apply_right_mask(path, S_IXUSR));
}

int right_grp_exec(char const *path)
{
    return (apply_right_mask(path, S_IXGRP));
}

int right_otr_exec(char const *path)
{
    return (apply_right_mask(path, S_IXOTH));
}