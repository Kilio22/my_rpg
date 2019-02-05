/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** getnextline
*/

#ifndef  READ_SIZE
#define  READ_SIZE 50
#endif  //READ_SIZE

#ifndef GETNEXTLINE_H
#define GETNEXTLINE_H

char *get_next_line(int fd);
char *my_strndup(char *str, int n);
char *my_strncat(char *dest, char *str, int n);
static char *read_file(int fd, char *str, char **readed);

#endif //GETNEXTLINE_H