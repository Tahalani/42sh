/*
** EPITECH PROJECT, 2022
** my_unsetenv
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

static void delete_line(char **array, int i)
{
    free(array[i]);
    for (int j = i; array[j] != NULL; j++) {
        array[j] = array[j + 1];
    }
}

static int my_unsetenv_2(char **del, char **env, int i)
{
    int j = 0;
    int len = 0;

    for (; env[j] != NULL; j++) {
        len = 0;
        for (; env[j][len] != '='; len++);
        if (my_strncmp(env[j], del[i], len) == 0)
            delete_line(env, j);
    }
    if (j == my_len_array(env))
        return (-1);
    return (0);
}

int my_unsetenv(char **env, char **commands)
{
    if (commands[1] == NULL) {
        my_puterr("unsetenv: Too few arguments.\n");
        return (-1);
    }
    for (int i = 0; commands[i] != NULL; i++) {
        if (my_unsetenv_2(commands, env, i) == 0)
            return (0);
    }
    return (-2);
}
