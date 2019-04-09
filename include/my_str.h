/*
** EPITECH PROJECT, 2018
** my_str.h
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
typedef int my_bool_t;
#endif

/* Epitech standard lib pool function */

int my_strlen(char const *str);

my_bool_t my_str_isnum(char const *str); //float with . ok
my_bool_t my_str_isint(char const *str);

char *my_revstr(char *str); //return NULL if fails
char *my_strstr(char *str, char const *to_find); //return \0 if not match
my_bool_t my_strcmp(char const *s1, char const *s2);

char *my_strcpy(char *dest, char const *str);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char **s1, char const *s2);
char *my_strncat(char **s1, char const *s2, int n);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int n);
my_bool_t my_strncmp(char const *s1, char const *s2, int n);

// my_strtok.c
char **my_strtok(char *src, char *tok);
void my_strtok_destroy(char **str_arr);
void remove_both_caracter(char **src, char to_remove);

/* fonction created by guilian ganster */
char *my_strreplace(char **str, char const *to_find, char const *substitute);

/*  my char is   */
my_bool_t my_char_isnumber(char c);
my_bool_t my_char_isuppercase(char c);
my_bool_t my_char_islowercase(char c);
my_bool_t my_char_isletter(char c);

//conversion sys
char *my_itoa(int nb);
int my_atoi(char const *str);

#endif //MY_STR_H
