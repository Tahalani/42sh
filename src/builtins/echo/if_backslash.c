/*
** EPITECH PROJECT, 2022
** if_backslash
** File description:
** FreeKOSOVO
*/

#include "my.h"
#include "echo.h"

int if_backlash_n(char **commands, int i, size_t *j)
{
    if (commands[i][*j] == '\\' && commands[i][*j + 1] == 'n') {
        my_putchar('\n');
        *j += 2;
        return 0;
    }
    return -1;
}

int if_backlash_t(char **commands, int i, size_t *j)
{
    if (commands[i][*j] == '\\' && commands[i][*j + 1] == 't') {
        my_putchar('\t');
        *j += 2;
        return 0;
    }
    return -1;
}

int if_backlash_a(char **commands, int i, size_t *j)
{
    if (commands[i][*j] == '\\' && commands[i][*j + 1] == 'a') {
        my_putchar('\a');
        *j += 2;
        return 0;
    }
    return -1;
}

int if_backlash_b(char **commands, int i, size_t *j)
{
    if (commands[i][*j] == '\\' && commands[i][*j + 1] == 'b') {
        my_putchar('\b');
        *j += 2;
        return 0;
    }
    return -1;
}
