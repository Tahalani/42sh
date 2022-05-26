/*
** EPITECH PROJECT, 2022
** manage_alias
** File description:
** FreeKOSOVO
*/

#include "alias.h"

int manage_alias(char **commands, shell_t *save)
{
    return search_in_shrc(commands, save);
}
