/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** builtins
*/

#ifndef BUILTINS_H_
    #define BUILTINS_H_

    #include "setenv.h"
    #include "cd.h"
    #include "mysh.h"
    #include "history.h"

int manage_builtins(char **commands, shell_t *);
int my_exit(char **commands, shell_t *);
int my_echo(char **commands, shell_t *);
int my_history(char **commands, shell_t *);

#endif/* !BUILTINS_H_ */
