/*
** EPITECH PROJECT, 2022
** error_execve
** File description:
** error handling execve
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

void put_2_elements(char *str, int *value)
{
    my_puterr(str);
    my_puterr(": Permission denied.\n");
    *value = 1;
}

void free_elements(char **commands, char **env)
{
    my_free_array(commands);
    my_free_array(env);
}

void error_execve(char *str, char **commands, char **env, int *value)
{
    struct stat buff;

    if (stat(str, &buff) == -1 || gettype(buff) != 'd') {
        if (execve(str, commands, env) == -1) {
            my_puterr(str);
            my_puterr(": Exec format error. Wrong Architecture.\n");
            free_elements(commands, env);
            exit(1);
        }
    } else {
        put_2_elements(str, value);
        free_elements(commands, env);
        exit(1);
    }
}
