/*
** EPITECH PROJECT, 2022
** verif_echo_arg
** File description:
** FreeKOSOVO
*/

#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "my.h"
#include "echo.h"

int is_arg_hyphen_n(char *commands)
{
    return (strcmp(commands, "-n") == 0 || strcmp(commands, "\'-n\'") == 0 ||
    strcmp(commands, "\"-n\"") == 0) ? true : false;
}

int verif_option_echo(char *commands)
{
    return (strcmp(commands, "-e") == 0 || strcmp(commands, "\"-e\"") == 0 ||
    strcmp(commands, "-E") == 0 || strcmp(commands, "\"-E\"") == 0 ||
    strcmp(commands, "\'-e\'") == 0 ||
    strcmp(commands, "\'-E\'") == 0) ? true : false;
}

int verif_solo_quote(char **commands)
{
    for (int i = 1; commands[i] != NULL; i++) {
        if (commands[i][0] == '\'' && (strlen(commands[i]) == 1 ||
        commands[i][strlen(commands[i]) - 1] != '\'')) {
            my_putstr("Unmatched '");
            my_putchar('\'');
            my_putstr("'.\n");
            return -1;
        }
        if (commands[i][0] == '\"' && (strlen(commands[i]) == 1 ||
        commands[i][strlen(commands[i]) - 1] != '\"')) {
            my_putstr("Unmatched '");
            my_putchar('\"');
            my_putstr("'.\n");
            return -1;
        }
    }
    return 0;
}
