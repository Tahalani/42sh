/*
** EPITECH PROJECT, 2022
** commands_array
** File description:
** FreeKOSOVO
*/

#ifndef commands_array_H_
    #define commands_array_H_

    #include "mysh.h"

static int (*COMMANDS_ARRAY[]) (char **, shell_t *) = {
    manage_variables,
    manage_builtins,
    check_access,
    check_path
};

#endif/* !commands_array_H_ */
