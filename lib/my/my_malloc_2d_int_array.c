/*
** EPITECH PROJECT, 2022
** my_malloc_2d_int_array
** File description:
** my_malloc_int_array
*/

#include <stddef.h>
#include <stdlib.h>

int **my_malloc_2d_int_array(int const nb_rows, int const nb_cols)
{
    int **arr = malloc(sizeof(int *) * (nb_rows));

    if (arr == NULL)
        return (NULL);
    for (int i = 0; i < nb_rows; i++) {
        arr[i] = malloc(sizeof(int) * (nb_cols));
        if (arr[i] == NULL)
            return (NULL);
    }
    return (arr);
}
