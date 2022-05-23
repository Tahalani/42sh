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

void handle_backslash(char **commands, int i, int *j);
int verif_option_echo(char *commands);
int is_arg_hyphen_n(char *commands);

int manage_echo_option(char **commands)
{
    my_putstr("je suis dans le fonction option");
}

void print_string(char **commands, int i)
{
    if (commands[i][0] != '"') {
        for (int j = 0; j < my_strlen(commands[i]); j++) {
            if (commands[i][j] == '\\')
                continue;
            else
                my_putchar(commands[i][j]);
        }
    } else {
        for (int j = 1; j < strlen(commands[i]) - 1; j++) {
            handle_backslash(commands, i, &j);
            if (commands[i][j] != '\0' && j < strlen(commands[i]) - 1)
                my_putchar(commands[i][j]);
        }
    }
}

void print_arg_in_boucle(char **commands, shell_t *save, int i)
{
    if (strcmp(commands[i], "$?") == 0 || strcmp(commands[i], "\"$?\"") == 0)
        my_put_nbr(save->return_value);
    else
        print_string(commands, i);
    if (commands[i + 1] != NULL)
        my_putchar(' ');
}

int my_echo(char **commands, shell_t *save)
{
    int i = 1;

    if (commands[1] == NULL) {
        my_putstr("\n");
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