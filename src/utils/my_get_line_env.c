/*
** EPITECH PROJECT, 2022
** my_get_line_env
** File description:
** FreeKOSOVO
*/

#include "my.h"
#include <string.h>

char *my_get_line_env(char **env, char *str)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], str, my_strlen(str)) == 0)
            return (env[i] + my_strlen(str));
    }
    return (NULL);
}
