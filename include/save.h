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
void save(rpg_t *rpg);

// open_core.c
void load(rpg_t *rpg);
void restore_killed(rpg_t *rpg, ini_file_t *file);

#endif /* !SAVE_H_ */
