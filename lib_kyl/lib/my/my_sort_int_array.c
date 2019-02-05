/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** lib
*/

void my_swap(int *a, int *b);

void my_sort_int_array(int *tab, int size)
{
    int i = 1;
    int j = 0;

    while (i < size) {
        j = i;
        while (j > 0) {
            if (tab[j - 1] > tab[j])
                my_swap(&tab[j - 1], &tab[j]);
            j--;
        }
        i++;
    }
    return;
}
