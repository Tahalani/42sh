/*
** EPITECH PROJECT, 2022
** my_setenv
** File description:
** FreeKOSOVO
*/

#include <string.h>
#include <stdlib.h>
#include "setenv.h"
#include "my.h"

static char **add_str(int len_tab, char **env, char *str, char **commands)
{
    char **result = malloc(sizeof(char *) * (len_tab + 2));

    if (result == NULL)
        return (NULL);
    for (int i = 0; i != len_tab; i++) {
        result[i] = my_strdup(env[i]);
        if (result[i] == NULL)
            return (NULL);
    }
    result[len_tab] = my_strcat(commands[1], str);
    if (result[len_tab] == NULL) {
        free(result);
        return (NULL);
    }
    result[len_tab + 1] = NULL;
    return (result);
}

static void free_elements(char *str, char *new, char **old_env)
{
    free(new);
    free(str);
    my_free_array(old_env);
}

char **my_setenv(char **env, char **commands, int *return_value)
{
    char *str = NULL;
    char *new = NULL;
    char **result = NULL;
    int len_tab = my_len_array(env);

    if (error_setenv(commands, &env, return_value) == -1)
        return (env);
    new = my_strdup("=");
    if (new == NULL)
        return (env);
    if (error_setenv(commands, &env, return_value) == 1)
        str = my_strcat(new, commands[2]);
    else
        str = my_strdup("=");
    if (str == NULL)
        return (env);
    result = add_str(len_tab, env, str, commands);
    free_elements(str, new, env);
    return (result);
}
