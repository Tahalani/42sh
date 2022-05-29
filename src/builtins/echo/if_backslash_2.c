/*
** EPITECH PROJECT, 2022
** if_backslash_2
** File description:
** echo backslash
*/

#include "my.h"
#include "echo.h"

int if_backlash_f(char **commands, int i, size_t *j)
{
    if (commands[i][*j] == '\\' && commands[i][*j + 1] == 'f') {
        my_putchar('\f');
        *j += 2;
        return 0;
    }
    return -1;
}

int if_backlash_r(char **commands, int i, size_t *j)
{
    if (commands[i][*j] == '\\' && commands[i][*j + 1] == 'r') {
        my_putchar('\r');
        *j += 2;
        return 0;
    }
    return -1;
}

int if_backlash_v(char **commands, int i, size_t *j)
{
    if (commands[i][*j] == '\\' && commands[i][*j + 1] == 'v') {
        my_putchar('\v');
        *j += 2;
        return 0;
    }
    return -1;
}
