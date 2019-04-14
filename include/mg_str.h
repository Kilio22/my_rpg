/*
** EPITECH PROJECT, 2018
** mg_str.h
** File description:
** contain all prototype of functions for str & char operation
*/

#ifndef MY_STR_H
#define MY_STR_H

#include <stdlib.h>

#ifndef BOOL_SYS
#define BOOL_SYS
#define TRUE 1
#define FALSE 0
typedef int mg_bool_t;
#endif

/* Epitech standard lib pool function */

int mg_strlen(char const *str);

mg_bool_t mg_str_isnum(char const *str); //float with . ok
mg_bool_t mg_str_isint(char const *str);

char *mg_revstr(char *str); //return NULL if fails
char *mg_strstr(char *str, char const *to_find); //return \0 if not match
mg_bool_t mg_strcmp(char const *s1, char const *s2);

char *mg_strcpy(char *dest, char const *str);
char *mg_strncpy(char *dest, char const *src, int n);
char *mg_strcat(char **s1, char const *s2);
char *mg_strncat(char **s1, char const *s2, int n);
char *mg_strdup(char const *src);
char *mg_strndup(char const *src, int n);
mg_bool_t mg_strncmp(char const *s1, char const *s2, int n);

// mg_strtok.c
char **mg_strtok(char *src, char *tok);
void mg_strtok_destroy(char **str_arr);
void remove_both_caracter(char **src, char to_remove);

/* fonction created by guilian ganster */
char *mg_strreplace(char **str, char const *to_find, char const *substitute);

/*  my char is   */
mg_bool_t mg_char_isnumber(char c);
mg_bool_t mg_char_isuppercase(char c);
mg_bool_t mg_char_islowercase(char c);
mg_bool_t mg_char_isletter(char c);

//conversion sys
char *mg_itoa(int nb);
int mg_atoi(char const *str);

#endif //MY_STR_H
