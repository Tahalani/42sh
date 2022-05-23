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

int is_arg_hyphen_n(char *commands)
{
    return (strcmp(commands, "-n") == 0 ||
    strcmp(commands, "\"-n\"") == 0) ? 1 : 0;
}

int verif_option_echo(char *commands)
{
    return (strcmp(commands, "-e") == 0 || strcmp(commands, "\"-e\"") == 0 ||
    strcmp(commands, "-E") == 0 || strcmp(commands, "\"-E\"") == 0) ? 1 : 0;
}