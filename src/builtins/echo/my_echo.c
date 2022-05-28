/*
** EPITECH PROJECT, 2022
** my_echo
** File description:
** FreeKOSOVO
*/

#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#include "my.h"
#include "builtins.h"
#include "echo.h"

void print_simple_case(char *commands, shell_t *save)
{
    size_t size = strlen(commands);

    for (size_t i = 0; i < size; i++) {
        if (commands[i] == '\\' || (commands[i] == '\"'
        && i == strlen(commands) - 1))
            continue;
        if (commands[i] == '$' && commands[i + 1] == '?') {
            my_put_nbr(save->return_value);
            i++;
            continue;
        }
        my_putchar(commands[i]);
    }
}

void manage_echo_option(char **commands, shell_t *save)
{
    if (commands[2] == NULL) {
        my_putchar('\n');
        return;
    }
    if (strcmp(commands[1], "-E") == 0 || strcmp(commands[1], "\"-E\"") == 0
    || strcmp(commands[1], "\'-E\'") == 0)
        echo_opt_maj_e(commands, save);
    if (strcmp(commands[1], "-e") == 0 || strcmp(commands[1], "\"-e\"") == 0
    || strcmp(commands[1], "\'-e\'") == 0)
        echo_opt_e(commands, save);
}

void print_arg_in_boucle(char **commands, shell_t *save, int i)
{
    if (strcmp(commands[i], "$") == 0 || strcmp(commands[i], "\"$\"") == 0)
        my_put_nbr(save->return_value);
    else {
        if (commands[i][0] != '\"' && commands[i][0] != '\'') {
            print_simple_case(commands[i], save);
        } else {
            print_with_backslash(commands, i, save);
        }
    }
    if (commands[i + 1] != NULL)
        my_putchar(' ');
}

int parsing_echo_word(char **commands, char *word, char c)
{
    int cpt = 0;
    int cpt_quote = 0;

    if (my_strcmp(commands[0], "echo") == 0)
        return true;
    for (int i = 0; commands[0][i] != 0 && cpt != 5; i++) {
        if (commands[0][i] != c) {
            word[cpt] = commands[0][i];
            cpt += 1;
        } else
            cpt_quote++;
    }
    if (cpt_quote % 2 != 0)
        return false;
    if (my_strcmp(word, "echo") == 0)
        return true;
    return false;
}

int my_echo(char **commands, shell_t *save)
{
    int i = 1;

    if (verif_solo_quote(commands) == -1)
        return -1;
    if (commands[1] == NULL) {
        my_putchar('\n');
    } else if (verif_option_echo(commands[1]) == 1) {
        manage_echo_option(commands, save);
    } else {
        if (is_arg_hyphen_n(commands[1]))
            i++;
        for (; commands[i] != NULL; i++)
            print_arg_in_boucle(commands, save, i);
        if (!is_arg_hyphen_n(commands[1]))
            my_putchar('\n');
    }
    return (0);
}
