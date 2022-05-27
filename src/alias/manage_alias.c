/*
** EPITECH PROJECT, 2022
** manage_alias
** File description:
** FreeKOSOVO
*/

#include <string.h>

#include "alias.h"

int delete_alias(char **commands);
int verif_unalias_arg(char **commands);

int manage_alias(char **commands, shell_t *save)
{
    int ret_val = -1;

    if (strcmp(commands[0], "alias") == 0) {
        ret_val = manage_tmp_alias(commands);
        if (ret_val == 0)
            save->return_value = ret_val;
        return ret_val;
    }
    if (strcmp(commands[0], "unalias") == 0) {
        ret_val = verif_unalias_arg(commands);
        save->return_value = ret_val;
        return 0;
    }
    ret_val = search_in_shrc(commands, save);
    if (ret_val == 0)
        save->return_value = ret_val;
    return ret_val;
}
