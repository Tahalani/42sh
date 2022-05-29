/*
** EPITECH PROJECT, 2022
** check_path
** File description:
** check path file
*/

#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

static int loop_path(path_t *path, int i, pid_t pid, int *value)
{
    if (access(path->bin[i], X_OK | F_OK) == 0) {
        pid = fork();
        if (pid != 0) {
            wait(&path->status);
            check_status(path->status, value);
        } else
            error_execve(path->bin[i], path->commands, path->env, value);
        return (0);
    }
    return (-1);
}

int check_path(char **commands, shell_t *save)
{
    pid_t pid = 0;
    path_t path = {.bin = my_getenv(save->env, "PATH="),
        .str = my_strcat("/", commands[0]), .commands = commands,
        .env = save->env};

    if (path.bin == NULL) {
        my_puterr("TERM environment variable not set.\n");
        my_freef("%s", path.str);
        return -1;
    }
    my_strcat_in_array(path.bin, path.str);
    free(path.str);
    for (int i = 0; path.bin[i] != NULL; i++) {
        if (loop_path(&path, i, pid, &save->return_value) == 0) {
            my_free_array(path.bin);
            return (0);
        }
    }
    my_free_array(path.bin);
    return (-1);
}
