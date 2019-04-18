/*
** EPITECH PROJECT, 2018
** mg_display.h
** File description:
** function for display types
*/

#ifndef mg_DISPLAY_H
#define mg_DISPLAY_H

#include <unistd.h>
#include <stdlib.h>

//  put char & strings  //
void mg_putchar(char c);
void mg_putstr(char const *str);

//  put nbr & other maths output   //
int mg_putnbr(int nb);
void mg_putunbr(unsigned int nb);
void mg_putfloat(float nb, int sensibility); //may have err if s > 5

/* err exit */
void mg_put_errchar(char c);
void mg_put_errstr(char const *str);

#endif //mg_DISPLAY_H
