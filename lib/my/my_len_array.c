/*
** EPITECH PROJECT, 2022
** my_len_array
** File description:
** len_array
*/

#include <stddef.h>

int my_len_array(char **array)
{
    int i;

    for (i = 0; array[i] != NULL; i++);
    return (i);
}
