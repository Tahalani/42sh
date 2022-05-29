/*
** EPITECH PROJECT, 2022
** error_setenv2
** File description:
** error setenv two
*/

#include "my.h"

int parentheses_2(char **commands, int *check, int i)
{
    if (commands[1][i] == ')' && *check == 0) {
        my_puterr("Too many )'s.\n");
        return (-1);
    }
    if (commands[1][i] == '(' && *check == 1) {
        my_puterr("Too many ('s.\n");
        return (-1);
    }
    if (commands[1][i] == ')' && *check == 1) {
        my_puterr("Badly placed ()'s.\n");
        return (-1);
    }
    if (commands[1][i] == '(')
        *check = 1;
    return (0);
}

int check_second_bracket(int check)
{
    if (check == 1) {
        my_puterr("Too many ('s.\n");
        return (-1);
    } else
        return (0);
}
