/*
** EPITECH PROJECT, 2022
** if_builtins_2
** File description:
** FreeKOSOVO
*/

#include "my.h"
#include "builtins.h"
#include "mysh.h"

int if_echo(char **commands, shell_t *save)
{
    if (is_writted_echo(commands) == 1) {
        save->return_value =
        my_echo(commands, save) == -1 ? 1 : 0;
        return (0);
    }
    return (1);
}

int if_history(char **commands, shell_t *save)
{
    if (my_strcmp(commands[0], "history") == 0) {
        save->return_value =
        my_history(commands, save) == -1 ? 1 : save->return_value;
        return 0;
    }
    return 1;
}
