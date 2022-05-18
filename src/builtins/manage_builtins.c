/*
** EPITECH PROJECT, 2022
** manage_builtins
** File description:
** FreeKOSOVO
*/

#include "builtins.h"
#include "my.h"
#include "builtins_array.h"

int manage_builtins(char **commands, shell_t *save)
{
    for (int i = 0; i != 6; i++) {
        if ((*BUILTINS_ARRAY[i]) (commands, save) == 0)
            return (0);
    }
    return (-1);
}
