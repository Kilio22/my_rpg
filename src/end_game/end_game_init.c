/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** end_game_init
*/

#include "rpg.h"

static void init_end_game_oth(end_game_t *end, rpg_t *rpg)
{
    sfTexture *texture =
sfTexture_createFromFile("assets/menu_image.png", NULL);

    end->language = GAME.language;
    end->end_status = 0;
    end->o_back = sfSprite_create();
    sfSprite_setTexture(end->o_back, texture, sfTrue);
    sfSprite_setScale(end->o_back, V2F(0.7, 0.7));
}

end_game_t init_end_game(rpg_t *rpg)
{
    end_game_t end;
    const sfView *default_view = sfRenderWindow_getDefaultView(WIND.wind);
    sfTexture *texture = sfTexture_create(1280, 720);
    sfTexture *parch_l = sfTexture_createFromFile("assets/parchemin.png", NULL);

    sfTexture_updateFromRenderWindow(texture, WIND.wind, 0, 0);
    sfRenderWindow_setView(WIND.wind, default_view);
    end.back = sfSprite_create();
    sfSprite_setTexture(end.back, texture, sfTrue);
    end.text = create_text(menu_font, " ", 30, V2F(110, 580));
    end.parch = sfSprite_create();
    sfSprite_setTexture(end.parch, parch_l, sfTrue);
    sfSprite_setPosition(end.parch, V2F(90, 558));
    end.rect = create_rect(V2F(0, 0), V2F(1280, 720));
    sfRectangleShape_setOutlineColor(end.rect, sfTransparent);
    init_end_game_oth(&end, rpg);
    fight_text_intro(0);
    update_rect_end(&end, 1);
    return end;
}