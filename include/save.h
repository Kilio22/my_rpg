/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** save
*/

#ifndef SAVE_H_
#define SAVE_H_

#include "struct.h"
#include "inventory.h"
#include "my_ini.h"
#include "mg_str.h"

// save_core.c
void save(rpg_t *rpg, obj_t **objs);

// open_core.c
void load(rpg_t *rpg, obj_t **objs);

#endif /* !SAVE_H_ */
