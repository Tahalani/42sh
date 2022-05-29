/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** builtins_array
*/

#ifndef BUILTINS_ARRAY_H_
    #define BUILTINS_ARRAY_H_

    #include "mysh.h"
    #define NB_BUILTINS 7

static const int nb_builtins = 7;

int if_exit(char **commands, shell_t *);
int if_env(char **commands, shell_t *);
int if_unsetenv(char **commands, shell_t *);
int if_setenv(char **commands, shell_t *);
int if_cd(char **commands, shell_t *);
int if_history(char **commands, shell_t *);
int if_echo(char **commands, shell_t *);

static int (*BUILTINS_ARRAY[]) (char **, shell_t *) = {
    if_exit,
    if_env,
    if_unsetenv,
    if_setenv,
    if_echo,
    if_cd,
    if_history
};

#endif/* !BUILTINS_ARRAY_H_ */
