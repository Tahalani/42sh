/*
** EPITECH PROJECT, 2022
** manage_alias
** File description:
** FreeKOSOVO
*/

#include <string.h>

#include "alias.h"

int manage_alias(char **commands, shell_t *save)
{
    if (strcmp(commands[0], "alias") == 0)
        return manage_tmp_alias(commands, save);
    return search_in_shrc(commands, save);
}
