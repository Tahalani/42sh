/*
** EPITECH PROJECT, 2022
** print_echo_if_arg
** File description:
** FreeKOSOVO
*/

#include <stddef.h>
#include <string.h>

#include "my.h"
#include "echo.h"

void print_simple_quote(char **commands, int i)
{
    size_t size = strlen(commands[i]);

    for (size_t j = 1; j < size; j++) {
        if (commands[i][j] == '\'' && j == strlen(commands[i]) - 1)
            break;
        handle_backslash(commands, i, &j);
        if (commands[i][j] != '\0' && !(commands[i][j] == '\''
        && j == strlen(commands[i]) - 1))
            my_putchar(commands[i][j]);
    }
}

void print_quote_case(char *commands, shell_t *save)
{
    size_t size = strlen(commands);

    for (size_t i = 1; i < size; i++) {
        if (i == strlen(commands) - 1 && (commands[i] == '\"' ||
        commands[i] == '\''))
            break;
        if (commands[i] == '$' && commands[i + 1] == '?') {
            my_put_nbr(save->return_value);
            i++;
            continue;
        }
        my_putchar(commands[i]);
    }
}

void print_with_backslash(char **commands, int i, shell_t *save)
{
    if (commands[i][0] == '\'') {
        print_simple_quote(commands, i);
        return;
    }
    for (size_t j = 1; j < strlen(commands[i]); j++) {
        if (j == strlen(commands[i]) - 1 && (commands[i][j] == '\"' ||
        commands[i][j] == '\''))
            break;
        handle_backslash(commands, i, &j);
        if (commands[i][j] == '$' && commands[i][j + 1] == '?') {
            my_put_nbr(save->return_value);
            j++;
            continue;
        }
        if (commands[i][j] != '\0' && !(commands[i][j] == '\"'
        && j == strlen(commands[i]) - 1))
            my_putchar(commands[i][j]);
    }
}

void echo_opt_maj_e(char **commands, shell_t *save)
{
    for (int i = 2; commands[i] != NULL; i++) {
        if (commands[i][0] != '\"' && commands[i][0] != '\'') {
            print_simple_case(commands[i], save);
        } else {
            print_quote_case(commands[i], save);
        }
        if (commands[i + 1] != NULL)
            my_putchar(' ');
    }
    my_putchar('\n');
}

void echo_opt_e(char **commands, shell_t *save)
{
    for (int i = 2; commands[i] != NULL; i++) {
        if (commands[i][0] != '\"' && commands[i][0] != '\'') {
            print_simple_case(commands[i], save);
        } else {
            print_with_backslash(commands, i, save);
        }
        if (commands[i + 1] != NULL)
            my_putchar(' ');
    }
    my_putchar('\n');
}
