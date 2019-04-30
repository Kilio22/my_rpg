/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create_dialogue
*/

#include "rpg.h"

static void create_text_dialogues(dialogue_t *new, int i, sfVector2f vect)
{
    new->text[0] = create_text(menu_font, welcome[i][new->language], 19, vect);
    vect.y += 40;
    for (int j = 1; j < 4; j++) {
        new->text[j] = create_text(menu_font,
dial[i][new->language][j - 1], 19, vect);
        vect.x += 180;
    }
    sfText_setColor(new->text[1], sfBlue);
}

dialogue_t create_dialogue(rpg_t *rpg, int i)
{
    dialogue_t new;
    sfVector2f vect = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 558}, WIND.view);
    sfTexture *texture = sfTexture_createFromFile("assets/parchemin.png", NULL);

    new.parch = sfSprite_create();
    sfSprite_setTexture(new.parch, texture, sfTrue);
    sfSprite_setScale(new.parch, V2F(0.6, 0.6));
    vect.x += 60;
    sfSprite_setPosition(new.parch, vect);
    new.high = 1;
    new.quest_status_d = -1;
    vect.x += 20;
    vect.y += 15;
    new.language = GAME.language;
    create_text_dialogues(&new, i, vect);
    new.nb_pnj = i;
    return new;
}