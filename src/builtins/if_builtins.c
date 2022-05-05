/*
** EPITECH PROJECT, 2022
** if_builtins
** File description:
** FreeKOSOVO
*/

#include <stddef.h>
#include "my.h"
#include "builtins.h"
#include "mysh.h"

int if_exit(char **commands, shell_t *save)
{
    if (my_strcmp(commands[0], "exit") == 0) {
        save->return_value =
        my_exit(commands, save) == -1 ? 1 : save->return_value;
        return (0);
    }
    return (1);
}

int if_env(char **commands, shell_t *save)
{
    if (my_strcmp(commands[0], "env") == 0) {
        if (my_len_array(commands) == 1) {
            my_show_word_array(save->env);
        } else {
            my_printf("env: '%s': No such file or directory\n", commands[1]);
            save->return_value = 127;
        }
        return (0);
    }
    return (1);
}

int if_unsetenv(char **commands, shell_t *save)
{
    if (my_strcmp(commands[0], "unsetenv") == 0) {
        save->return_value =
        my_unsetenv(save->env, commands) == -1 ? 1 : save->return_value;
        return (0);
    }
    return (1);
}

int if_setenv(char **commands, shell_t *save)
{
    if (my_strcmp(commands[0], "setenv") == 0) {
        save->env = my_setenv(save->env, commands, &save->return_value);
        return (0);
    }
    return (1);
}

int if_cd(char **commands, shell_t *save)
{
    if (my_strcmp(commands[0], "cd") == 0) {
        save->return_value =
        builtin_cd(commands, &save->env) == -1 ? 1 : save->return_value;
        return (0);
    }
    return (1);
}
