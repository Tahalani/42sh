/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** manage_builtins
*/

#include "builtins.h"
#include "my.h"
#include "builtins_array.h"

int manage_builtins(char **commands, shell_t *save)
{
    for (int i = 0; i != NB_BUILTINS; i++) {
        if ((*BUILTINS_ARRAY[i])(commands, save) == 0)
            return (0);
    }
    return (-1);
}
