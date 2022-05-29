/*
** EPITECH PROJECT, 2022
** my_free_int_array
** File description:
** my_free_int array
*/

#include <stdlib.h>

void my_free_int_array(int **array, int nb_rows)
{
    for (int i = 0; i < nb_rows; i++)
        free(array[i]);
    free(array);
}
