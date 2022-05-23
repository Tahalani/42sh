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

void manage_echo_option(char **commands)
{
    if (commands[2] == NULL) {
        my_putchar('\n');
        return;
    }
    if (strcmp(commands[1], "-E") == 0 || strcmp(commands[1], "\"-E\"") == 0
    || strcmp(commands[1], "\'-E\'") == 0)
        echo_opt_maj_e(commands);
    if (strcmp(commands[1], "-e") == 0 || strcmp(commands[1], "\"-e\"") == 0
    || strcmp(commands[1], "\'-e\'") == 0)
        echo_opt_e(commands);
}

void print_arg_in_boucle(char **commands, shell_t *save, int i)
{
    if (strcmp(commands[i], "$?") == 0 || strcmp(commands[i], "\"$?\"") == 0)
        my_put_nbr(save->return_value);
    else {
        if (commands[i][0] != '\"' && commands[i][0] != '\'') {
            print_simple_case(commands[i]);
        } else {
            print_with_backslash(commands, i);
        }
    }
    if (commands[i + 1] != NULL)
        my_putchar(' ');
}

int my_echo(char **commands, shell_t *save)
{
    int i = 1;

    if (verif_solo_quote(commands) == -1) {
        save->return_value = 1;
        return -1;
    }
    if (commands[1] == NULL) {
        my_putchar('\n');
    } else if (verif_option_echo(commands[1]) == 1) {
        manage_echo_option(commands);
    } else {
        if (is_arg_hyphen_n(commands[1]))
            i++;
        for (; commands[i] != NULL; i++)
            print_arg_in_boucle(commands, save, i);
        if (!is_arg_hyphen_n(commands[1]))
            my_putchar('\n');
    }
    save->return_value = 0;
    return (0);
}