/*
** EPITECH PROJECT, 2019
** mygraphlib
** File description:
** prompt_mem
*/

#include "my_prompt.h"

my_prompt_t *my_prompt_create(sfTexture *background)
{
    my_prompt_t *new = malloc(sizeof(my_prompt_t));

    new->background = sfSprite_create();
    sfSprite_setTexture(new->background, background, sfTrue);
    new->font = sfFont_createFromFile("graphmy_lib/prompt/arial.ttf");
    new->text = sfText_create();
    sfText_setFont(new->text, new->font);
    new->focused = 1;
    new->char_to_display = 10;
    new->pos = (sfVector2f){0, 0};
    new->scale = (sfVector2f){1, 1};
    new->return_released = 1;
    new->to_display = mg_strdup("");
    return (new);
}

void my_prompt_destroy(my_prompt_t *prompt)
{
    sfSprite_destroy(prompt->background);
    sfText_destroy(prompt->text);
    sfFont_destroy(prompt->font);
    free(prompt->to_display);
    free(prompt);
}

static void display_text(sfRenderWindow *window, my_prompt_t *prompt)
{
    sfFloatRect back;
    sfFloatRect text;
    sfVector2f pos_text;
    int offset = mg_strlen(prompt->to_display) - prompt->char_to_display;
    char *to_display;

    if (offset < 0)
        offset = 0;
    to_display = mg_strdup(prompt->to_display + offset);
    sfText_setString(prompt->text, to_display);
    back = sfSprite_getGlobalBounds(prompt->background);
    text = sfText_getGlobalBounds(prompt->text);
    pos_text.x = back.left + (back.width / 2) - (text.width / 2);
    pos_text.y = back.top + (back.height / 2) - (text.height / 2);
    pos_text.y -= back.height * 0.15;
    sfText_setPosition(prompt->text, pos_text);
    sfRenderWindow_drawText(window, prompt->text, NULL);
    free(to_display);
}

void sfRenderWindow_drawPrompt(sfRenderWindow *window, my_prompt_t *prompt)
{
    sfSprite_setPosition(prompt->background, prompt->pos);
    sfSprite_setScale(prompt->background, prompt->scale);
    sfText_setFont(prompt->text, prompt->font);
    sfText_setPosition(prompt->text, prompt->pos);
    sfText_setScale(prompt->text, prompt->scale);
    sfRenderWindow_drawSprite(window, prompt->background, NULL);
    display_text(window, prompt);
}