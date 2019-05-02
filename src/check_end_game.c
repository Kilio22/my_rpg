/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_end_game
*/

#include "rpg.h"

int end_text_index(char **to_print, int *p_ind, int *index, end_game_t *end)
{
    if (my_strlen(*to_print) == 0) {
        *to_print = malloc(sizeof(char) * (my_strlen(end_text[end->language][end->end_status]) + 1));
        if (*to_print == NULL)
            return -1;
    }
    if (end == NULL) {
        free(*to_print);
        *to_print = NULL;
        *p_ind = 0;
        return -1;
    }
    if (*index != end->end_status) {
        *index = end->end_status;
        *p_ind = 0;
        free(*to_print);
        *to_print = my_strdup("");
    }
    return 0;
}

int update_end_text(end_game_t *end)
{
    static int print_index = 0;
    static int index = 0;
    static char *print = NULL;

    if (end_text_index(&print, &print_index, &index, end) == -1)
        return -1;
    for (size_t i = 0; (i < update_time(NULL) || i <= 1) &&
print_index < my_strlen(end_text[end->language][index]); i++) {
        print[print_index] = end_text[end->language][index][print_index];
        print_index++;
        print[print_index] = '\0';
    }
    sfText_setString(end->text, print);
    if (fight_text_intro(1) == 1 && my_strlen(print) == my_strlen(end_text[end->language][end->end_status])) {
        end->end_status++;
    }
    if (my_strlen(print) != my_strlen(end_text[end->language][index]))
        fight_text_intro(0);
    return 0;
}

end_game_t init_end_game(rpg_t *rpg)
{
    end_game_t end;
    const sfView *default_view = sfRenderWindow_getDefaultView(WIND.wind);
    sfTexture *texture = sfTexture_create(1280, 720);
    sfTexture *parch_text = sfTexture_createFromFile("assets/parchemin.png", NULL);

    sfTexture_updateFromRenderWindow(texture, WIND.wind, 0, 0);
    sfRenderWindow_setView(WIND.wind, default_view);
    end.back = sfSprite_create();
    sfSprite_setTexture(end.back, texture, sfTrue);
    end.text = create_text(menu_font, "oui", 30, V2F(110, 580));
    end.parch = sfSprite_create();
    sfSprite_setTexture(end.parch, parch_text, sfTrue);
    sfSprite_setPosition(end.parch, V2F(90, 558));
    end.end_status = 0;
    end.language = GAME.language;
    end.rect = create_rect(V2F(0, 0), V2F(1280, 720));
    sfRectangleShape_setOutlineColor(end.rect, sfTransparent);
    return end;
}

int end_game_event(end_game_t *end, rpg_t *rpg)
{
    if (WIND.event.type == sfEvtClosed) {
        sfRenderWindow_close(WIND.wind);
        return 1;
    }
    if (WIND.event.type == sfEvtKeyPressed
&& WIND.event.key.code == sfKeyEscape)
        pause_game(rpg);
    return 0;
}

void avengers_end_game(rpg_t *rpg)
{
    const sfView *view_backup = sfRenderWindow_getView(WIND.wind);
    end_game_t end = init_end_game(rpg);
    size_t frames = 0;
    int n_val = 0;

    fight_text_intro(0);
    while (sfRenderWindow_isOpen(WIND.wind)) {
        update_time(&frames);
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            n_val += end_game_event(&end, rpg);
        if (n_val > 0 || MENU.menu_on == 0)
            return;
        sfRenderWindow_clear(WIND.wind, sfBlack);
        sfRenderWindow_drawSprite(WIND.wind, end.back, NULL);
        sfRenderWindow_drawSprite(WIND.wind, end.parch, NULL);
        sfRenderWindow_drawText(WIND.wind, end.text, NULL);
        sfRenderWindow_display(WIND.wind);
        update_end_text(&end);
    }
    sfRenderWindow_setView(WIND.wind, view_backup);
}

void check_end_game(rpg_t *rpg, obj_t **obj, house_t **house)
{
    if (rpg->killed[0] == 1 && rpg->killed[1] == 1 && rpg->killed[2] == 1)
        avengers_end_game(rpg);
}