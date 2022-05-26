/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

#include "mysh.h"
#include "my.h"

char **env_prompt;

int myshell(shell_t *save)
{
    env_prompt = save->env;
    save->str = NULL;
    size_t size;
    save->status = 0;

    signal(SIGINT, ctrl_c);
    copy_file_in_directory(".42shrc",
    my_strcat(my_get_line_env(save->env, "HOME="), "/.42shrc"));
    my_prompt(save->env);
    while (save->status == 0 && getline(&save->str, &size, stdin) > 0) {
        manage_separator(save);
        env_prompt = save->env;
        if (save->status == 1)
            break;
        my_prompt(save->env);
    }
    free(save->str);
    return (0);
}
