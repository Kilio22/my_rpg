/*
** EPITECH PROJECT, 2018
** printf h
** File description:
** h
*/


#ifndef PRINTF_H_
#define PRINTF_H_
#include <stdarg.h>

int put_unsign(unsigned int nb);
int put_octal(int nb);
int put_hexa(int nb);
int put_binary(unsigned int nb);
int put_pointers(long nb);
int my_putstr_s(char const *str);
int print_char(va_list list);
int print_str(va_list list);
int print_str_s(va_list list);
int print_binary(va_list list);
int print_octal(va_list list);
int print_hexa(va_list list);
int print_unsig(va_list list);
int print_nbr(va_list list);
int print_pointers(va_list list);
int check(char c);
int printer(char c, va_list list);
int my_printf(char *str, ...);
int put_octal_d(int nb);

#endif /* !PRINTF_H_ */