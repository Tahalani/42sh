/*
** EPITECH PROJECT, 2022
** manage_builtins
** File description:
** FreeKOSOVO
*/

#include "builtins.h"
#include "my.h"
#include "builtins_array.h"

int if_echo(char **commands, shell_t *save)
{
    if (my_strcmp(commands[0], "echo") == 0) {
        save->return_value =
        my_echo(commands, save) == -1 ? 1 : save->return_value;
        return (0);
    }
    return (1);
}

int manage_builtins(char **commands, shell_t *save)
{
    for (int i = 0; i != nb_builtins; i++) {
        if ((*BUILTINS_ARRAY[i]) (commands, save) == 0)
            return (0);
    }
    return (-1);
}
