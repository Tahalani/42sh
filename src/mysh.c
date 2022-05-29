/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** my_42sh file
*/

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

#include "variables.h"
#include "mysh.h"
#include "alias.h"
#include "my.h"

char **env_prompt;

void initialise_value(shell_t *save)
{
    env_prompt = save->env;
    save->str = NULL;
    save->status = 0;
}

void close_program(shell_t *save)
{
    remove(VARIABLES_TMP_FILE);
    free(save->str);
    remove(ALIAS_TMP_FILE);
}

int myshell(shell_t *save)
{
    size_t size;
    char *shrc_path = my_strcat(my_get_line_env(save->env, "HOME="),
    RC_FILE_NAME);
    initialise_value(save);

    if (shrc_path == NULL)
        return -1;
    signal(SIGINT, ctrl_c);
    copy_file_in_directory(RC_FILE_NAME, shrc_path);
    my_prompt(save->env);
    while (save->status == 0 && getline(&save->str, &size, stdin) > 0) {
        manage_separator(save);
        env_prompt = save->env;
        if (save->status == 1)
            break;
        my_prompt(save->env);
    }
    close_program(save);
    return (0);
}
