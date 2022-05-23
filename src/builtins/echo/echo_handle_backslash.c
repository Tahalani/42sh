/*
** EPITECH PROJECT, 2022
** if_builtins
** File description:
** FreeKOSOVO
*/

#include <stddef.h>
#include <string.h>
#include "my.h"
#include "builtins.h"
#include "mysh.h"
#include <unistd.h>

void other_backslash(char **commands, int i, size_t *j);

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

void other_backslash(char **commands, int i, size_t *j)
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
