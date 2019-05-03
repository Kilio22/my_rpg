/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory
*/


#ifndef INVENTORY2_H_
#define INVENTORY2_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my_vector.h"
#include "my_dragndrop.h"
#include <stdlib.h>
#include "mg_str.h"
#include "my_ini.h"
#include "my_display.h"
#include "my.h"

#define INVENTORY_SIZE_X 4
#define INVENTORY_SIZE_Y 4
#define INVENTORY_SIZE (4 * 4)

static const char items_data[] = "assets_data.ini";

#define DATA_MAPPING_SIZE 5

enum data_mapping {
    NAME,
    TYPE,
    ASSET,
    HP,
    ATTACK
};

enum items {
    WEAPON = 0,
    HELMET,
    ARMOR,
    PANTS,
    BOOTS,
    SHIELD,
    OTHER
};

struct item {
    char *name;
    int id;
    int type;
    sfTexture *t;
    dragndrop_t *display;
    int hp;
    int attack;
};
typedef struct item item_t;

struct inventory {
    item_t *stock[INVENTORY_SIZE_X * INVENTORY_SIZE_Y];
    item_t *stuff[3][6];
    item_t *item_dragging;
    int state;
    int should_exit;
    int stats[3][4];
    int key_leave;
    sfSprite *grid;
    sfSprite *inv_widget[3];

    sfRenderWindow *window;
    sfFont *font;
};
typedef struct inventory inventory_t;

// item.c
item_t *item_create(int id, ini_file_t *data);
void item_show_debug(item_t *item);
void item_destroy(item_t *item);

// inventory.c
inventory_t *inventory_create(sfRenderWindow *window);
void inventory_destroy(inventory_t *inv);

// inventory_core.c
void inventory_draw(inventory_t *inv);
void inventory_event(inventory_t *inv);
void inventory_compute(inventory_t *inv);
void inventory_loop(inventory_t *inv);

// inventory_draw.c
void inventory_draw_background(inventory_t *inv);
void inventory_draw_stock(inventory_t *inv);
void inventory_draw_stuff(inventory_t *inv);
void inventory_draw_debug(inventory_t *inv);

// inventory_data.c
int inventory_get_empty_case(inventory_t *inv);
void inventory_add_item(inventory_t *inv, item_t *item);

// inventory_event.c
void inventory_event_stock(inventory_t *inv);
void inventory_event_stuff(inventory_t *inv);
void inventory_event_select(inventory_t *inv);

// inventory_compute.c
void inventory_compute_stock_released(inventory_t *inv);
void inventory_compute_stuff_released(inventory_t *inv);

// inventory_stats.c
void inventory_draw_stats(inventory_t *inv);

// inventory_common.c
int inventory_get_id_from_coord(sfRenderWindow *window);
int inventory_get_stuff_id_from_mouse(sfRenderWindow *window);
int is_collided_mouse_rect(sfIntRect rect, sfRenderWindow *window);

// inventory_files_save.c
void inventory_save(inventory_t *inv, char *path);

// inventory_file_load.c
inventory_t *inventory_create_from_file(sfRenderWindow *window, char *path);

//inventory_stats.c
int compute_attack_stat(inventory_t *inv, int nb_char);
int compute_health_stat(inventory_t *inv, int nb_char);

static const sfVector2f stuff_grid[6] = {
{68, 214}, {143, 68},
{143, 142}, {143, 214},
{143, 287}, {216, 214}};

#endif /* !INVENTORY_H_ */
