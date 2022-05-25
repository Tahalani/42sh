/*
** EPITECH PROJECT, 2022
** alias_array
** File description:
** FreeKOSOVO
*/

#ifndef ALIAS_ARRAY_H_
    #define ALIAS_ARRAY_H_

    #include "mysh.h"

int if_alias_ll(char **commands, shell_t *);

static int (*ALIAS_ARRAY[]) (char **, shell_t *) = {
    if_alias_ll
};

#endif/* !ALIAS_ARRAY_H_ */
