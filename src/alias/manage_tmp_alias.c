/*
** EPITECH PROJECT, 2022
** manage_tmp_alias
** File description:
** FreeKOSOVO
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "alias.h"
#include "my.h"

int create_alias(char **commands)
{
    if (my_write_in_file("/tmp/.42shrc", "alias ") == -1)
        return -1;
    if (my_write_in_file("/tmp/.42shrc", commands[1]) == -1)
        return -1;
    if (my_write_in_file("/tmp/.42shrc", "=") == -1)
        return -1;
    for (int i = 2; commands[i] != NULL; i++) {
        if (my_write_in_file("/tmp/.42shrc", commands[i]) == -1)
            return -1;
        if (commands[i + 1] != NULL)
            my_write_in_file("/tmp/.42shrc", " ");
    }
    if (my_write_in_file("/tmp/.42shrc", "\n") == -1)
        return -1;
    return 0;
}

int manage_tmp_alias(char **commands)
{
    int cpt_arg = 0;

    for (; commands[cpt_arg] != NULL; cpt_arg++);
    if (cpt_arg == 1) {
        printf("ALIAS avec getline ?");
        return 0;
    }
    if (cpt_arg == 2)
        return 0;
    if (search_alias_already_set(commands) == 1)
        return 0;
    else
        return create_alias(commands);
}
