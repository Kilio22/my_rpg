/*
** EPITECH PROJECT, 2018
** my_display.h
** File description:
** function for display types
*/

#ifndef MY_DISPLAY_H
#define MY_DISPLAY_H

#include <unistd.h>
#include <stdlib.h>

//  put char & strings  //
void my_putchar(char c);
void my_putstr(char const *str);

//  put nbr & other maths output   //
int my_putnbr(int nb);
void my_putunbr(unsigned int nb);
void my_putfloat(float nb, int sensibility); //may have err if s > 5

/* err exit */
void my_put_errchar(char c);
void my_put_errstr(char const *str);

#endif //MY_DISPLAY_H
