/*
** EPITECH PROJECT, 2018
** task02
** File description:
** all proto of libmy.a
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>

void my_putchar(char c);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest , char const *src , int n);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char *str, int n);
char *my_strdup(char const *src);
char *check2(char *nb11, char *nb22);
char *my_strxdup(char const *src, int n);
int my_intlen(int nb);
int my_check_occur(char *str, char c);
char *my_int_to_char(int nb);
int my_tab_len(char **tab);
void my_put_error(char *str);
int my_atoi(char *input);
char *my_itoa(int nb, char *str);
char *my_realloc(char *input_str, int nb);
char *my_realloc_str(char *f, char *b);
char **my_str_to_word_array(char const *str, char c);

#endif /* !MY_H_ */