/*
** EPITECH PROJECT, 2022
** verif_echo_arg
** File description:
** verif echo file
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

void compare_wich_quote(char **commands, int i, int *cpt_double_quote,
int *cpt_quote)
{
    for (int j = 0; commands[i][j] != '\0'; j++) {
        if (commands[i][j] == '\"')
            *cpt_double_quote += 1;
        if (commands[i][j] == '\'')
            *cpt_quote += 1;
    }
}

int verif_solo_quote(char **commands)
{
    int cpt_quote = 0;
    int cpt_double_quote = 0;

    for (int i = 1; commands[i] != NULL; i++)
        compare_wich_quote(commands, i, &cpt_double_quote, &cpt_quote);
    for (int i = 1; commands[i] != NULL; i++) {
        if (commands[i][0] == '\'' && cpt_quote % 2 == 1
        && (strlen(commands[i]) == 1 ||
        commands[i][strlen(commands[i]) - 1] != '\'')) {
            my_putstr("Unmatched \'\'\'.\n");
            return -1;
        }
        if (commands[i][0] == '\"' && cpt_double_quote % 2 == 1
        && (strlen(commands[i]) == 1 ||
        commands[i][strlen(commands[i]) - 1] != '\"')) {
            my_putstr("Unmatched \'\"\'.\n");
            return -1;
        }
    }
    return 0;
}

int is_writted_echo(char **commands)
{
    char word_double_quote[5] = {'e'};
    char word_simple_quote[5] = {'e'};

    if (my_strcmp(commands[0], "echo") == 0)
        return true;
    if (parsing_echo_word(commands, word_double_quote, '\'') == true ||
    parsing_echo_word(commands, word_simple_quote, '\"') == true)
        return true;
    return false;
}
