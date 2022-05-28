/*
** EPITECH PROJECT, 2022
** echo_handle_backslash
** File description:
** FreeKOSOVO
*/

#include "echo_array.h"
#include "echo.h"

int handle_backslash(char **commands, int i, size_t *j)
{
    for (int index = 0; index != NBR_BACKSLASH; index++) {
        if ((*ECHO_ARRAY[index])(commands, i, j) == 0)
            return (0);
    }
    return (-1);
}
