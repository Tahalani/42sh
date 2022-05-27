/*
** EPITECH PROJECT, 2022
** commands_array
** File description:
** FreeKOSOVO
*/

#ifndef COMMANDS_ARRAY_H_
    #define COMMANDS_ARRAY_H_

    #include "mysh.h"

static int (*COMMANDS_ARRAY[]) (char **, shell_t *) = {
    manage_builtins,
    check_access,
    check_path
};

#endif/* !COMMANDS_ARRAY_H_ */
