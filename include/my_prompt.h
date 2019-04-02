/*
** EPITECH PROJECT, 2019
** mygraphlib
** File description:
** my_prompt
*/

#ifndef MY_PROMPT_H_
#define MY_PROMPT_H_

#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "my_str.h"
#include <stdlib.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1
typedef int my_bool_t;

struct my_prompt {
    sfSprite *background;
    sfText *text;
    char *to_display;
    int char_to_display;
    sfVector2f pos;
    sfVector2f scale;

    my_bool_t return_released;
    my_bool_t focused;
    sfFont *font;
};
typedef struct my_prompt my_prompt_t;

// prompt mem
my_prompt_t *my_prompt_create(sfTexture *background);
void my_prompt_destroy(my_prompt_t *prompt);
void sfRenderWindow_drawPrompt(sfRenderWindow *window, my_prompt_t *prompt);

// prompt event
void my_prompt_check_focus(my_prompt_t *prompt, sfRenderWindow *window);
void my_prompt_check_input(my_prompt_t *prompt, sfEvent event);
my_bool_t my_prompt_enter_pressed(my_prompt_t *prompt);
my_bool_t my_prompt_enter_pressedOnce(my_prompt_t *prompt);

// string manipulation
void my_prompt_str_pop(my_prompt_t *prompt);
void my_prompt_str_push(my_prompt_t *prompt, char c);

#endif /* !MY_PROMPT_H_ */
