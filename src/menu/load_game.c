/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** load_game
*/

#include "rpg.h"

static int init_text_load(load_game_t *new, rpg_t *rpg)
{
    char *line = NULL;
    sfVector2f pos = {640, 260};
    int size = 0;

    for (int i = 0; i < 3; i++) {
        line = check_save_status(i);
        if (my_strlen(line) > size)
            size = my_strlen(line);
        if (line == NULL) {
            new->text[i].text = create_text(menu_font, "N/A", 60, pos);
            new->text[i].status = -1;
        }
        else {
            new->text[i].text = create_text(menu_font, line, 60, pos);
            new->text[i].status = 1;
        }
        pos.y += 100;
        free(line);
    }
    return size;
}

load_game_t init_load_game(rpg_t *rpg)
{
    load_game_t new;
    sfTexture *texture =
sfTexture_createFromFile(menu_path[0][GAME.language], NULL);
    int size = 0;

    new.back = sfSprite_create();
    sfSprite_setTexture(new.back, texture, sfTrue);
    sfSprite_setScale(new.back, V2F(0.7, 0.7));
    size = init_text_load(&new, rpg);
    new.rect = create_rect((sfVector2f){640, 260}, (sfVector2f){25 * size, 90});
    new.high = 0;
    sfText_setColor(new.text[0].text, sfYellow);
    return new;
}

void update_rect_load(load_game_t *load, size_t frame)
{
    sfVector2f pos = sfRectangleShape_getPosition(load->rect);
    sfVector2f text_pos = sfText_getPosition(load->text[load->high].text);

    if (pos.y == text_pos.y)
        return;
    for (size_t i = 0; i < frame; i++) {
        if (pos.y < text_pos.y)
            pos.y += 10;
        else
            pos.y -= 10;
    }
    sfRectangleShape_setPosition(load->rect, pos);
}

void load_display(rpg_t *rpg, load_game_t *load)
{
    sfRenderWindow_drawSprite(WIND.wind, load->back, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawText(WIND.wind, load->text[i].text, NULL);
    sfRenderWindow_drawRectangleShape(WIND.wind, load->rect, NULL);
    sfRenderWindow_setView(WIND.wind, WIND.view);
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

void menu_load_game(rpg_t *rpg, obj_t **obj, house_t **house)
{
    load_game_t load = init_load_game(rpg);
    int ret_val = 0;
    size_t frames;

    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            ret_val += check_load_game_events(rpg, &load, obj, house);
        if (ret_val == 1 || MENU.menu_on == 0) {
            destroy_load(&load);
            return;
        }
        rpg->frame = update_time(&frames);
        update_rect_load(&load, frames);
        check_mbutton_press_load(rpg, &load, obj, house);
        load_display(rpg, &load);
    }
    destroy_load(&load);
}