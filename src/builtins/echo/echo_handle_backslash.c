/*
** EPITECH PROJECT, 2022
** echo_handle_backslash
** File description:
** FreeKOSOVO
*/

#include "my.h"
#include "builtins.h"
#include "echo.h"

static void other_backslash(char **commands, int i, size_t *j);

void handle_backslash(char **commands, int i, size_t *j)
{
    if (commands[i][*j] == '\\' && commands[i][*j + 1] == 'n') {
        my_putchar('\n');
        *j += 2;
    }
    if (commands[i][*j] == '\\' && commands[i][*j + 1] == 't') {
        my_putchar('\t');
        *j += 2;
    }
    if (commands[i][*j] == '\\' && commands[i][*j + 1] == 'a') {
        my_putchar('\a');
        *j += 2;
    }
    if (commands[i][*j] == '\\' && commands[i][*j + 1] == 'b') {
        my_putchar('\b');
        *j += 2;
    }
    other_backslash(commands, i, j);
}

static void other_backslash(char **commands, int i, size_t *j)
{
    if (commands[i][*j] == '\\' && commands[i][*j + 1] == 'v') {
        my_putchar('\v');
        *j += 2;
    }
    if (commands[i][*j] == '\\' && commands[i][*j + 1] == 'f') {
        my_putchar('\f');
        *j += 2;
    }
    if (commands[i][*j] == '\\' && commands[i][*j + 1] == 'r') {
        my_putchar('\r');
        *j += 2;
    }
}
