/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** credits
*/

#include "rpg.h"

static void destroy_credits(credit_t *credit)
{
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(credit->back));
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(credit->cred));
    sfRectangleShape_destroy(credit->rect);
    sfSprite_destroy(credit->back);
    sfSprite_destroy(credit->cred);
}

static credit_t init_credit(rpg_t *rpg)
{
    credit_t credits;
    sfTexture *text =
sfTexture_createFromFile(menu_path[0][GAME.language], NULL);

    credits.back = sfSprite_create();
    credits.cred = sfSprite_create();
    sfSprite_setTexture(credits.back, text, sfTrue);
    text = sfTexture_createFromFile(credit_path[GAME.language], NULL);
    sfSprite_setTexture(credits.cred, text, sfTrue);
    sfSprite_setScale(credits.back, V2F(0.7, 0.7));
    sfSprite_setPosition(credits.back, V2F(0, 0));
    sfSprite_setPosition(credits.cred, V2F(0, 800));
    credits.rect = create_rect(V2F(0, 0), V2F(1280, 720));
    sfRectangleShape_setOutlineColor(credits.rect, sfTransparent);
    sfRectangleShape_setFillColor(credits.rect, (sfColor){0, 0, 0, 190});
    return credits;
}

static int update_rect_credit(credit_t *credits, size_t frame)
{
    sfVector2f pos = sfSprite_getPosition(credits->cred);

    if (pos.y < -6870)
        return 1;
    for (size_t i = 0; i < frame; i++)
        pos.y -= 1;
    sfSprite_setPosition(credits->cred, pos);
    return 0;
}

void menu_credit(rpg_t *rpg, obj_t **obj, house_t **house)
{
    credit_t credits = init_credit(rpg);
    int ret_val = 0;
    size_t frames;

    (void) obj;
    (void) house;
    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            ret_val += check_credit_events(rpg);
        if (ret_val == 1 || MENU.menu_on == 0) {
            destroy_credits(&credits);
            return;
        }
        rpg->frame = update_time(&frames);
        if (update_rect_credit(&credits, frames) == 1)
            break;
        credit_display(rpg, &credits);
    }
    destroy_credits(&credits);
}