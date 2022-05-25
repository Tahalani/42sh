/*
** EPITECH PROJECT, 2022
** manage_alias
** File description:
** FreeKOSOVO
*/

#include "alias_array.h"

int manage_alias(char **commands, shell_t *save)
{
    for (int i = 0; i != 1; i++) {
        if ((*ALIAS_ARRAY[i]) (commands, save) == 0)
            return (0);
    }
    return (-1);
}
