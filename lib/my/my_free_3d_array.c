/*
** EPITECH PROJECT, 2022
** my_free_3d_array
** File description:
** FreeKOSOVO
*/

#include <stdio.h>
#include <stdlib.h>

#include "my.h"

void my_free_3d_array(char ***array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_freef("%t", array[i]);
    }
    free(array);
}