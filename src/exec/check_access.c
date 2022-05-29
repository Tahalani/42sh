/*
** EPITECH PROJECT, 2022
** check_access
** File description:
** access check
*/

#include <unistd.h>
#include <sys/wait.h>
#include "mysh.h"

static int execute_commands(char **commands, char **env, int *return_value)
{
    pid_t pid;
    int status;

    if (access(commands[0], X_OK) == 0) {
        pid = fork();
        if (pid != 0) {
            wait(&status);
            check_status(status, return_value);
        } else if (pid == 0)
            error_execve(commands[0], commands, env, return_value);
        return (0);
    } else
        put_2_elements(commands[0], return_value);
    return (0);
}

int check_access(char **commands, shell_t *save)
{
    if (access(commands[0], F_OK) == 0) {
        execute_commands(commands, save->env, &save->return_value);
        return (0);
    }
    return (-1);
}
