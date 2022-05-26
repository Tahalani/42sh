/*
** EPITECH PROJECT, 2022
** if_builtins_2
** File description:
** FreeKOSOVO
*/

#include <stddef.h>

#include "my.h"
#include "builtins.h"

int if_history(char **commands, shell_t *save)
{
    if (my_strcmp(commands[0], "history") == 0) {
        save->return_value =
        my_history(commands, save) == -1 ? 1 : save->return_value;
        return 0;
    }
    return 1;
}
