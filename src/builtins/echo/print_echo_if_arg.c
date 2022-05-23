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

void print_with_backslash(char **commands, int i);

void print_simple_case(char *commands)
{
    for (size_t i = 0; i < strlen(commands); i++) {
        if (commands[i] == '\\')
            continue;
        my_putchar(commands[i]);
    }
}

void print_quote_case(char *commands)
{
    for (size_t i = 1; i < strlen(commands) - 1; i++) {
        my_putchar(commands[i]);
    }
}

void print_with_backslash(char **commands, int i)
{
    for (size_t j = 1; j < strlen(commands[i]) - 1; j++) {
        handle_backslash(commands, i, &j);
        if (commands[i][j] != '\0' && j < strlen(commands[i]) - 1)
            my_putchar(commands[i][j]);
    }
}

void echo_opt_maj_e(char **commands)
{
    for (int i = 2; commands[i] != NULL; i++) {
        if (commands[i][0] != '\"' && commands[i][0] != '\'') {
            print_simple_case(commands[i]);
        } else {
            print_quote_case(commands[i]);
        }
        if (commands[i + 1] != NULL)
            my_putchar(' ');
    }
    my_putchar('\n');
}

void echo_opt_e(char **commands)
{
    for (int i = 2; commands[i] != NULL; i++) {
        if (commands[i][0] != '\"' && commands[i][0] != '\'') {
            print_simple_case(commands[i]);
        } else {
            print_with_backslash(commands, i);
        }
        if (commands[i + 1] != NULL)
            my_putchar(' ');
    }
    my_putchar('\n');
}