/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** commands_array
*/

#ifndef COMMANDS_ARRAY_H_
    #define COMMANDS_ARRAY_H_

    #include "mysh.h"

static int (*COMMANDS_ARRAY[]) (char **, shell_t *) = {
    manage_alias,
    manage_builtins,
    check_access,
    check_path
};

#endif/* !COMMANDS_ARRAY_H_ */
