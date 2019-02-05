/*
** EPITECH PROJECT, 2018
** task03
** File description:
** function return content of array
*/

void my_putchar(char c);

int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    int compteur = 0;
    while (tab[compteur] != 0) {
        my_putstr(tab[compteur]);
        my_putchar('\n');
        compteur++;
    }
    return (0);
}
