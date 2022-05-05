/*
** EPITECH PROJECT, 2022
** my_malloc_2d_char_array
** File description:
** FreeKOSOVO
*/

#include <stddef.h>
#include <stdlib.h>

char **my_malloc_2d_char_array(int const nb_col, int const nb_line)
{
    char **result = malloc(sizeof(char *) * (nb_line + 1));

    if (result == NULL)
        return (NULL);
    for (int i = 0; i != nb_line; i++) {
        result[i] = malloc(sizeof(char) * (nb_col + 1));
        if (result[i] == NULL)
            return (NULL);
        result[i][nb_col] = '\0';
    }
    result[nb_line] = NULL;
    return (result);
}
